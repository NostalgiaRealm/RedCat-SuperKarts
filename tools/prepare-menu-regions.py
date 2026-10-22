#!/usr/bin/env python3
"""Export original Delphi RegionLink bitmap regions (RGB zero is outside)."""
import argparse
import hashlib
import json
from pathlib import Path
from PIL import Image

ROOT=Path(__file__).resolve().parents[1]

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--source',type=Path,default=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data'))
    p.add_argument('--forms',type=Path,default=ROOT/'public/assets/ui/forms.json')
    p.add_argument('--output',type=Path,default=ROOT/'public/assets')
    a=p.parse_args()
    forms=json.loads(a.forms.read_text());references={}
    def walk(form,node):
        name=node['properties'].get('RegionLink.Filename','').replace('(IMAGEBASE)','').lower()
        if name:references.setdefault(name,[]).append({'form':form,'definition':node['name']})
        for child in node.get('children',[]):walk(form,child)
    for form,node in forms.items():walk(form,node)
    source={f.name.lower():f for f in (a.source/'gfx').iterdir() if f.is_file()}
    regions={}
    for name,refs in references.items():
        original=source[name];im=Image.open(original).convert('RGB')
        pixels=list(im.getdata());rows=[];rectangles=[];active={}
        for y in range(im.height):
            spans=[];x=0
            while x<im.width:
                if pixels[y*im.width+x]==(0,0,0):x+=1;continue
                begin=x
                while x<im.width and pixels[y*im.width+x]!=(0,0,0):x+=1
                spans.append((begin,x))
            rows.append(spans);next_active={}
            for begin,end in spans:
                if (begin,end) in active:
                    rect=active[begin,end];rect[3]+=1
                else:
                    rect=[begin,y,end-begin,1];rectangles.append(rect)
                next_active[begin,end]=rect
            active=next_active
        # Independent pixel reconstruction ensures merging did not include gaps.
        restored=set()
        for x,y,w,h in rectangles:
            restored.update((xx,yy) for yy in range(y,y+h) for xx in range(x,x+w))
        expected={(x,y) for y in range(im.height) for x in range(im.width) if pixels[y*im.width+x]!=(0,0,0)}
        if restored!=expected:raise ValueError(f'Region pixel coverage changed: {name}')
        regions[name]={'width':im.width,'height':im.height,'rectangles':rectangles,
            'solidPixels':len(expected),'transparentRGB':[0,0,0],
            'sha256':hashlib.sha256(original.read_bytes()).hexdigest(),
            'source':str(original),'references':refs,
            'nativeFunctions':['0045348c','00453170','0045312c','0045e1c8']}
    manifest_path=a.output/'manifest.json';manifest=json.loads(manifest_path.read_text())
    menu_by_lower={name.lower():name for name in manifest['menu']}
    for name,region in regions.items():manifest['menu'][menu_by_lower[name]]['region']=region
    for path,data in [(manifest_path,manifest),(a.output/'menu/manifest.json',manifest['menu']),
                      (a.output/'ui/regions.json',{'regions':regions})]:
        path.parent.mkdir(parents=True,exist_ok=True)
        path.write_text(json.dumps(data,separators=(',',':'),ensure_ascii=False)+'\n')
    print(f'Exported {len(regions)} original regions; {sum(r["solidPixels"] for r in regions.values())} active pixels verified')

if __name__=='__main__':main()
