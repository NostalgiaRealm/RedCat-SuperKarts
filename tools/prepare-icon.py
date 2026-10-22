#!/usr/bin/env python3
"""Reassemble the launcher's original icon resources without pixel conversion."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--source',type=Path,required=True)
args=parser.parse_args()
pe=pefile.PE(str(args.source))
resources={}
for kind in pe.DIRECTORY_ENTRY_RESOURCE.entries:
    if kind.id not in (3,14):
        continue
    for entry in kind.directory.entries:
        item=entry.directory.entries[0].data.struct
        resources[(kind.id,str(entry.name) if entry.name else entry.id)]=pe.get_data(item.OffsetToData,item.Size)
groups=[(name,data) for (kind,name),data in resources.items() if kind==14]
if not groups:
    raise SystemExit('The original launcher has no icon group.')
name,data=groups[0]
reserved,kind,count=struct.unpack_from('<HHH',data)
if reserved!=0 or kind!=1 or len(data)!=6+count*14:
    raise SystemExit('Invalid original icon-group directory.')
entries=[];images=[];offset=6+count*16
for i in range(count):
    fields=struct.unpack_from('<BBBBHHIH',data,6+i*14)
    image=resources[(3,fields[-1])]
    if len(image)!=fields[-2]:
        raise SystemExit('Original icon image size mismatch.')
    entries.append(struct.pack('<BBBBHHII',*fields[:-1],offset))
    images.append(image);offset+=len(image)
output=struct.pack('<HHH',0,1,count)+b''.join(entries)+b''.join(images)
folder=ROOT/'public/assets/ui';folder.mkdir(parents=True,exist_ok=True)
(folder/'original.ico').write_bytes(output)
(folder/'icon-source.json').write_text(json.dumps({
    'source':str(args.source),'sourceSHA256':hashlib.sha256(args.source.read_bytes()).hexdigest(),
    'group':name,'images':count,'imageSHA256':[hashlib.sha256(image).hexdigest() for image in images],
    'iconSHA256':hashlib.sha256(output).hexdigest(),
},indent=2)+'\n')
print(f'Preserved {count} original launcher icon images')
