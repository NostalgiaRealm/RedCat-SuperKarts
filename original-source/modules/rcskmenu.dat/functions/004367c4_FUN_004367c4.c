/*
 * FUN_004367c4 at 004367c4
 * undefined __register FUN_004367c4(int param_1, int * param_2, int param_3, uint param_4, char param_5, LPRECT param_6)
 * Address ranges: 004367c4-004369aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00436810) */
/* WARNING: Removing unreachable block (ram,0x0043681a) */

void FUN_004367c4(int param_1,int *param_2,int param_3,uint param_4,char param_5,LPRECT param_6)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  HDC pHVar5;
  LPCSTR pCVar6;
  int iVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  tagRECT *ptVar8;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar9;
  UINT edge;
  LPRECT lprc;
  UINT grfFlags;
  uint format;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  tagRECT local_20;
  uint *local_10;
  int local_c;
  int *local_8;
  
  bVar2 = 0;
  puStack_30 = &stack0xfffffffc;
  local_10 = (uint *)0x0;
  puStack_34 = &LAB_004369ab;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  local_c = param_3;
  local_8 = param_2;
  iVar3 = thunk_FUN_004385f4(param_1);
  if ((iVar3 != 0) && (uVar4 = FUN_00439ae8(iVar3), (char)uVar4 != '\0')) {
    param_4 = param_4 | 0x20002;
  }
  FUN_00403be8((int *)&local_10,local_c);
  uVar9 = (param_4 & 0x400) == 0;
  if ((!(bool)uVar9) &&
     ((uVar9 = true, local_10 == (uint *)0x0 ||
      ((uVar9 = 0, (char)*local_10 == '&' &&
       (uVar9 = *(char *)((int)local_10 + 1) == '\0', (bool)uVar9)))))) {
    FUN_00403dd8((int *)&local_10,(undefined4 *)&DAT_004369c4);
  }
  FUN_00403ee0(local_10,(uint *)&DAT_004369d0);
  if ((bool)uVar9) {
    if ((param_4 & 0x400) == 0) {
      ptVar8 = &local_20;
      for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
        ptVar8->left = param_6->left;
        param_6 = (LPRECT)((int)param_6 + (uint)bVar2 * -8 + 4);
        ptVar8 = (tagRECT *)((int)ptVar8 + ((uint)bVar2 * -2 + 1) * 4);
      }
      local_20.top = local_20.top + 4;
      grfFlags = 2;
      edge = 6;
      ptVar8 = &local_20;
      pHVar5 = (HDC)FUN_00418994(local_8);
      DrawEdge(pHVar5,ptVar8,edge,grfFlags);
    }
    goto LAB_00436995;
  }
  FUN_00417fbc((int *)local_8[5],'\x01');
  if (*(char *)(param_1 + 0x2e) != '\0') {
    piVar1 = (int *)local_8[3];
    bVar2 = FUN_00417990((int)piVar1);
    FUN_0041799c(piVar1,bVar2 | 1);
  }
  if (*(char *)(param_1 + 0x2d) == '\0') {
    if (param_5 == '\0') {
      OffsetRect(param_6,1,1);
      FUN_004176d0((int *)local_8[3],-0x7fffffec,extraout_ECX);
      lprc = param_6;
      format = param_4;
      iVar3 = FUN_00403dd0((int)local_10);
      pCVar6 = FUN_00403f94((undefined *)local_10);
      pHVar5 = (HDC)FUN_00418994(local_8);
      DrawTextA(pHVar5,pCVar6,iVar3,lprc,format);
      OffsetRect(param_6,-1,-1);
      uVar4 = extraout_ECX_00;
    }
    else {
      iVar3 = FUN_00417210(0x8000000d);
      iVar7 = FUN_00417210(0x80000010);
      uVar4 = extraout_ECX_01;
      if (iVar3 == iVar7) {
        FUN_004176d0((int *)local_8[3],-0x7fffffec,extraout_ECX_01);
        goto LAB_00436970;
      }
    }
    FUN_004176d0((int *)local_8[3],-0x7ffffff0,uVar4);
  }
LAB_00436970:
  iVar3 = FUN_00403dd0((int)local_10);
  pCVar6 = FUN_00403f94((undefined *)local_10);
  pHVar5 = (HDC)FUN_00418994(local_8);
  DrawTextA(pHVar5,pCVar6,iVar3,param_6,param_4);
LAB_00436995:
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_004369b2;
  puStack_34 = (undefined1 *)0x4369aa;
  FUN_00403b50((int *)&local_10);
  return;
}

