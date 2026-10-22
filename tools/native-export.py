#!/usr/bin/env python3
"""Static Ghidra export of original PE inputs. Writes only inside this project."""
from pathlib import Path
import subprocess,concurrent.futures,json,hashlib,os
root=Path(__file__).resolve().parents[1]
src=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data')
def run(n):
 out=root/'evidence/native'/n;project=root/'evidence/native/projects'/n
 project.mkdir(parents=True,exist_ok=True)
 cmd=['/home/rick/.local/bin/ghidra-headless',str(project),'analysis','-import',str(src/n),'-overwrite','-scriptPath',str(root/'tools/native-ghidra'),'-max-cpu','2','-analysisTimeoutPerFile','900','-postScript','ExportAll.java',str(out)]
 log=root/'evidence/native/logs'/f'{n}.log'
 with log.open('w') as f:
  r=subprocess.run(cmd,stdout=f,stderr=subprocess.STDOUT,env=dict(os.environ,GHIDRA_HEADLESS_MAXMEM='2G'))
 (root/'evidence/native/logs'/f'{n}-command.json').write_text(json.dumps({'command':cmd,'returncode':r.returncode,'source_sha256':hashlib.sha256((src/n).read_bytes()).hexdigest()},indent=2))
 print(n,r.returncode,flush=True)
with concurrent.futures.ThreadPoolExecutor(max_workers=2) as e:list(e.map(run,['RCSK.exe','rcskspel.dat','RCMovie.dat','rcskmenu.dat']))
