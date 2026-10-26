/*
 * FUN_004739c0 at 004739c0
 * undefined FUN_004739c0(void)
 * Address ranges: 004739c0-00473bdc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004739c0(int *param_1)

{
  int iVar1;
  POINT pt;
  POINT pt_00;
  bool bVar2;
  int iVar3;
  LONG *pLVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  BOOL BVar9;
  undefined4 uVar10;
  LONG local_3c;
  LONG local_38;
  undefined1 local_34 [4];
  RECT local_30;
  RECT local_20;
  LONG local_10;
  LONG local_c;
  
  if (DAT_006abae0 != 0) {
    FUN_004b6120(2,1,0,0,0x280,0x1e0,0,0,DAT_004fe930,DAT_004fe934,4);
  }
  FUN_004b9ea0(&local_3c,&local_38,local_34);
  iVar3 = FUN_00473be0(1);
  uVar10 = 3;
  *param_1 = iVar3;
  FUN_004707f0(3);
  pLVar4 = (LONG *)FUN_004715a0(uVar10);
  local_10 = *pLVar4;
  uVar10 = 3;
  FUN_004707f0(3);
  iVar3 = FUN_004715a0(uVar10);
  local_c = *(LONG *)(iVar3 + 4);
  uVar10 = 3;
  FUN_004707f0(3);
  piVar5 = (int *)FUN_004715a0(uVar10);
  uVar10 = 3;
  FUN_004707f0(3);
  piVar6 = (int *)FUN_00471560(uVar10);
  iVar3 = *piVar6;
  iVar1 = *piVar5;
  uVar10 = 3;
  FUN_004707f0(3);
  iVar7 = FUN_004715a0(uVar10);
  uVar10 = 3;
  FUN_004707f0(3);
  iVar8 = FUN_00471560(uVar10);
  local_30.bottom = *(int *)(iVar7 + 4) + *(int *)(iVar8 + 4);
  uVar10 = 1;
  local_30.left = local_10;
  local_30.top = local_c;
  local_30.right = iVar3 + iVar1;
  FUN_004707f0(1);
  pLVar4 = (LONG *)FUN_004715a0(uVar10);
  local_10 = *pLVar4;
  uVar10 = 1;
  FUN_004707f0(1);
  iVar3 = FUN_004715a0(uVar10);
  local_c = *(LONG *)(iVar3 + 4);
  uVar10 = 1;
  FUN_004707f0(1);
  piVar5 = (int *)FUN_004715a0(uVar10);
  uVar10 = 1;
  FUN_004707f0(1);
  piVar6 = (int *)FUN_00471560(uVar10);
  iVar3 = *piVar6;
  iVar1 = *piVar5;
  uVar10 = 1;
  FUN_004707f0(1);
  iVar7 = FUN_004715a0(uVar10);
  uVar10 = 1;
  FUN_004707f0(1);
  iVar8 = FUN_00471560(uVar10);
  local_20.left = local_10;
  local_20.bottom = *(int *)(iVar7 + 4) + *(int *)(iVar8 + 4);
  local_20.top = local_c;
  pt.y = local_38;
  pt.x = local_3c;
  local_20.right = iVar3 + iVar1;
  BVar9 = PtInRect(&local_30,pt);
  if (BVar9 == 0) {
    pt_00.y = local_38;
    pt_00.x = local_3c;
    BVar9 = PtInRect(&local_20,pt_00);
    if (BVar9 == 0) {
      bVar2 = false;
    }
    else {
      *param_1 = 5;
      bVar2 = true;
    }
  }
  else {
    bVar2 = true;
    *param_1 = 8;
  }
  if ((*param_1 == 5) || (*param_1 == 8)) {
    FUN_004707f0();
    if (*param_1 == 5) {
      uVar10 = 2;
    }
    else {
      uVar10 = 4;
    }
    FUN_004715e0(1,uVar10,9);
    if (bVar2) {
      if (*param_1 == 5) {
        uVar10 = 6;
      }
      else {
        uVar10 = 9;
      }
      FUN_004715e0(1,uVar10,9);
    }
  }
  FUN_00471d10(1);
  return;
}

