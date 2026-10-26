/*
 * FUN_0044efe4 at 0044efe4
 * undefined __register FUN_0044efe4(int * param_1, LONG * param_2, undefined * param_3, uint param_4, int param_5, int * param_6, int * param_7, char param_8, char param_9, byte param_10)
 * Address ranges: 0044efe4-0044f257
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044efe4(int *param_1,LONG *param_2,undefined *param_3,uint param_4,int param_5,
                 int *param_6,int *param_7,char param_8,char param_9,byte param_10)

{
  uint uVar1;
  HDC pHVar2;
  LPCSTR pCVar3;
  LPCSTR lpchText;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  tagRECT *ptVar5;
  undefined4 *in_FS_OFFSET;
  uint format;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  tagRECT local_34;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined *local_c;
  int *local_8;
  
  puVar7 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  local_14 = *param_7;
  local_10 = param_7[1];
  ptVar5 = &local_34;
  for (iVar4 = 4; iVar4 != 0; iVar4 = iVar4 + -1) {
    ptVar5->left = *param_2;
    param_2 = param_2 + 1;
    ptVar5 = (tagRECT *)&ptVar5->top;
  }
  puStack_44 = (undefined1 *)0x44f017;
  local_c = param_3;
  local_8 = param_1;
  FUN_00403f84((int)param_3);
  puStack_48 = &LAB_0044f275;
  uStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_4c;
  puStack_44 = &stack0xfffffffc;
  if (param_6 != (int *)0x0) {
    local_24 = local_34.left;
    if (param_8 == '\0') {
      local_20 = 0;
      puStack_44 = &stack0xfffffffc;
    }
    else if (param_8 == '\x01') {
      puStack_44 = &stack0xfffffffc;
      iVar4 = (**(code **)(*param_6 + 0x20))();
      uVar1 = (local_34.bottom + local_34.top) - iVar4;
      local_20 = (int)uVar1 >> 1;
      if (local_20 < 0) {
        local_20 = local_20 + (uint)((uVar1 & 1) != 0);
      }
    }
    else {
      puStack_44 = &stack0xfffffffc;
      if (param_8 == '\x02') {
        puStack_44 = &stack0xfffffffc;
        local_20 = (**(code **)(*param_6 + 0x20))();
        local_20 = local_34.bottom - local_20;
      }
    }
    if (param_10 < 2) {
      FUN_0044ecb0(local_8,&local_24,param_6,&local_14,'\x01','\0');
    }
    else if (param_10 == 2) {
      FUN_0044ecb0(local_8,&local_24,param_6,&local_14,'\x01','\x01');
    }
    uVar1 = (**(code **)(*param_6 + 0x2c))();
    iVar4 = (int)uVar1 >> 1;
    if (iVar4 < 0) {
      iVar4 = iVar4 + (uint)((uVar1 & 1) != 0);
    }
    local_34.left = iVar4 + local_34.left + param_5;
  }
  uVar1 = 0;
  if ((param_4 & 8) == 0) {
    uVar1 = 0x20;
  }
  if ((param_4 & 1) != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  if ((param_4 & 2) != 0) {
    uVar1 = uVar1 | 0x4000;
  }
  if ((param_4 & 4) != 0) {
    uVar1 = uVar1 | 0x800;
  }
  if ((param_4 & 0x10) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if (param_9 != '\0') {
    if (param_9 == '\x01') {
      uVar1 = uVar1 | 1;
    }
    else if (param_9 == '\x02') {
      uVar1 = uVar1 | 2;
    }
  }
  if (param_8 != '\0') {
    if (param_8 == '\x01') {
      uVar1 = uVar1 | 4;
    }
    else if (param_8 == '\x02') {
      uVar1 = uVar1 | 8;
    }
  }
  local_18 = *(int *)(local_8[3] + 0x18);
  iVar4 = 1;
  pHVar2 = (HDC)FUN_00418994(local_8);
  local_1c = SetBkMode(pHVar2,iVar4);
  uVar6 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffa8;
  if (param_10 == 0) {
    ptVar5 = &local_34;
    iVar4 = -1;
    pCVar3 = FUN_00403f94(local_c);
    pHVar2 = (HDC)FUN_00418994(local_8);
    DrawTextA(pHVar2,pCVar3,iVar4,ptVar5,uVar1);
    puVar10 = puVar7;
  }
  else if (param_10 == 1) {
    FUN_004176d0((int *)local_8[3],local_14,extraout_ECX);
    ptVar5 = &local_34;
    iVar4 = -1;
    pCVar3 = FUN_00403f94(local_c);
    pHVar2 = (HDC)FUN_00418994(local_8);
    DrawTextA(pHVar2,pCVar3,iVar4,ptVar5,uVar1);
    puVar10 = puVar8;
  }
  else if (param_10 == 2) {
    OffsetRect(&local_34,1,1);
    FUN_004176d0((int *)local_8[3],local_10,extraout_ECX_00);
    ptVar5 = &local_34;
    iVar4 = -1;
    format = uVar1;
    lpchText = FUN_00403f94(local_c);
    pCVar3 = lpchText;
    pHVar2 = (HDC)FUN_00418994(local_8);
    DrawTextA(pHVar2,pCVar3,iVar4,ptVar5,format);
    OffsetRect(&local_34,-1,-1);
    FUN_004176d0((int *)local_8[3],local_14,extraout_ECX_01);
    ptVar5 = &local_34;
    iVar4 = -1;
    pHVar2 = (HDC)FUN_00418994(local_8);
    DrawTextA(pHVar2,lpchText,iVar4,ptVar5,uVar1);
    puVar10 = puVar9;
  }
  *in_FS_OFFSET = uVar6;
  FUN_004176d0((int *)local_8[3],local_18,puVar10);
  iVar4 = local_1c;
  pHVar2 = (HDC)FUN_00418994(local_8);
  SetBkMode(pHVar2,iVar4);
  return;
}

