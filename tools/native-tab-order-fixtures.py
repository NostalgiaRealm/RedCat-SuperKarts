#!/usr/bin/env python3
"""Run original441980 Loaded/4458dc SetTabOrder for shipped form siblings.
TList allocation/index/get/set/insert/delete are explicit container boundaries;
native traversal, target-index selection and move order run original code.
"""
import json,hashlib,pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
p=NativeProbe(SOURCE);binary=SOURCE/'rcskmenu.dat';p.uc.mem_write(0x400000,pefile.PE(str(binary)).get_memory_mapped_image());p.uc.mem_map(0,0x1000)
parent,children,order,temp=[SCRATCH+i*0x1000 for i in range(1,5)]
p.u32(parent+0x180,children);p.u32(parent+0x16c,order);lists={}
def ret(value=None):
 if value is not None:p.uc.reg_write(UC_X86_REG_EAX,value&0xffffffff)
 sp=p.uc.reg_read(UC_X86_REG_ESP);p.uc.reg_write(UC_X86_REG_ESP,sp+4);p.uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
def hook(uc,address,size,unused):
 eax=uc.reg_read(UC_X86_REG_EAX);edx=uc.reg_read(UC_X86_REG_EDX);ecx=uc.reg_read(UC_X86_REG_ECX)
 if address==0x402e7c:ret(temp)
 elif address==0x402eac:ret()
 elif address==0x40f8a4:lists[eax]=[0]*edx;p.u32(eax+8,edx);ret()
 elif address==0x40f6b0:ret(lists[eax][edx])
 elif address==0x40f7fc:lists[eax][edx]=ecx;ret()
 elif address==0x40f70c:ret(lists[eax].index(edx) if edx in lists[eax] else -1)
 elif address==0x40f550:lists[eax].pop(edx);p.u32(eax+8,len(lists[eax]));ret()
 elif address==0x40f72c:lists[eax].insert(edx,ecx);p.u32(eax+8,len(lists[eax]));ret()
p.uc.hook_add(UC_HOOK_CODE,hook)
classes={'TDaviGraphicButton','TDaviGraphicRadioButton','TDaviGraphicCheckBox','TDaviGraphicSlider','TDaviEdit2','TEdit','TButton','TCheckBox','TDaviRadioButton','TComboBox','TTransparentControl','TPanel','TGroupBox','TDaviPageControl','TTabSheet'}
report={'scope':__doc__,'sourceSha256':hashlib.sha256(binary.read_bytes()).hexdigest(),'cases':[]}
def visit(form,item):
 records=[child for child in item['children'] if child['class'] in classes]
 if records:
  objects=[SCRATCH+0x5000+i*0x300 for i in range(len(records))]
  for obj,record in zip(objects,records):p.u32(obj+0x24,parent);p.u32(obj+0x170,record['properties'].get('TabOrder',-1)&0xffffffff)
  lists[children]=objects.copy();lists[order]=objects.copy();p.u32(children+8,len(objects));p.u32(order+8,len(objects))
  p.uc.reg_write(UC_X86_REG_EAX,parent);p.run(0x441980)
  report['cases'].append({'form':form,'parent':item['name'],'input':[{'name':r['name'],'tabOrder':r['properties'].get('TabOrder',-1)} for r in records],
   'output':[records[objects.index(obj)]['name'] for obj in lists[order]]})
 for child in item['children']:visit(form,child)
for name,form in json.loads((ROOT/'public/assets/ui/forms.json').read_text()).items():visit(name,form)
(ROOT/'evidence/native/tab-order-fixtures.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({'nativeParentLists':len(report['cases'])}))
