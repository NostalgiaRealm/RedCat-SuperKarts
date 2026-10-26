/*
 * FUN_004107ac at 004107ac
 * undefined FUN_004107ac(void)
 * Address ranges: 004107ac-004107e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004107ac(undefined4 param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = FUN_00410f04;
  uVar2 = 0x411258;
  uVar4 = param_1;
  bVar1 = FUN_00410754();
  (**(code **)(*param_2 + 4))(param_2,"Strings",bVar1,uVar2,param_1,pcVar3,uVar4);
  return;
}

