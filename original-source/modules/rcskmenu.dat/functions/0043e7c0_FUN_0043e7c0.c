/*
 * FUN_0043e7c0 at 0043e7c0
 * undefined FUN_0043e7c0(void)
 * Address ranges: 0043e7c0-0043e7dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e7c0(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 != '\0') {
    (**(code **)(*(int *)param_1[6] + 0x5c))((int *)param_1[6],param_2);
  }
  return;
}

