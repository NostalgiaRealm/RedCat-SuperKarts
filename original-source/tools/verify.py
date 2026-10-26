#!/usr/bin/env python3
"""Check export completeness, file mappings and original byte preservation.

This is static deliverable validation, not game/runtime parity validation.
"""
from pathlib import Path
import csv, hashlib, json
import pefile

ROOT=Path(__file__).resolve().parents[1]
def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def rows(path):
    with path.open() as f:return list(csv.DictReader(f,delimiter='\t'))
def write_json(path,data):path.write_text(json.dumps(data,indent=2)+'\n')
def main():
    manifest=json.loads((ROOT/'input-manifest.json').read_text());modules=[]
    for entry in manifest['game_modules']:
        name=Path(entry['path']).name;folder=ROOT/'modules'/name;source=ROOT/entry['input_copy']
        assert digest(source)==entry['sha256'],name
        for path,sha in [(Path(manifest['cd_root'])/entry['path'],entry['sha256']),
                         (Path(entry['installed_copy']),entry['installed_sha256'])]:
            if path.exists() and sha:assert digest(path)==sha,(name,'original changed')
        command=json.loads((ROOT/'logs'/f'{name}-command.json').read_text())
        assert command['source_sha256']==entry['sha256'] and command['export_completed']
        summary=json.loads((folder/'summary.json').read_text());functions=rows(folder/'functions.tsv')
        assert len(functions)==summary['functions'] and len({x['address'] for x in functions})==len(functions)
        assert sum(x['status']=='decompiled' for x in functions)==summary['decompiled']
        assert sum(x['status']=='assembly_fallback' for x in functions)==summary['assembly_fallback']
        assert len(list((folder/'functions').glob('*.c')))==len(functions)
        assert len(list((folder/'assembly').glob('*.asm')))==len(functions)
        warnings=[];all_source=(folder/'full_decompilation.c').read_text()
        all_source_lines='\n'.join(x for x in all_source.splitlines() if x.strip())
        source_cursor=0
        for f in functions:
            text=(folder/f['file']).read_text()
            normalized='\n'.join(x for x in text.splitlines() if x.strip())
            source_index=all_source_lines.find(normalized,source_cursor)
            assert source_index>=0,(name,f['address'],'missing combined source')
            source_cursor=source_index+len(normalized)
            assert ' at '+f['address'] in text,(name,f['address'],'missing address')
            ranges=[tuple(int(a,16) for a in part.split('-')) for part in f['body_ranges'].split(';')]
            assert sum(b-a+1 for a,b in ranges)==int(f['body_bytes'])
            if f['error'] or 'WARNING:' in text:
                warnings.append({'address':f['address'],'name':f['name'],'file':f['file'],
                                 'decompiler_message':f['error'],
                                 'warnings':[x.strip() for x in text.splitlines() if 'WARNING:' in x]})
        pe=pefile.PE(str(source));base=pe.OPTIONAL_HEADER.ImageBase;raw=source.read_bytes()
        assembly=rows(folder/'assembly.tsv');instruction_bytes=0;orphan_instructions=0
        assembly_by_address={i['address']:i for i in assembly}
        by_function={f['address']:set() for f in functions}
        function_addresses={x['address'] for x in functions}
        for i in assembly:
            address=int(i['address'],16);expected=bytes.fromhex(i['bytes']);offset=pe.get_offset_from_rva(address-base)
            assert raw[offset:offset+len(expected)]==expected,(name,i['address'],'instruction bytes differ')
            assert not i['function'] or i['function'] in function_addresses
            if i['function']:by_function[i['function']].add(i['address'])
            instruction_bytes+=len(expected);orphan_instructions+=not bool(i['function'])
        for f in functions:
            actual=set()
            for line in (folder/'assembly'/f"{f['address']}.asm").read_text().splitlines()[1:]:
                address,encoded,instruction=line.split('\t',2)
                assert address in assembly_by_address and encoded==assembly_by_address[address]['bytes']
                assert instruction==assembly_by_address[address]['instruction']
                actual.add(address)
            assert actual==by_function[f['address']],(name,f['address'],'per-function assembly differs')
        assert len(assembly)==summary['instructions']
        recovery=rows(folder/'function-recovery.tsv')
        write_json(folder/'decompiler-warnings.json',warnings)
        modules.append({'module':name,'sha256':entry['sha256'],'identified_functions':len(functions),
                        'decompiled_functions':summary['decompiled'],'assembly_fallbacks':summary['assembly_fallback'],
                        'retried_functions':summary['retried'],'decompiler_warning_functions':len(warnings),
                        'no_return_assumptions':sum(x.get('no_return')=='true' for x in functions),
                        'functions_with_outside_executable_pcode_origins':summary['functions_with_outside_pcode_origins'],
                        'instructions_verified_against_original':len(assembly),'instruction_bytes_verified':instruction_bytes,
                        'instructions_without_function':orphan_instructions,
                        'instruction_bytes_outside_functions':summary['instruction_bytes_outside_functions'],
                        'executable_bytes_without_instructions':summary['executable_bytes_without_instructions'],
                        'recovery_identified_or_created':sum(x['result'] in ['created','identified'] for x in recovery),
                        'recovery_unresolved':[x for x in recovery if x['result'] not in ['created','identified'] and x['address'] not in function_addresses],
                        'recovery_rejected_attempts_later_resolved':sum(x['result'] not in ['created','identified'] and x['address'] in function_addresses for x in recovery),
                        'checks_passed':True})
    total=lambda key:sum(m[key] for m in modules)
    verification={'date':'2026-10-26','scope':'Static decompilation/export completeness and original byte identity; not runtime or port parity.',
                  'all_game_runtime_modules_exported':len(modules)==5,'modules':modules,
                  'totals':{key:total(key) for key in ['identified_functions','decompiled_functions','assembly_fallbacks',
                            'decompiler_warning_functions','instructions_verified_against_original','instruction_bytes_verified',
                            'instruction_bytes_outside_functions','executable_bytes_without_instructions']},
                  'limitations':[
                    'Decompilation recovers C-like inspection pseudocode, not the lost authored source, build system, original variable names, or exact types.',
                    'All identified functions are exported. Function discovery is heuristic; executable-section gaps can contain undiscovered code, embedded tables or padding.',
                    'Decoded instructions outside function bodies remain available in assembly.tsv. No-return, exception flow and computed dispatch assumptions can truncate pseudocode.',
                    'Decompiler warnings and unmapped/indirect targets are preserved, not silently resolved. Successful decompilation does not prove semantic equivalence.',
                    'CD installer/autorun and third-party redistributable executables are inventoried but outside the game-runtime export. Operating-system DLLs are not part of the shipped game source.'
                  ],'checks_passed':True}
    write_json(ROOT/'verification.json',verification)
    files=[]
    for path in sorted(ROOT.rglob('*')):
        relative=path.relative_to(ROOT)
        if not path.is_file() or relative.parts[0]=='work' or '__pycache__' in relative.parts or relative.name=='SHA256SUMS.txt':continue
        files.append(f'{digest(path)}  {relative.as_posix()}')
    (ROOT/'SHA256SUMS.txt').write_text('\n'.join(files)+'\n')
    print(json.dumps({'checks_passed':True,'modules':len(modules),'totals':verification['totals'],'hashed_files':len(files)},indent=2))
if __name__=='__main__':main()
