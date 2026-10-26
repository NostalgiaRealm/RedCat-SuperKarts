/*
 * FUN_0041ae68 at 0041ae68
 * undefined __cdecl FUN_0041ae68(int param_1)
 * Address ranges: 0041ae68-0041af20
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041ae68(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar2 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  iVar6 = piVar1[1];
  iVar5 = piVar1[2];
  iVar3 = FUN_00412687(*piVar1,0);
  uVar7 = 1;
  iVar4 = FUN_00412a49(iVar2);
  iVar4 = iVar4 + iVar5 / 2;
  iVar5 = FUN_004129f6(iVar2);
  iVar5 = iVar5 + iVar6 / 2;
  iVar6 = FUN_00412061();
  FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar7);
  if (piVar1[4] != 0) {
    FUN_0041258a(iVar2,piVar1[5],piVar1[6],piVar1[6],piVar1[7]);
  }
  return;
}

