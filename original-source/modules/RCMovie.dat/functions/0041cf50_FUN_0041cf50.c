/*
 * FUN_0041cf50 at 0041cf50
 * undefined __cdecl FUN_0041cf50(int param_1)
 * Address ranges: 0041cf50-0041d1f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041cf50(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_8;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x14));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x14));
  iVar3 = piVar2[1] / 2;
  iVar4 = piVar2[2] / 2;
  if (iVar1 == -1) {
    FUN_0040187a((byte *)s__s__d_____draw_button__no_valid_w_00436d58);
  }
  FUN_00404a0d();
  iVar8 = *(int *)(param_1 + 0x10);
  if (iVar8 == 4) {
    FUN_00411de7(iVar1,2);
    if (piVar2[4] == 0) {
      local_8 = FUN_00412687(*piVar2,2);
    }
    else {
      local_8 = FUN_00412687(*piVar2,0);
    }
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else if (iVar8 == 0x10) {
    FUN_00411de7(iVar1,1);
    local_8 = FUN_00412687(*piVar2,3);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else if (iVar8 == 0x11) {
    FUN_00411de7(iVar1,4);
    local_8 = FUN_00412687(*piVar2,1);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  else {
    FUN_00411de7(iVar1,0);
    local_8 = FUN_00412687(*piVar2,0);
    uVar9 = 1;
    iVar5 = FUN_00412a49(iVar1);
    iVar5 = iVar5 + iVar4;
    iVar6 = FUN_004129f6(iVar1);
    iVar6 = iVar6 + iVar3;
    iVar8 = local_8;
    iVar7 = FUN_00412061();
    FUN_004105ee(iVar7,iVar8,iVar6,iVar5,uVar9);
  }
  if (piVar2[4] != 0) {
    FUN_0041258a(iVar1,piVar2[5],piVar2[6],piVar2[6],piVar2[7]);
  }
  if (*(int *)(param_1 + 0x10) == 4) {
    if (piVar2[4] != 0) {
      local_8 = FUN_00412687(*piVar2,2);
    }
    uVar9 = 1;
    iVar8 = FUN_00412a49(iVar1);
    iVar8 = iVar8 + iVar4;
    iVar1 = FUN_004129f6(iVar1);
    iVar1 = iVar1 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,local_8,iVar1,iVar8,uVar9);
  }
  FUN_00404a81();
  return;
}

