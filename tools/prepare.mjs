import {spawnSync} from 'node:child_process';
import path from 'node:path';
import {existsSync} from 'node:fs';
const args=process.argv.slice(2);
const installation=args.includes('--installation')?args[args.indexOf('--installation')+1]:'/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts';
const data=existsSync(path.join(installation,'data'))?path.join(installation,'data'):installation;
function run(command,argv){
  const result=spawnSync(command,argv,{stdio:'inherit'});
  if(result.error)throw result.error;
  if(result.status!==0)process.exit(result.status||1);
}
const python=process.env.PYTHON||'python3';
run(python,['tools/prepare-assets.py',...args]);
run(python,['tools/native-menu-resources.py','--source',path.join(data,'rcskmenu.dat')]);
run(python,['tools/inventory_gameplay.py','--source',data]);
run(process.execPath,['tools/prepare-ui.mjs']);
run(python,['tools/prepare-icon.py','--source',path.join(data,'RCSK.exe')]);
run(python,['tools/prepare-menu-regions.py','--source',data]);
run(python,['tools/prepare-help.py','--source',path.join(data,'RCSK.HLP')]);
