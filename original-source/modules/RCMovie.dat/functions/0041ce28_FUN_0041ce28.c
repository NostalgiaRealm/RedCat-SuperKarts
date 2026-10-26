/*
 * FUN_0041ce28 at 0041ce28
 * undefined __cdecl FUN_0041ce28(int param_1)
 * Address ranges: 0041ce28-0041cf4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041ce28(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = FUN_00412a9d(*(int *)(param_1 + 0x18));
  piVar2 = (int *)FUN_00412b01(*(int *)(param_1 + 0x18));
  iVar6 = piVar2[1];
  iVar5 = piVar2[2];
  iVar3 = FUN_0041294e(iVar1);
  if ((iVar3 == 1) || (iVar3 == 4)) {
    iVar3 = FUN_00412687(*piVar2,1);
    uVar7 = 1;
    iVar4 = FUN_00412a49(iVar1);
    iVar4 = iVar4 + iVar5 / 2;
    iVar5 = FUN_004129f6(iVar1);
    iVar5 = iVar5 + iVar6 / 2;
    iVar6 = FUN_00412061();
    FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar7);
  }
  else {
    iVar3 = FUN_00412687(*piVar2,0);
    uVar7 = 1;
    iVar4 = FUN_00412a49(iVar1);
    iVar4 = iVar4 + iVar5 / 2;
    iVar5 = FUN_004129f6(iVar1);
    iVar5 = iVar5 + iVar6 / 2;
    iVar6 = FUN_00412061();
    FUN_004105ee(iVar6,iVar3,iVar5,iVar4,uVar7);
  }
  if (piVar2[4] != 0) {
    FUN_0041258a(iVar1,piVar2[5],piVar2[6],piVar2[6],piVar2[7]);
  }
  return;
}

