#!/usr/bin/env python3
"""Inventory shipped reachability inputs and exact PE references; no binary writes."""
import argparse, collections, hashlib, json, re, struct, subprocess
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser()
parser.add_argument('--source',type=Path,default=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data'))
parser.add_argument('--output',type=Path,default=ROOT/'evidence/native/legacy-feature-inventory.json')
args=parser.parse_args()
binary=args.source/'rcskspel.dat';raw=binary.read_bytes();pe=pefile.PE(data=raw)
assembly=subprocess.run(['objdump','-d',str(binary)],check=True,capture_output=True,text=True).stdout
direct=collections.defaultdict(list)
for line in assembly.splitlines():
 match=re.match(r'^\s*([0-9a-f]+):.*\bcall\s+0x([0-9a-f]+)\s*$',line)
 if match:direct[int(match[2],16)].append('0x'+match[1])
def pointer_references(address):
 result=[];pattern=struct.pack('<I',address);start=0
 while True:
  offset=raw.find(pattern,start)
  if offset<0:return result
  try:result.append(hex(pe.OPTIONAL_HEADER.ImageBase+pe.get_rva_from_offset(offset)))
  except pefile.PEFormatError:pass
  start=offset+1
def function(address,size):
 return {'address':hex(address),'bytes':pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase,size).hex(),
         'directCalls':direct[address],'absoluteAddressOccurrences':pointer_references(address)}
config=json.loads((ROOT/'public/assets/config.json').read_text())
forms=json.loads((ROOT/'public/assets/ui/forms.json').read_text())
def controls(form):
 result=[]
 def visit(node):
  if node['class']=='TDaviGraphicRadioButton':
   result.append({'name':node['name'],'onClick':node['properties'].get('OnClick')})
  for child in node['children']:visit(child)
 visit(form);return result
tracks=[]
for track_id in range(6):
 track=json.loads((ROOT/f'public/assets/tracks/etappe{track_id}.json').read_text())
 paths=collections.Counter(path['type']for path in track['paths'])
 objects=collections.Counter(obj['type']for obj in track['placements'])
 tracks.append({'track':track_id,'pathTypes':dict(sorted(paths.items())),
  'legacyBuiltinPaths2to12':sum(paths[k]for k in range(2,13)),
  'trafficLightObjectsType4':objects[4]})
ini=config['ini/shellimg.dat']
sequence=[value for key,value in ini['advsequence'].items()if key.isdecimal()]
out={
 'sourceSha256':hashlib.sha256(raw).hexdigest(),
 'scope':'Shipped menu/config/content reachability, complete objdump direct-call scan, raw PE absolute-address scan. Absence of an absolute address does not alone rule out computed dispatch.',
 'traffic':{
  'configReader':function(0x4077e0,6),'disabledInitializer':function(0x412e00,17),
  'modelGetterReferences':pointer_references(0x53ba58),
  'selectionFunction':function(0x407940,8),'tracks':tracks,
  'emptyTableConstructor':function(0x407680,25)},
 'bonusRace':{
  'quickRaceRadioControls':controls(forms['TFRMSELECTCOUNTRY']),
  'quickRaceSetterValues':{'0x46fefc':0,'0x46ff20':1,'0x46ff44':2},
  'adventureSequence':sequence,'required':ini['requiredtypes']['bonusrace'],
  'statusIcon':ini['staticons']['bonusrace'],
  'hudInit':function(0x46aa20,12),'hudUpdate':function(0x46aa70,12)},
 'money':{'suppliedValue':config['race.ini']['player']['money'],
  'readAndDiscardFunction':function(0x42c0a0,0x49),
  'menuMoneyStringPresent':b'money'in(args.source/'rcskmenu.dat').read_bytes().lower()},
 'damage':{'suppliedValue':config['race.ini']['player']['damage'],
  'numericalCollisionSink':function(0x435630,1),
  'globalAddressReferences':pointer_references(0x53be30),
  'damageMeshTableReferences':pointer_references(0x6847d0),
  'damageMeshInit':'0x42ccf0 ->0x49aec0(1000), all pointers zero',
  'damageMeshGuard':'0x48ffc0/0x490130 only bind nonzero table entries;0x4343d0 returns when body+0xc8 == -1'}
}
args.output.parent.mkdir(parents=True,exist_ok=True)
args.output.write_text(json.dumps(out,indent=2)+'\n')
print(json.dumps({'tracks':len(tracks),'legacyTrafficPaths':sum(x['legacyBuiltinPaths2to12']for x in tracks),
 'bonusRaceCampaignEntries':sum('BONUSRACE'in x.upper()for x in sequence),
 'damageSink':out['damage']['numericalCollisionSink']['bytes'],
 'trafficInitIncomingCalls':out['traffic']['disabledInitializer']['directCalls'],
 'trafficInitAbsolutePointers':out['traffic']['disabledInitializer']['absoluteAddressOccurrences']}))
