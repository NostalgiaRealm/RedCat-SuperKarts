/*
 * FUN_0041c516 at 0041c516
 * undefined __cdecl FUN_0041c516(int param_1)
 * Address ranges: 0041c516-0041c5f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041c516(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar3 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  iVar2 = piVar1[4];
  iVar7 = piVar1[1];
  iVar6 = piVar1[2];
  iVar4 = FUN_00412687(*piVar1,iVar2 << 1);
  uVar8 = 1;
  iVar5 = FUN_00412a49(iVar3);
  iVar5 = iVar5 + iVar6 / 2;
  iVar6 = FUN_004129f6(iVar3);
  iVar6 = iVar6 + iVar7 / 2;
  iVar7 = FUN_00412061();
  FUN_004105ee(iVar7,iVar4,iVar6,iVar5,uVar8);
  if ((piVar1[5] != 0) && (*(int *)(piVar1[5] + iVar2 * 4) != 0)) {
    FUN_00412618(iVar3,*(byte **)(piVar1[5] + iVar2 * 4),piVar1[6],piVar1[7],piVar1[7],piVar1[8]);
  }
  return;
}

