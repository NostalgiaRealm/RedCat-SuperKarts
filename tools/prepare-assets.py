#!/usr/bin/env python3
"""Reproduce portable assets from read-only original installation and ISO files."""
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import hashlib
import io
import json
import math
from pathlib import Path
import shutil
import struct
import subprocess
from PIL import Image
from lib.superkarts_formats import archive_entries, mesh, road, route, placements, collision, drive, paths, ini

ROOT=Path(__file__).resolve().parents[1]
DEFAULT_INSTALL=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts')
DEFAULT_CD=Path('/home/rick/Games/UnpackedISO/RedCat Superkarts/RedCat Superkarts')

def digest(data):return hashlib.sha256(data).hexdigest()
def write_json(path,data):
    path.parent.mkdir(parents=True,exist_ok=True)
    path.write_text(json.dumps(data,separators=(',',':'),ensure_ascii=False,allow_nan=False)+'\n',encoding='utf8')
def image(data,target,key=False,nativeRGB=False):
    original=Image.open(io.BytesIO(data))
    im=original.convert('RGBA')
    source_alpha=im.getchannel('A').histogram()
    partial_alpha=sum(source_alpha[1:255])
    keyed=0
    if key:
        key_color=(255,0,255) if key is True else tuple(key)
        pixels=list(im.get_flattened_data() if hasattr(im,'get_flattened_data') else im.getdata())
        keyed=sum(1 for c in pixels if c[:3]==key_color)
        im.putdata([(r,g,b,0 if (r,g,b)==key_color else 255 if nativeRGB else a) for r,g,b,a in pixels])
    elif nativeRGB:
        im.putalpha(255)
    target.parent.mkdir(parents=True,exist_ok=True);im.save(target)
    return {'width':im.width,'height':im.height,'pixelsMadeTransparent':keyed,
            'colorKeyRGB':list(key_color) if key else None,
            'sourceHasAlpha':'A' in original.getbands(),
            'sourceHasPartialAlpha':partial_alpha>0,
            'sourcePartialAlphaPixels':partial_alpha,
            'sourceTransparentPixels':source_alpha[0],
            'sourceAlphaCounts':{'zero':source_alpha[0],'partial':partial_alpha,'opaque':source_alpha[255]},
            'sourceMode':original.mode,'sourceFormat':original.format,
            'nativeRGB':nativeRGB}
def find(folder,name):
    return next(f for f in folder.iterdir() if f.name.lower()==name.lower())

def prepare_racer_tables(source,out,manifest):
    """Keep the original 20 x 0x7c-byte tables read by native 0x4319f0."""
    tables={}
    for original in sorted(source.iterdir()):
        if original.name.lower() not in [f'cars{i}.dat' for i in range(4)]:continue
        data=original.read_bytes()
        if len(data)!=20*0x7c:raise ValueError(f'Unexpected racer table size: {original}')
        filename='racer-tables/'+original.name.lower()
        (out/'racer-tables').mkdir(exist_ok=True)
        (out/filename).write_bytes(data)
        tables[original.stem.lower()[4:]]={'file':filename,'source':str(original),
            'sha256':digest(data),'records':20,'recordBytes':0x7c,
            'runtimeDifficultyTable':original.stem.lower()!='cars3'}
    if len(tables)!=4:raise ValueError('Expected all four shipped cars*.dat tables')
    manifest['racerTables']=tables
    write_json(out/'racer-tables/manifest.json',tables)

def mesh_bounds(geometry):
    # 004aa040 -> 004aa0c0 scans original, unscaled XYZ for its eight corners.
    coords=geometry['position']
    return {name:value for axis,label in enumerate('XYZ')
            for name,value in [(f'min{label}',min(coords[axis::3])),(f'max{label}',max(coords[axis::3]))]}

def horizontal_radius(bounds):
    # Native 004aa0c0, float32 stores / 24-bit x87 arithmetic (active D3D mode).
    f=lambda value:struct.unpack('<f',struct.pack('<f',value))[0]
    x=f(f(bounds['maxX']-bounds['minX'])*0.5)
    z=f(f(bounds['maxZ']-bounds['minZ'])*0.5)
    # x87's 24-bit precision retains its extended exponent while values remain
    # in registers. This matters for one shipped frame's extreme coordinates.
    def register(value):
        fraction, exponent=math.frexp(value)
        return math.ldexp(round(fraction * (1 << 24)) / (1 << 24), exponent)
    return f(math.sqrt(register(register(x*x)+register(z*z))))

