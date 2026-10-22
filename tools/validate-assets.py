#!/usr/bin/env python3
"""Verify extraction bytes, parsed geometry, generated images, and movie timing."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import wave
from concurrent.futures import ThreadPoolExecutor
from PIL import Image
from lib.superkarts_formats import mesh,road,route,placements,collision,drive,paths
ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'public/assets'

def sha(data):return hashlib.sha256(data).hexdigest()
def check(condition,message):
    if not condition:raise AssertionError(message)
def probe(path):
    result=subprocess.run(['ffprobe','-v','warning','-count_frames','-show_streams','-show_format','-of','json',str(path)],capture_output=True,text=True,check=True)
    return json.loads(result.stdout),result.stderr.strip()
def main():
    m=json.loads((OUT/'manifest.json').read_text());source=Path(m['sourceInstallation'])/'data'
    files={f.name.lower():f for f in source.iterdir() if f.is_file()}
    results={'format':'superkarts-asset-validation-v1','checks':{},'limitations':[
        'Geometry/data validation is structural; it does not establish complete runtime or visual parity.',
        'Movie comparison verifies decoded frame counts, cadence, dimensions, audio format; codec output is lossy.',
        'Indexed RC sprite palette and several raw resource meanings remain unresolved.']}
    records=0
    for stem,arc in m['archives'].items():
        check(sha(files[stem+'.ind'].read_bytes())==arc['indexSHA256'],f'{stem} source index changed')
        check(sha(files[stem+'.img'].read_bytes())==arc['imageSHA256'],f'{stem} source image changed')
        blob=files[stem+'.img'].read_bytes()
        for e in arc['entries']:
            data=(ROOT/'raw/extracted'/stem/e['filename']).read_bytes()
            check(sha(data)==e['sha256'],f'extraction digest mismatch {e["filename"]}')
            check(data==blob[e['offset']:e['offset']+e['length']],f'extraction byte mismatch {e["filename"]}')
            records+=1
    results['checks']['archiveRecordsByteExact']=records
    versions={};geometry=0
    for file in (ROOT/'raw/extracted/rcs').glob('*.d3d'):
        data=mesh(file.read_bytes());versions[data['sourceVersion']]=versions.get(data['sourceVersion'],0)+1
        generated=json.loads((OUT/'meshes'/(file.stem+'.json')).read_text())
        for key in data:check(data[key]==generated[key],f'D3D conversion mismatch {file.name}:{key}')
        geometry+=1
    results['checks']['meshesByteParsed']=geometry;results['checks']['meshVersions']=versions
    for track in m['tracks']:
        stem='etappe'+str(track['id']);t=json.loads((OUT/track['file']).read_text())
        for suffix,parser,key in [('rmp',road,None),('pmp',route,'route'),('omp',placements,'placements'),('cmp',collision,'collision'),('dmp',drive,'drive'),('pth',paths,'paths')]:
            parsed=parser(files[stem+'.'+suffix].read_bytes())
            if key:check(t[key]==parsed,f'{stem} {key} mismatch')
            else:
                for k in parsed:check(t[k]==parsed[k],f'{stem} {k} mismatch')
        check(len(t['groups'])==4*t['sectorCount'],'RMP sector count mismatch')
        for sector in t['route']:
            check(all(i<len(t['collision']) for i in sector['collisionIndices']),'collision ref')
            check(all(i<len(t['drive']) for i in sector['driveIndices']+sector['driveLeftIndices']),'drive ref')
    results['checks']['tracksCompletelyParsed']=len(m['tracks'])
    images=0
    for section in ['images','menu','fonts','indexedSprites']:
        for e in m[section].values():
            with Image.open(OUT/e['file']) as im:
                im.load();check((im.width,im.height)==(e['width'],e['height']),f'image dimensions {e["file"]}')
            images+=1
    results['checks']['imagesDecoded']=images
    audio=0;formats={}
    for name,e in m['audio'].items():
        f=OUT/e['file']
        check(sha(f.read_bytes())==e['sha256'],f'audio output bytes changed: {name}')
        if e.get('source'):
            check(Path(e['source']).name==e['sourceFilename'],f'original audio filename case changed: {name}')
            check(sha(Path(e['source']).read_bytes())==e['sha256'],f'original loose audio changed: {name}')
        if f.suffix.lower()!='.wav':continue
        with wave.open(str(f)) as w:
            check(w.getnframes()>0,f'empty WAV {f.name}')
            key=f'{w.getnchannels()}ch-{w.getsampwidth()*8}bit-{w.getframerate()}Hz'
            formats[key]=formats.get(key,0)+1;audio+=1
    results['checks']['waveFilesDecoded']=audio;results['checks']['waveFormats']=formats
    audio_sources=json.loads((OUT/m['menuAudioSources']).read_text())
    resolved=0
    for reference in audio_sources['menuReferences']:
        name=reference['source']
        if reference['file']:
            check(name in m['audio'] and m['audio'][name]['file']==reference['file'],
                  f'menu sound reference mismatch: {reference}')
            check((OUT/reference['file']).is_file(),f'menu sound missing: {name}')
            resolved+=1
        else:
            check(name not in m['audio'],f'menu sound incorrectly reported absent: {name}')
    results['checks']['looseAudioByteExact']=len(audio_sources['looseFiles'])
    results['checks']['menuAudioReferencesResolved']=resolved
    results['missingOriginalMenuAudio']=audio_sources['missingSourceReferences']
    for entry in m.get('physics',{}).values():
        check(sha((OUT/entry['file']).read_bytes())==entry['sha256'],'physics source bytes changed')
    results['checks']['physicsTablesByteExact']=len(m.get('physics',{}))
    for entry in m.get('racerTables',{}).values():
        data=(OUT/entry['file']).read_bytes()
        check(sha(data)==entry['sha256'],'racer table source bytes changed')
        check(data==Path(entry['source']).read_bytes(),'racer table differs from original')
        check(len(data)==20*0x7c,'racer table size differs from native loader')
    results['checks']['racerTablesByteExact']=len(m.get('racerTables',{}))
    def video(entry):
        name,e=entry;s,sw=probe(Path(m['sourceCD'])/e['original']);d,dw=probe(OUT/e['file'])
        sv=next(v for v in s['streams'] if v['codec_type']=='video');dv=next(v for v in d['streams'] if v['codec_type']=='video')
        sa=next(v for v in s['streams'] if v['codec_type']=='audio');da=next(v for v in d['streams'] if v['codec_type']=='audio')
        for k in ['width','height','avg_frame_rate','nb_read_frames','display_aspect_ratio']:
            check(sv[k]==dv[k],f'{name}: source vs converted {k}: {sv[k]} != {dv[k]}')
        for k in ['channels','sample_rate']:check(sa[k]==da[k],f'{name}: audio {k} changed')
        return name,{'frames':int(sv['nb_read_frames']),'frameRate':sv['avg_frame_rate'],
            'width':sv['width'],'height':sv['height'],'audioChannels':sa['channels'],'audioRate':sa['sample_rate'],
            'sourceContainerDuration':s['format']['duration'],'outputContainerDuration':d['format']['duration'],
            'sourceDecodeWarnings':sw,'outputDecodeWarnings':dw}
    with ThreadPoolExecutor(max_workers=3) as pool:results['movies']=dict(pool.map(video,m.get('movies',{}).items()))
    results['status']='passed'
    target=ROOT/'docs/evidence/asset-validation.json';target.write_text(json.dumps(results,indent=2)+'\n')
    print(json.dumps(results['checks'],indent=2));print(f'{len(results["movies"])} movie frame counts/cadences matched; saved {target}')
if __name__=='__main__':main()
