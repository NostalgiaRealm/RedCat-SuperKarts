/*
 * FUN_00419db3 at 00419db3
 * undefined __cdecl FUN_00419db3(int * param_1)
 * Address ranges: 00419db3-00419e34
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00419db3(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  FUN_00412a9d(param_1[6]);
  piVar1 = (int *)FUN_00412b01(param_1[6]);
  uVar7 = 0;
  iVar4 = param_1[1] + *(int *)(DAT_0043db88 + 0x84) * piVar1[1];
  iVar3 = *param_1 + *(int *)(DAT_0043db88 + 0x80) * *piVar1;
  iVar6 = param_1[1];
  iVar5 = *param_1;
  iVar2 = FUN_00412061();
  FUN_0040f8b1(2,iVar2,iVar5,iVar6,iVar3,iVar4,uVar7);
  return;
}