def prepare_loose_audio(installation, cd, out, manifest, configs):
    """Menu voices are loose CD Media/sounds files, separate from the RCS archive."""
    loose=[]
    (out/'audio').mkdir(exist_ok=True)
    for root in [installation, cd]:
        for path in sorted(root.rglob('*')):
            if not path.is_file() or path.suffix.lower() not in ['.wav','.mp3','.mid']:
                continue
            data=path.read_bytes();name=path.name.lower();sha=digest(data)
            existing=manifest['audio'].get(name)
            if existing and existing['sha256']!=sha:
                raise ValueError(f'Conflicting original audio bytes: {name}: {path}')
            filename='audio/'+name
            (out/filename).write_bytes(data)
            spec={'file':filename,'sha256':sha,'source':str(path),'sourceRelative':str(path.relative_to(root)),
                  'sourceRoot':str(root),'sourceFilename':path.name,'bytes':len(data)}
            manifest['audio'][name]=spec
            loose.append({'name':name,**spec})
    references=[]
    for filename,sections in configs.items():
        if not filename.startswith('ini/'):continue
        for section,entries in sections.items():
            for index,value in entries.items():
                name=value.strip().lower()
                if name.endswith('.wav'):
                    references.append({'config':filename,'section':section,'index':index,'source':name,
                        'file':manifest['audio'].get(name,{}).get('file')})
    report={'looseFiles':loose,'menuReferences':references,
            'missingSourceReferences':[ref for ref in references if ref['file'] is None]}
    write_json(out/'audio/menu-sources.json',report)
    manifest['menuAudioSources']='audio/menu-sources.json'
    print(f'Copied {len(loose)} loose audio files; {len(references)} menu references; '
          f'{len(report["missingSourceReferences"])} references absent from supplied originals',flush=True)
    return report

