/*
 * FUN_00474040 at 00474040
 * undefined FUN_00474040(void)
 * Address ranges: 00474040-004743a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00474040(void)

{
  int iVar1;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  LONG LVar2;
  LONG LVar3;
  int iVar4;
  LONG *pLVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  BOOL BVar10;
  undefined4 uVar11;
  uint local_2c;
  LONG local_28;
  LONG local_24;
  RECT local_20;
  LONG local_10;
  LONG local_c;
  
  FUN_00473d40();
  iVar4 = FUN_004b3830(0x4a);
  if (iVar4 != 0) {
    FUN_004743b0(0x4a);
    return 0;
  }
  iVar4 = FUN_004b3830(0x4e);
  if (iVar4 != 0) {
    FUN_004743b0(0x4e);
    return 1;
  }
  iVar4 = FUN_004b3830(0x1b);
  if (iVar4 != 0) {
    FUN_004743b0(0x1b);
    return 1;
  }
  local_28 = 0;
  local_24 = 0;
  local_2c = 0;
  FUN_004b9ea0(&local_28,&local_24,&local_2c);
  LVar3 = local_24;
  LVar2 = local_28;
  if ((local_2c & 1) != 0) {
    uVar11 = 8;
    FUN_004707f0(8);
    pLVar5 = (LONG *)FUN_004715a0(uVar11);
    local_10 = *pLVar5;
    uVar11 = 8;
    FUN_004707f0(8);
    iVar4 = FUN_004715a0(uVar11);
    local_c = *(LONG *)(iVar4 + 4);
    uVar11 = 8;
    FUN_004707f0(8);
    piVar6 = (int *)FUN_004715a0(uVar11);
    uVar11 = 8;
    FUN_004707f0(8);
    piVar7 = (int *)FUN_00471560(uVar11);
    iVar4 = *piVar7;
    iVar1 = *piVar6;
    uVar11 = 8;
    FUN_004707f0(8);
    iVar8 = FUN_004715a0(uVar11);
    uVar11 = 8;
    FUN_004707f0(8);
    iVar9 = FUN_00471560(uVar11);
    local_20.bottom = *(int *)(iVar8 + 4) + *(int *)(iVar9 + 4);
    local_20.left = local_10;
    local_20.top = local_c;
    pt.y = LVar3;
    pt.x = LVar2;
    local_20.right = iVar4 + iVar1;
    BVar10 = PtInRect(&local_20,pt);
    if (BVar10 != 0) {
      return 1;
    }
    uVar11 = 5;
    FUN_004707f0(5);
    pLVar5 = (LONG *)FUN_004715a0(uVar11);
    local_10 = *pLVar5;
    uVar11 = 5;
    FUN_004707f0(5);
    iVar4 = FUN_004715a0(uVar11);
    local_c = *(LONG *)(iVar4 + 4);
    uVar11 = 5;
    FUN_004707f0(5);
    piVar6 = (int *)FUN_004715a0(uVar11);
    uVar11 = 5;
    FUN_004707f0(5);
    piVar7 = (int *)FUN_00471560(uVar11);
    iVar4 = *piVar7;
    iVar1 = *piVar6;
    uVar11 = 5;
    FUN_004707f0(5);
    iVar8 = FUN_004715a0(uVar11);
    uVar11 = 5;
    FUN_004707f0(5);
    iVar9 = FUN_00471560(uVar11);
    local_20.bottom = *(int *)(iVar8 + 4) + *(int *)(iVar9 + 4);
    local_20.left = local_10;
    local_20.top = local_c;
    pt_00.y = LVar3;
    pt_00.x = LVar2;
    local_20.right = iVar4 + iVar1;
    BVar10 = PtInRect(&local_20,pt_00);
    if (BVar10 != 0) {
      return 0;
    }
    uVar11 = 1;
    FUN_004707f0(1);
    pLVar5 = (LONG *)FUN_004715a0(uVar11);
    local_10 = *pLVar5;
    uVar11 = 1;
    FUN_004707f0(1);
    iVar4 = FUN_004715a0(uVar11);
    local_c = *(LONG *)(iVar4 + 4);
    uVar11 = 1;
    FUN_004707f0(1);
    piVar6 = (int *)FUN_004715a0(uVar11);
    uVar11 = 1;
    FUN_004707f0(1);
    piVar7 = (int *)FUN_00471560(uVar11);
    iVar4 = *piVar7;
    iVar1 = *piVar6;
    uVar11 = 1;
    FUN_004707f0(1);
    iVar8 = FUN_004715a0(uVar11);
    uVar11 = 1;
    FUN_004707f0(1);
    iVar9 = FUN_00471560(uVar11);
    local_20.bottom = *(int *)(iVar8 + 4) + *(int *)(iVar9 + 4);
    local_20.left = local_10;
    local_20.top = local_c;
    pt_01.y = LVar3;
    pt_01.x = LVar2;
    local_20.right = iVar4 + iVar1;
    BVar10 = PtInRect(&local_20,pt_01);
    if (BVar10 != 0) {
      return 2;
    }
    uVar11 = 3;
    FUN_004707f0(3);
    pLVar5 = (LONG *)FUN_004715a0(uVar11);
    local_10 = *pLVar5;
    uVar11 = 3;
    FUN_004707f0(3);
    iVar4 = FUN_004715a0(uVar11);
    local_c = *(LONG *)(iVar4 + 4);
    uVar11 = 3;
    FUN_004707f0(3);
    piVar6 = (int *)FUN_004715a0(uVar11);
    uVar11 = 3;
    FUN_004707f0(3);
    piVar7 = (int *)FUN_00471560(uVar11);
    iVar4 = *piVar7;
    iVar1 = *piVar6;
    uVar11 = 3;
    FUN_004707f0(3);
    iVar8 = FUN_004715a0(uVar11);
    uVar11 = 3;
    FUN_004707f0(3);
    iVar9 = FUN_00471560(uVar11);
    local_20.bottom = *(int *)(iVar8 + 4) + *(int *)(iVar9 + 4);
    local_20.left = local_10;
    local_20.top = local_c;
    pt_02.y = LVar3;
    pt_02.x = LVar2;
    local_20.right = iVar4 + iVar1;
    BVar10 = PtInRect(&local_20,pt_02);
    if (BVar10 != 0) {
      return 3;
    }
  }
  return 0xffffffff;
}

