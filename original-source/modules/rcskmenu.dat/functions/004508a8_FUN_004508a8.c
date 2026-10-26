/*
 * FUN_004508a8 at 004508a8
 * undefined __register FUN_004508a8(int * param_1, int param_2, undefined4 param_3, char param_4, char param_5, undefined4 * param_6, int * param_7, int param_8)
 * Address ranges: 004508a8-00450da0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004508a8(int *param_1,int param_2,undefined4 param_3,char param_4,char param_5,
                 undefined4 *param_6,int *param_7,int param_8)

{
  bool bVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  HDC hdc;
  HBITMAP pHVar7;
  HGDIOBJ pvVar8;
  int iVar9;
  undefined4 *unaff_EBX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  int *piVar10;
  undefined4 *in_FS_OFFSET;
  byte bVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  undefined *in_stack_ffffffd0;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  
  bVar11 = 0;
  local_20 = (undefined4 *)&stack0xfffffffc;
  iVar9 = 6;
  do {
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  LOCK();
  UNLOCK();
  local_24 = (undefined4 *)&LAB_00450da1;
  local_28 = (undefined4 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_28;
  FUN_004507f8(param_1,-1,0);
  if (param_8 < 0x11) {
    if (param_8 == 0x10) {
      if ((((*param_7 != 0x7c00) || (param_7[1] != 0x3e0)) || (param_7[2] != 0x1f)) &&
         (((*param_7 != 0xf800 || (param_7[1] != 0x7e0)) || (param_7[2] != 0x1f)))) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c6b0,(int *)&local_20);
        piVar3 = FUN_0040ac64((int *)&DAT_00415c50,'\x01',local_20);
        FUN_00403604(piVar3);
      }
      goto LAB_00450af2;
    }
    if (param_8 == 1) {
      if (((*param_7 != 0xff0000) || (param_7[1] != 0xff00)) || (param_7[2] != 0xff)) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c6b0,(int *)&stack0xffffffec);
        piVar3 = FUN_0040ac64((int *)&DAT_00415c50,'\x01',unaff_EBX);
        FUN_00403604(piVar3);
      }
      goto LAB_00450af2;
    }
    if (param_8 == 4) {
      if (((*param_7 != 0xff0000) || (param_7[1] != 0xff00)) || (param_7[2] != 0xff)) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c6b0,(int *)&stack0xffffffe8);
        piVar3 = FUN_0040ac64((int *)&DAT_00415c50,'\x01',unaff_ESI);
        FUN_00403604(piVar3);
      }
      goto LAB_00450af2;
    }
    if (param_8 == 8) {
      if (((*param_7 != 0xff0000) || (param_7[1] != 0xff00)) || (param_7[2] != 0xff)) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c6b0,(int *)&stack0xffffffe4);
        piVar3 = FUN_0040ac64((int *)&DAT_00415c50,'\x01',unaff_EDI);
        FUN_00403604(piVar3);
      }
      goto LAB_00450af2;
    }
  }
  else {
    if (param_8 == 0x18) {
      if (((*param_7 != 0xff0000) || (param_7[1] != 0xff00)) || (param_7[2] != 0xff)) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c6b0,(int *)&local_24);
        piVar3 = FUN_0040ac64((int *)&DAT_00415c50,'\x01',local_24);
        FUN_00403604(piVar3);
      }
      goto LAB_00450af2;
    }
    if (param_8 == 0x20) {
      if (((*param_7 != 0xff0000) || (param_7[1] != 0xff00)) || (param_7[2] != 0xff)) {
        FUN_00405438((undefined4 *)PTR_PTR_0047c6b0,(int *)&local_28);
        piVar3 = FUN_0040ac64((int *)&DAT_00415c50,'\x01',local_28);
        FUN_00403604(piVar3);
      }
      goto LAB_00450af2;
    }
  }
  puVar13 = &stack0xffffffd0;
  in_stack_ffffffd0 = (undefined *)0x0;
  pbVar12 = (byte *)0x450ade;
  FUN_00405438((undefined4 *)PTR_PTR_0047c6ac,(int *)&stack0xffffffcc);
  uVar4 = FUN_0040aca0((int)&DAT_00415c50,'\x01',pbVar12,in_stack_ffffffd0,puVar13);
  FUN_00403604(uVar4);
LAB_00450af2:
  param_1[2] = param_8;
  param_1[0x10a] = 0;
  param_1[0x11f] = param_2;
  uVar5 = param_2 * param_8 + 0x1fU >> 5;
  param_1[0x120] = uVar5 * 4;
  param_1[0x10c] = uVar5 * -4;
  param_1[0x11d] = param_1[0x120] * param_1[0x10a];
  if ((param_8 == 0x10) || (param_8 == 0x20)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  piVar3 = param_7;
  piVar10 = param_1 + 0x111;
  for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar10 = *piVar3;
    piVar3 = piVar3 + (uint)bVar11 * -2 + 1;
    piVar10 = piVar10 + (uint)bVar11 * -2 + 1;
  }
  param_1[0x10f] = 0;
  if (param_1[2] < 9) {
    param_1[0x10f] = 1 << ((byte)param_1[2] & 0x1f);
  }
  param_1[4] = 0x28;
  if (bVar1) {
    param_1[4] = param_1[4] + 0xc;
  }
  param_1[4] = param_1[4] + param_1[0x10f] * 4;
  puVar6 = (undefined4 *)FUN_00402714(param_1[4]);
  param_1[3] = (int)puVar6;
  FUN_00402b54(puVar6,param_1[4],0);
  puVar6 = (undefined4 *)param_1[3];
  *puVar6 = 0x28;
  puVar6[1] = param_1[0x11f];
  puVar6[2] = param_1[0x10a];
  *(undefined2 *)(puVar6 + 3) = 1;
  *(short *)((int)puVar6 + 0xe) = (short)param_1[2];
  if (bVar1) {
    puVar6[4] = 3;
  }
  else if ((param_1[2] == 4) && (param_4 != '\0')) {
    puVar6[4] = 2;
  }
  else if ((param_1[2] == 8) && (param_4 != '\0')) {
    puVar6[4] = 1;
  }
  else {
    puVar6[4] = 0;
  }
  puVar6[5] = param_1[0x11d];
  puVar6[6] = 0;
  puVar6[7] = 0;
  puVar6[8] = 0;
  puVar6[9] = 0;
  iVar9 = 0x28;
  if (bVar1) {
    iVar9 = param_1[3];
    *(int *)(iVar9 + 0x28) = *param_7;
    *(int *)(iVar9 + 0x2c) = param_7[1];
    *(int *)(iVar9 + 0x30) = param_7[2];
    iVar9 = 0x34;
  }
  param_1[0x106] = iVar9;
  puVar6 = (undefined4 *)((int)param_1 + 0x15);
  for (iVar9 = 0x100; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar6 = *param_6;
    param_6 = param_6 + (uint)bVar11 * -2 + 1;
    puVar6 = puVar6 + (uint)bVar11 * -2 + 1;
  }
  FUN_0040282c((undefined4 *)((int)param_1 + 0x15),(undefined4 *)(param_1[3] + param_1[0x106]),
               param_1[0x10f] << 2);
  *(bool *)(param_1 + 0x107) = *(int *)(param_1[3] + 0x10) - 1U < 2;
  if ((param_5 == '\0') && ((char)param_1[0x107] == '\0')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(undefined1 *)(param_1 + 0x10b) = uVar2;
  if (param_4 == '\0') {
    if (param_5 == '\0') {
      hdc = CreateCompatibleDC((HDC)0x0);
      param_1[0x108] = (int)hdc;
      pHVar7 = CreateDIBSection(hdc,(BITMAPINFO *)param_1[3],0,(void **)(param_1 + 0x110),
                                (HANDLE)0x0,0);
      param_1[0x109] = (int)pHVar7;
      if (pHVar7 == (HBITMAP)0x0) {
        in_stack_ffffffd0 = &DAT_00450dbc;
        puVar13 = &stack0xffffffd0;
        pbVar12 = (byte *)0x0;
        FUN_00405438((undefined4 *)PTR_PTR_0047c894,(int *)&stack0xffffffc8);
        uVar4 = FUN_0040aca0((int)&DAT_0040ddb0,'\x01',pbVar12,pbVar12,puVar13);
        FUN_00403604(uVar4);
      }
      pvVar8 = SelectObject((HDC)param_1[0x108],(HGDIOBJ)param_1[0x109]);
      param_1[0x10d] = (int)pvVar8;
    }
    else {
      iVar9 = FUN_00402714(param_1[0x11d]);
      param_1[0x110] = iVar9;
      if (iVar9 == 0) {
        FUN_0040ac58();
      }
    }
  }
  param_1[0x11e] = (param_1[0x10a] + -1) * param_1[0x120] + param_1[0x110];
  *in_FS_OFFSET = in_stack_ffffffd0;
  local_28 = (undefined4 *)&LAB_00450da8;
  FUN_00403b74((int *)&stack0xffffffc8,2);
  FUN_00403b74((int *)&local_28,6);
  return;
}

