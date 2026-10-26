/*
 * FUN_0043e7a0 at 0043e7a0
 * undefined FUN_0043e7a0(void)
 * Address ranges: 0043e7a0-0043e7bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e7a0(int *param_1,uint *param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x20))();
  if (cVar1 != '\0') {
    FUN_0043f67c(param_1[6],param_2);
  }
  return;
}

