#!/usr/bin/env python3
"""Recover Delphi form method names via class VMT, without source-name inference."""
import argparse,json,struct
from pathlib import Path
import pefile
ROOT=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--source',type=Path,default=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data/rcskmenu.dat'));a.add_argument('--output',type=Path,default=ROOT/'evidence/native/metadata/menu-form-methods.json');args=a.parse_args()
p=pefile.PE(str(args.source));b=p.get_memory_mapped_image();base=p.OPTIONAL_HEADER.ImageBase
out={}
for fp in (ROOT/'evidence/native/menu-resources').glob('*.json'):
 f=json.loads(fp.read_text());name=f['class'];needle=bytes([len(name)])+name.encode();pos=0
 while (pos:=b.find(needle,pos))>=0:
  target=struct.pack('<I',base+pos);q=0
  while (q:=b.find(target,q))>=0:
   if q>=8:
    mt=struct.unpack_from('<I',b,q-8)[0]-base
    if 0<=mt<len(b)-2:
     count=struct.unpack_from('<H',b,mt)[0]
     if count<200:
      cursor=mt+2;methods={}
      for _ in range(count):
       length,addr=struct.unpack_from('<HI',b,cursor);n=b[cursor+6]
       if length<7+n or cursor+length>len(b):raise ValueError('Invalid Delphi method record')
       methods[b[cursor+7:cursor+7+n].decode('ascii')]=f'0x{addr:x}';cursor+=length
      if methods:
       fields={};ft=struct.unpack_from('<I',b,q-12)[0]-base
       if 0<=ft<len(b)-6:
        fc=struct.unpack_from('<H',b,ft)[0];fcursor=ft+6
        if fc<1000:
         for _ in range(fc):
          off,kind=struct.unpack_from('<IH',b,fcursor);fl=b[fcursor+6]
          fields[b[fcursor+7:fcursor+7+fl].decode('ascii')]=f'0x{off:x}';fcursor+=7+fl
       out[name]={'vmt':f'0x{base+q+44:x}','methods':methods,'fields':fields}
   q+=4
  pos+=len(needle)
args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(out,indent=2)+'\n');print('Recovered method tables for',len(out),'forms')
