#!/usr/bin/env python3
"""Extract Delphi DFM resources as structured properties, without running code."""
from pathlib import Path
import pefile,struct,json,hashlib,argparse
ROOT=Path(__file__).resolve().parents[1]
DEFAULT_SOURCE=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data/rcskmenu.dat')
class Dfm:
 def __init__(self,b):
  if b[:4]!=b'TPF0':raise ValueError('Missing TPF0 signature')
  self.b=b;self.p=4;self.depth=0
 def n(self,n):
  if n<0 or self.p+n>len(self.b):raise ValueError(f'Truncated DFM at {self.p}, need {n} bytes')
  v=self.b[self.p:self.p+n];self.p+=n;return v
 def u(self,f):return struct.unpack('<'+f,self.n(struct.calcsize('<'+f)))[0]
 def s(self):return self.n(self.u('B')).decode('cp1252')
 def v(self):
  k=self.u('B')
  if k==0:return None
  if k==1:
   a=[]
   while self.b[self.p]:a.append(self.v())
   self.p+=1;return a
  if k in [2,3,4,19]:return self.u({2:'b',3:'h',4:'i',19:'q'}[k])
  if k==5:return {'extended80':self.n(10).hex()}
  if k in [6,7]:return self.s()
  if k in [8,9]:return k==9
  if k==10:
   b=self.n(self.u('I'));return {'binaryBytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}
  if k==11:
   a=[]
   while self.b[self.p]:a.append(self.s())
   self.p+=1;return a
  if k in [12,20]:return self.n(self.u('I')).decode('cp1252' if k==12 else 'utf8')
  if k==13:return None
  if k==14:
   a=[]
   while self.b[self.p]:
    item={};self.p+=1
    while self.b[self.p]:
     key=self.s();item[key]=self.v()
    self.p+=1;a.append(item)
   self.p+=1;return a
  if k==15:return self.u('f')
  if k==16:return self.u('q')/10000
  if k==17:return self.u('d')
  if k==18:return self.n(self.u('I')*2).decode('utf16le')
  raise ValueError((self.p,k))
 def node(self):
  self.depth+=1
  if self.depth>100:raise ValueError('Excessive DFM nesting')
  flags=0
  if self.b[self.p]&0xf0==0xf0:flags=self.u('B')
  if flags:raise ValueError(f'Unsupported component flags {flags:#x}')
  n={'class':self.s(),'name':self.s(),'properties':{},'children':[]}
  while self.b[self.p]:
   key=self.s();n['properties'][key]=self.v()
  self.p+=1
  while self.b[self.p]:n['children'].append(self.node())
  self.p+=1;self.depth-=1;return n
def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--source',type=Path,default=DEFAULT_SOURCE);parser.add_argument('--output',type=Path,default=ROOT/'evidence/native/menu-resources');args=parser.parse_args()
 source=args.source
 if source.is_dir():source=source/'rcskmenu.dat'
 p=pefile.PE(str(source));out=args.output;out.mkdir(parents=True,exist_ok=True)
 failures=[];pending=[];count=0
 for t in p.DIRECTORY_ENTRY_RESOURCE.entries:
  if t.id!=10:continue
  for n in t.directory.entries:
   s=n.directory.entries[0].data.struct;b=p.get_data(s.OffsetToData,s.Size)
   if b[:4]!=b'TPF0':continue
   d=Dfm(b)
   try:
    r=d.node()
    if d.p!=len(b):raise ValueError(f'Unconsumed DFM bytes: {len(b)-d.p}')
    r['source']={'resource':str(n.name),'rva':hex(s.OffsetToData),'bytes':len(b),'parsedBytes':d.p};pending.append((str(n.name),r));count+=1
   except (ValueError,IndexError,struct.error,UnicodeError) as e:failures.append(f'{n.name}: {e}')
 if failures:raise SystemExit('Invalid DFM resources: '+ '; '.join(failures))
 if not count:raise SystemExit('No TPF0 form resources found')
 for name,data in pending:(out/(name+'.json')).write_text(json.dumps(data,indent=2))
 print(f'Validated {count} form resources')
if __name__=='__main__':main()
