#!/usr/bin/env python3
"""Reproduce the original game inspection source without modifying the original.

Requires Python 3, pefile, and Ghidra headless. Default imports are fresh.
--reuse-existing accepts only this repository's hash-bound earlier databases.
"""
from pathlib import Path
import argparse, concurrent.futures, hashlib, json, os, shutil, struct, subprocess
import pefile

ROOT=Path(__file__).resolve().parents[1]
REPO=ROOT.parent
MODULES=['rcskmenu.dat','rcskspel.dat','RCSK.exe','RCMovie.dat','SMACKW32.DLL']
DEFAULT_CD='/home/rick/Games/UnpackedISO/RedCat Superkarts/RedCat Superkarts'
DEFAULT_INSTALLED='/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data'
def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def write_json(path,data):path.parent.mkdir(parents=True,exist_ok=True);path.write_text(json.dumps(data,indent=2)+'\n')
def pe_info(path):
    pe=pefile.PE(str(path),fast_load=True)
    return {'machine':hex(pe.FILE_HEADER.Machine),'image_base':hex(pe.OPTIONAL_HEADER.ImageBase),
            'entry_point':hex(pe.OPTIONAL_HEADER.ImageBase+pe.OPTIONAL_HEADER.AddressOfEntryPoint),
            'sections':[{'name':s.Name.rstrip(b'\0').decode(errors='replace'),
                         'virtual_address':hex(pe.OPTIONAL_HEADER.ImageBase+s.VirtualAddress),
                         'virtual_size':s.Misc_VirtualSize,'file_offset':s.PointerToRawData,
                         'raw_size':s.SizeOfRawData,'flags':hex(s.Characteristics)} for s in pe.sections]}
def inventory(cd,installed):
    entries=[]
    for path in sorted(cd.rglob('*')):
        if not path.is_file():continue
        with path.open('rb') as f:
            header=f.read(64)
            if len(header)<64 or header[:2]!=b'MZ':continue
            f.seek(struct.unpack_from('<I',header,0x3c)[0]);signature=f.read(4)
        # Legacy NE/DOS installers are recorded too, but cannot be PE imported.
        rel=str(path.relative_to(cd));game=rel.startswith('data/Game/') and path.name in MODULES
        entries.append({'path':rel,'size':path.stat().st_size,'sha256':digest(path),
                        'format':'PE' if signature==b'PE\0\0' else 'DOS_or_NE',
                        'scope':'game_runtime' if game else 'installer_autorun_or_third_party_support',
                        'exported':game})
    game=[x for x in entries if x['scope']=='game_runtime']
    assert sorted(Path(x['path']).name for x in game)==sorted(MODULES)
    for x in game:
        source=cd/x['path'];dest=ROOT/'inputs'/source.name
        dest.parent.mkdir(exist_ok=True);shutil.copyfile(source,dest)
        x['input_copy']='inputs/'+source.name;x['pe']=pe_info(source)
        comparison=installed/source.name
        x['installed_copy']=str(comparison)
        x['installed_sha256']=digest(comparison) if comparison.is_file() else None
        x['cd_installed_identical']=x['installed_sha256']==x['sha256']
    result={'source_date':'2026-10-26','cd_root':str(cd),'installed_root':str(installed),
            'scope_note':'All game-runtime PE images in data/Game; CD installer, autorun and third-party driver redistributables are inventoried but excluded from game-source decompilation.',
            'game_modules':game,'all_cd_mz_images':entries}
    write_json(ROOT/'input-manifest.json',result)
    dependencies=[]
    for subtree in ['data','Media']:
        for path in sorted((cd/subtree).rglob('*')):
            if not path.is_file() or path.parent.name=='Game' and path.name in MODULES:continue
            dependencies.append({'path':str(path.relative_to(cd)),'size':path.stat().st_size,'sha256':digest(path)})
    write_json(ROOT/'reference-data.json',{
        'cd_root':str(cd),'files':dependencies,
        'note':'Original non-PE game configuration, archive, help, image, audio and movie data. Read-only references; no contents are inferred from filenames. The five game runtime binaries are in input-manifest.json.',
        'repository_readers':['../tools/prepare-assets.py','../tools/native-menu-methods.py'],
        'repository_extracted_originals':'../raw/',
        'repository_browser_assets':'../public/assets/',
        'resource_evidence':'../evidence/native/menu-resources/'})
    return result