def font_atlas(data, palette, target):
    glyphs={}; x=y=rowheight=0; width=512
    for code in range(256):
        w,h,offset=struct.unpack_from('<HHI',data,code*8)
        if w==65535:continue
        if not (2056<=offset<=len(data) and offset+w*h<=len(data)):
            raise ValueError(f'Invalid glyph {code} range')
        if x+w>width:x=0;y+=rowheight+1;rowheight=0
        glyphs[str(code)]={'x':x,'y':y,'width':w,'height':h,'sourceOffset':offset}
        x+=w+1;rowheight=max(rowheight,h)
    atlas=Image.new('RGBA',(width,y+rowheight),(0,0,0,0))
    for glyph in glyphs.values():
        offset=glyph['sourceOffset'];w=glyph['width'];h=glyph['height']
        pixels=data[offset:offset+w*h]
        rgba=bytes(c for index in pixels for c in (*palette[index*3:index*3+3],0 if index==255 else 255))
        atlas.paste(Image.frombytes('RGBA',(w,h),rgba),(glyph['x'],glyph['y']))
    target.parent.mkdir(parents=True,exist_ok=True);atlas.save(target)
    return {'file':'fonts/'+target.name,'width':atlas.width,'height':atlas.height,'glyphs':glyphs,
            'palette':'e02_pl16.pcx','transparentIndex':255,
            'headerUnknown':list(struct.unpack_from('<4H',data,2048))}

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--installation',type=Path,default=DEFAULT_INSTALL)
    p.add_argument('--cd',type=Path,default=DEFAULT_CD)
    p.add_argument('--skip-media',action='store_true')
    p.add_argument('--media-only',action='store_true')
    p.add_argument('--font-dir',type=Path,default=Path('/home/rick/.local/share/fonts/microsoft'),
                   help='Locally installed original Comic Sans MS TTF files used by native menu')
    a=p.parse_args();source=a.installation/'data' if (a.installation/'data').is_dir() else a.installation
    out=ROOT/'public/assets';raw=ROOT/'raw/extracted';out.mkdir(parents=True,exist_ok=True)
    if a.media_only:
        manifest=json.loads((out/'manifest.json').read_text())
    else:
        previous=json.loads((out/'manifest.json').read_text()) if (out/'manifest.json').exists() else {}
        manifest={'format':'superkarts-assets-v1','sourceInstallation':str(a.installation),'sourceCD':str(a.cd),
                  'archives':{},'images':{},'meshes':{},'audio':{},'menu':{},'tracks':[],'conversionErrors':[]}
        if 'movies' in previous:manifest['movies']=previous['movies']
        texture_aliases=set()
        for stem,named in [('rcs',True),('rc',False)]:
            idx=find(source,stem+'.ind').read_bytes();blob=find(source,stem+'.img').read_bytes()
            entries=archive_entries(idx,len(blob),named)
            target=raw/stem;target.mkdir(parents=True,exist_ok=True)
            print(f'Extracting {stem}: {len(entries)} records',flush=True)
            for e in entries:
                data=blob[e['offset']:e['offset']+e['length']];e['sha256']=digest(data)
                (target/e['filename']).write_bytes(data)
                if not named or not data:continue
                suffix=Path(e['filename']).suffix.lower();name=e['filename'];key=e['name'].lower()
                try:
                    if suffix in ['.tga','.pcx','.pcl']:
                        filename='textures/'+name+'.png'
                        # Native FUN_0042ccf0 initializes RGB key to 0x7f00ff
                        # (little-endian RGB bytes). Menu clFuchsia is separate.
                        metadata=image(data,out/filename,(255,0,127),nativeRGB=True)
                        e['imageMetadata']=metadata
                        spec={'file':filename,'source':name,**metadata}
                        alias=out/'textures'/(Path(name).stem+'.png')
                        # Rebuild aliases deterministically on every run. An
                        # old PCX alias must not retain a prior color-key mask.
                        if suffix=='.tga' or alias not in texture_aliases:
                            shutil.copyfile(out/filename,alias)
                            texture_aliases.add(alias)
                        manifest['images'].setdefault(key,spec)
                    elif suffix=='.d3d':
                        parsed=mesh(data);parsed['source']={'archive':stem,'name':e['name'],'index':e['index'],'sha256':e['sha256']}
                        filename='meshes/'+Path(name).stem+'.json';write_json(out/filename,parsed)
                        bounds=mesh_bounds(parsed)
                        manifest['meshes'].setdefault(key,{'file':filename,'vertices':parsed['vertexCount'],
                            'triangles':parsed['triangleCount'],'bounds':bounds,
                            'horizontalRadius':horizontal_radius(bounds)})
                    elif suffix=='.wav':
                        filename='audio/'+name;(out/'audio').mkdir(exist_ok=True);(out/filename).write_bytes(data)
                        manifest['audio'].setdefault(key,{'file':filename,'sha256':e['sha256']})
                except Exception as exc:
                    manifest['conversionErrors'].append({'file':name,'error':str(exc)})
            manifest['archives'][stem]={'indexSHA256':digest(idx),'imageSHA256':digest(blob),'count':len(entries),
                'types':dict(Counter(Path(e['name']).suffix.lower() or 'unnamed' for e in entries)),'entries':entries}
        for f in sorted((source/'gfx').iterdir()):
            if f.suffix.lower() not in ['.bmp','.pcx','.tga']:continue
            filename='menu/'+f.stem.lower()+'.png'
            manifest['menu'][f.name]={'file':filename,'sha256':digest(f.read_bytes()),**image(f.read_bytes(),out/filename,True)}
        write_json(out/'menu/manifest.json',manifest['menu'])
        configs={f.name.lower():ini(f.read_text(encoding='cp1252')) for f in source.iterdir() if f.suffix.lower()=='.ini'}
        configs.update({'ini/'+f.name.lower():ini(f.read_text(encoding='cp1252')) for f in (source/'ini').iterdir() if f.suffix.lower() in ['.ini','.dat']})
        write_json(out/'config.json',configs)
        prepare_loose_audio(a.installation,a.cd,out,manifest,configs)
        manifest['physics']={}
        for i in range(3):
            original=find(source,f'Phys{i}.dat');data=original.read_bytes()
            filename=f'physics/phys{i}.dat';(out/'physics').mkdir(exist_ok=True)
            (out/filename).write_bytes(data)
            manifest['physics'][str(i)]={'file':filename,'sha256':digest(data)}
        prepare_racer_tables(source,out,manifest)
        palette=Image.open(raw/'rcs/e02_pl16.pcx').getpalette()
        manifest['fonts']={}
        for f in sorted((raw/'rcs').glob('*.fnt')):
            spec=font_atlas(f.read_bytes(),palette,out/'fonts'/(f.stem+'.png'))
            spec['sha256']=digest(f.read_bytes());manifest['fonts'][f.name]=spec
        write_json(out/'fonts/manifest.json',manifest['fonts'])
        manifest['menuFonts']={}
        for filename in ['comic.ttf','comicbd.ttf','comici.ttf','comicz.ttf']:
            source_font=a.font_dir/filename
            if source_font.is_file():
                data=source_font.read_bytes();target=out/'fonts'/filename;target.write_bytes(data)
                manifest['menuFonts'][filename]={'file':'fonts/'+filename,'source':str(source_font),'sha256':digest(data)}
        write_json(out/'fonts/menu-fonts.json',manifest['menuFonts'])
        manifest['indexedSprites']={}
        for f in sorted((raw/'rc').glob('*.bin')):
            data=f.read_bytes();w,h,hx,hy=struct.unpack_from('<4H',data)
            if len(data)!=8+w*h:raise ValueError(f'RC indexed sprite length mismatch: {f}')
            target=out/'indexed-sprites'/(f.stem+'.png');target.parent.mkdir(exist_ok=True)
            Image.frombytes('L',(w,h),data[8:]).save(target)
            manifest['indexedSprites'][f.stem]={'file':'indexed-sprites/'+target.name,
                'width':w,'height':h,'hotspot':[hx,hy],'encoding':'8-bit palette indices, not display RGB',
                'paletteStatus':'Unresolved; raw index values preserved losslessly'}
        write_json(out/'indexed-sprites/manifest.json',manifest['indexedSprites'])
        tracks=configs['track.ini']['maps']
        for i in range(6):
            stem=f'etappe{i}';spec=[x.strip() for x in tracks[str(i)].split(',')]
            parsed=road(find(source,stem+'.rmp').read_bytes())
            parsed.update({'id':i,'name':spec[8],'textures':[manifest['images'][t+'.tga']['file'] for t in spec[2:6]],
                'editorTextures':[Path(configs[stem+'.ini']['textures'][str(j)].replace('\\','/')).name.lower() for j in range(4)],
                'route':route(find(source,stem+'.pmp').read_bytes()),'placements':placements(find(source,stem+'.omp').read_bytes()),
                'collision':collision(find(source,stem+'.cmp').read_bytes()),'drive':drive(find(source,stem+'.dmp').read_bytes()),
                'paths':paths(find(source,stem+'.pth').read_bytes()),
                'pathTypes':configs[stem+'.ini'].get('pathtypes',{}),
                'pathObjects':configs[f'animobj{i}.ini'].get('path_objects',{}),
                'sky':[spec[6],spec[7]],'music':int(spec[9]),'mirrored':bool(int(spec[14]))})
            definitions={}
            for k,v in configs[stem+'.ini']['objects'].items():
                if not k.isdigit():continue
                fields=[s.strip() for s in v.split(',')]
                definitions[fields[4].lower()]={'mesh':Path(fields[0].replace('\\','/')).name.lower(),'texture':Path(fields[1].replace('\\','/')).name.lower(),
                    'name':fields[2],'fields':fields}
            parsed['objectDefinitions']=definitions
            parsed['source']={s:digest(find(source,stem+'.'+s).read_bytes()) for s in ['rmp','pmp','omp','cmp','dmp','ini','pth']}
            filename='tracks/'+stem+'.json';write_json(out/filename,parsed)
            manifest['tracks'].append({'id':i,'name':spec[8],'file':filename,'sectors':parsed['sectorCount'],
                'quads':len(parsed['index'])//6,'objects':len(parsed['placements']),'mirrored':parsed['mirrored']})
            print(f'Converted {spec[8]}: {len(parsed["index"])//6} quads, {len(parsed["placements"])} objects',flush=True)
        for f in sorted(source.glob('rclemu*.dat')):
            filename='audio/'+f.stem+'.mp3';shutil.copyfile(f,out/filename)
            manifest['audio'][f.name]={'file':filename,'sha256':digest(f.read_bytes()),'format':'MPEG Layer III (source .dat extension)'}
        # Runtime 0041bb30 selects this record using Race.INI [PLAYER] car,
        # irrespective of the contestant argument. 0041bdd0 builds these children.
        carconfig=configs['car_ssr.ini'];cars={}
        for key,value in carconfig['cars'].items():
            section=value.split(',')[0].strip().lower();row=carconfig[section]
            coords=[struct.unpack('<f',struct.pack('<f',float(v.strip())))[0] for v in row['wheelpos'].split(',')]
            front=row['fwheels'].lower();rear=row['bwheels'].lower()
            radii=[]
            for filename in [front,rear]:
                geometry=json.loads((out/manifest['meshes'][filename]['file']).read_text())
                radii.append(abs(min(geometry['position'][1::3])))
            cars[key]={'section':section,'body':row['mesh'].lower(),'frontWheel':front,'rearWheel':rear,
                'bodyBounds':manifest['meshes'][row['mesh'].lower()]['bounds'],
                'frontRadius':radii[0],'rearRadius':radii[1],'wheelOffsets':[
                    [-coords[0],*coords[1:3]],coords[:3],[-coords[3],*coords[4:6]],coords[3:6]]}
        write_json(out/'cars.json',{'cars':cars,'selectionSource':'Race.INI [PLAYER] car',
            'nativeFunctions':['0041bb30','0041bdd0','00475140','0042df90','00416650'],
            'sourceSHA256':digest(find(source,'car_ssr.ini').read_bytes())})
        manifest['cars']='cars.json'
        manifest['trackMusic']={str(i):manifest['audio'][f'rclemu{i:02d}.dat']['file'] for i in range(6)}
        write_json(out/'manifest.json',manifest)
        write_json(ROOT/'docs/evidence/asset-inventory.json',{'tracks':manifest['tracks'],'archives':{k:{j:v for j,v in a.items() if j!='entries'} for k,a in manifest['archives'].items()},
            'images':len(manifest['images']),'meshes':len(manifest['meshes']),'audio':len(manifest['audio']),
            'fonts':len(manifest['fonts']),'indexedSprites':len(manifest['indexedSprites']),
            'menu':len(manifest['menu']),'errors':manifest['conversionErrors']})
    if not a.skip_media:
        def convert(f):
            target=out/'media'/(f.stem.lower()+'.mp4');target.parent.mkdir(exist_ok=True)
            sha=digest(f.read_bytes());cache=target.with_suffix('.sha256')
            if not target.exists() or not cache.exists() or cache.read_text()!=sha:
                temp=target.with_suffix('.part.mp4')
                subprocess.run(['ffmpeg','-hide_banner','-loglevel','error','-y','-i',str(f),'-map','0:v:0','-map','0:a:0?',
                    '-c:v','libx264','-crf','18','-preset','fast','-pix_fmt','yuv420p','-threads','2',
                    '-c:a','aac','-b:a','160k','-movflags','+faststart',str(temp)],check=True)
                temp.replace(target);cache.write_text(sha)
            probe=json.loads(subprocess.check_output(['ffprobe','-v','quiet','-show_format','-show_streams','-of','json',str(f)]))
            print(f'Converted movie {f.name}',flush=True)
            return f.stem.lower(),{'file':'media/'+target.name,'sha256':sha,'original':str(f.relative_to(a.cd)),
                'duration':float(probe['format']['duration']),'streams':[{k:s[k] for k in ['codec_type','codec_name','width','height','sample_rate','channels','r_frame_rate','avg_frame_rate','display_aspect_ratio'] if k in s} for s in probe['streams']]}
        with ThreadPoolExecutor(max_workers=3) as pool:
            manifest['movies']=dict(pool.map(convert,sorted((a.cd/'Media/movies').glob('*.[mM][pP][gG]'))))
        write_json(out/'media/manifest.json',manifest['movies']);write_json(out/'manifest.json',manifest)
    print(f'Assets prepared; {len(manifest.get("conversionErrors",[]))} conversion errors (see manifest)',flush=True)
    return 1 if manifest.get('conversionErrors') else 0
if __name__=='__main__':raise SystemExit(main())
