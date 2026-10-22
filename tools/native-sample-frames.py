#!/usr/bin/env python3
"""Passive sample of this project's owned reference game's frame counter."""
import os,time,json,struct,statistics
from pathlib import Path
prefix=str(Path('evidence/native/runtime/wineprefix').resolve()).encode()
pid=None
for p in Path('/proc').glob('[0-9]*'):
 try:
  if (p/'comm').read_text().strip()=='rcskspel.dat' and b'WINEPREFIX='+prefix in (p/'environ').read_bytes().split(b'\0'):pid=int(p.name);break
 except (OSError,ValueError):pass
assert pid,'Owned reference game process not found'
f=os.open(f'/proc/{pid}/mem',os.O_RDONLY)
read=lambda addr:struct.unpack('<I',os.pread(f,4,addr))[0]
start=time.monotonic_ns();prev=read(0x53bab8);a=[{'ns':0,'frame':prev}]
while time.monotonic_ns()-start<12_000_000_000:
 now=time.monotonic_ns();cur=read(0x53bab8)
 if cur!=prev:a.append({'ns':now-start,'frame':cur});prev=cur
 time.sleep(.001)
os.close(f)
d=[(y['ns']-x['ns'])/1e6 for x,y in zip(a,a[1:]) if y['frame']==x['frame']+1]
r={'pid':pid,'address':'0x0053bab8','function':'0x00430cd0','source':'rcskspel.dat','method':'Read-only /proc/pid/mem polling every ~1 ms, monotonic clock; no target patching','durationSeconds':(time.monotonic_ns()-start)/1e9,'frames':a,'meanFrameMs':statistics.mean(d),'medianFrameMs':statistics.median(d),'minFrameMs':min(d),'maxFrameMs':max(d),'measuredFps':(a[-1]['frame']-a[0]['frame'])/((a[-1]['ns']-a[0]['ns'])/1e9),'samplingBoundMs':1.5}
p=Path('evidence/native/runtime/frame-sample.json');p.write_text(json.dumps(r,indent=2));print({k:v for k,v in r.items() if k!='frames'})