def validate_seeds():
    raw=(ROOT/'inputs/rcskmenu.dat').read_bytes()
    tables=json.loads((ROOT/'tools/menu-method-tables.json').read_text())
    seeds=['address\tname\trecord_file_offset']
    for cls,table in tables.items():
        for name,address in table['methods'].items():
            record=struct.pack('<I',int(address,16))+bytes([len(name)])+name.encode('ascii')
            offset=raw.find(record)
            assert offset>=2 and struct.unpack_from('<H',raw,offset-2)[0]>=len(record)+2,(cls,name)
            seeds.append(f'{int(address,16):08x}\t{cls}_{name}\t{offset-2:08x}')
    (ROOT/'tools/menu-method-seeds.tsv').write_text('\n'.join(seeds)+'\n')
def export(name,args):
    output=ROOT/'modules'/name
    if output.exists():shutil.rmtree(output)
    output.mkdir(parents=True,exist_ok=True)
    project=ROOT/'work/projects'/name;project.parent.mkdir(parents=True,exist_ok=True)
    source=ROOT/'inputs'/name
    reuse=False
    if args.reuse_existing:
        previous=REPO/'evidence/native/projects'/name
        manifest=REPO/'evidence/native/logs'/f'{name}-command.json'
        if previous.exists() and manifest.exists():
            evidence=json.loads(manifest.read_text())
            assert evidence['source_sha256']==digest(source) and evidence['returncode']==0
            if project.exists():shutil.rmtree(project)
            shutil.copytree(previous,project);reuse=True
    project.mkdir(parents=True,exist_ok=True)
    if not reuse:
        # Finish initial analysis before post-processing: headless normally
        # analyzes again after post scripts, which could add unexported functions.
        initial=[args.ghidra,str(project),'analysis','-import',str(source),'-overwrite','-analysisTimeoutPerFile','900','-max-cpu','2']
        (ROOT/'logs').mkdir(exist_ok=True)
        with (ROOT/'logs'/f'{name}-import.log').open('w') as log:
            imported=subprocess.run(initial,stdout=log,stderr=subprocess.STDOUT,env=dict(os.environ,GHIDRA_HEADLESS_MAXMEM='2G'))
        if imported.returncode:raise RuntimeError(f'Initial analysis failed: {name}')
    command=[args.ghidra,str(project),'analysis','-process',name,'-noanalysis']
    command+=['-scriptPath',str(ROOT/'tools'),'-max-cpu','2','-postScript','RecoverFunctions.java',str(output)]
    if name=='rcskmenu.dat':command.append(str(ROOT/'tools/menu-method-seeds.tsv'))
    command+=['-postScript','OriginalSourceExport.java',str(output)]
    logfile=ROOT/'logs'/f'{name}.log';logfile.parent.mkdir(exist_ok=True)
    with logfile.open('w') as log:
        result=subprocess.run(command,stdout=log,stderr=subprocess.STDOUT,env=dict(os.environ,GHIDRA_HEADLESS_MAXMEM='2G'))
    text=logfile.read_text();success=result.returncode==0 and 'EXPORT COMPLETE:' in text
    write_json(ROOT/'logs'/f'{name}-command.json',{'command':command,'returncode':result.returncode,
               'export_completed':success,'source_sha256':digest(source),'reused_matching_database':reuse,
               'reuse_source':str(REPO/'evidence/native/projects'/name) if reuse else None})
    print(name,'complete' if success else 'FAILED',flush=True)
    if not success:raise RuntimeError(f'{name}: inspect {logfile}')
def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cd-root',type=Path,default=Path(DEFAULT_CD))
    parser.add_argument('--installed-root',type=Path,default=Path(DEFAULT_INSTALLED))
    parser.add_argument('--ghidra',default=shutil.which('ghidra-headless') or '/home/rick/.local/bin/ghidra-headless')
    parser.add_argument('--jobs',type=int,default=2)
    parser.add_argument('--reuse-existing',action='store_true')
    parser.add_argument('--module',choices=MODULES,action='append')
    args=parser.parse_args()
    inventory(args.cd_root.resolve(),args.installed_root.resolve());validate_seeds()
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        list(pool.map(lambda name:export(name,args),args.module or MODULES))
    # Recheck originals after every analysis. No command ever opens them for write.
    manifest=json.loads((ROOT/'input-manifest.json').read_text())
    for entry in manifest['game_modules']:
        assert digest(args.cd_root/entry['path'])==entry['sha256']
        if entry['installed_sha256'] is not None:assert digest(Path(entry['installed_copy']))==entry['installed_sha256']
if __name__=='__main__':main()
