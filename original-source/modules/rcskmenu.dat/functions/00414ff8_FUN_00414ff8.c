/*
 * FUN_00414ff8 at 00414ff8
 * undefined FUN_00414ff8(void)
 * Address ranges: 00414ff8-00415022
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414ff8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (param_2 != iVar1) {
    if (iVar1 != 0) {
      FUN_00415184(iVar1,param_1);
    }
    *(int *)(param_1 + 0x10) = param_2;
    if (param_2 != 0) {
      FUN_00415178(param_2,param_1);
    }
  }
  return;
}

