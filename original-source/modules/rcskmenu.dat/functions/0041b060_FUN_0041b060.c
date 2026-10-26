/*
 * FUN_0041b060 at 0041b060
 * undefined FUN_0041b060(void)
 * Address ranges: 0041b060-0041b0b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b060(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_0041b5a4(param_1,param_2);
  if ((char)uVar1 == '\0') {
    iVar3 = FUN_004118b0(param_2);
    iVar2 = FUN_00411894(param_2);
    FUN_0041b218((int)param_1,param_2,iVar3 - iVar2);
  }
  else {
    FUN_0041b148((int)param_1,param_2);
  }
  iVar3 = (**(code **)(*param_1 + 0x24))();
  *(bool *)((int)param_1 + 0x1a) = iVar3 != 0;
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

