/*
 * FUN_0041b6e6 at 0041b6e6
 * undefined __cdecl FUN_0041b6e6(int param_1)
 * Address ranges: 0041b6e6-0041b884
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041b6e6(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar2 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  iVar3 = piVar1[4] / 2;
  iVar4 = piVar1[5] / 2;
  iVar5 = FUN_00412687(*piVar1,*(int *)(DAT_0043d858 + *piVar1 * 0xc) + -1);
  uVar9 = 1;
  iVar6 = FUN_00412a49(iVar2);
  iVar6 = iVar6 + iVar4;
  iVar7 = FUN_004129f6(iVar2);
  iVar7 = iVar7 + iVar3;
  iVar8 = FUN_00412061();
  FUN_004105ee(iVar8,iVar5,iVar7,iVar6,uVar9);
  iVar5 = FUN_0041294e(iVar2);
  if ((iVar5 == 1) || (iVar5 == 4)) {
    iVar5 = FUN_00412687(piVar1[3],*(int *)(DAT_0043d858 + piVar1[3] * 0xc) + -1);
    uVar9 = 1;
    iVar6 = FUN_00412a49(iVar2);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar2);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar9);
  }
  else {
    iVar5 = FUN_00412687(*piVar1,*(int *)(DAT_0043d858 + *piVar1 * 0xc) + -1);
    uVar9 = 1;
    iVar6 = FUN_00412a49(iVar2);
    iVar6 = iVar6 + iVar4;
    iVar4 = FUN_004129f6(iVar2);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00412061();
    FUN_004105ee(iVar3,iVar5,iVar4,iVar6,uVar9);
  }
  if (piVar1[8] != 0) {
    FUN_0041258a(iVar2,piVar1[9],piVar1[10],piVar1[10],piVar1[0xb]);
  }
  return;
}

