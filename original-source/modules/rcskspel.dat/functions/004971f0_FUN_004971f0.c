/*
 * FUN_004971f0 at 004971f0
 * undefined FUN_004971f0(void)
 * Address ranges: 004971f0-00497260
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004971f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(param_1 + 0x9e) = 0;
  *(undefined4 *)(param_1 + 0xa2) = 0;
  iVar1 = FUN_00497ab0(param_2,param_3,&param_2,&param_3,&local_4,&local_8);
  FUN_00497270(param_2,param_3);
  if (iVar1 != 0) {
    FUN_00497270(local_4,local_8);
  }
  return;
}

