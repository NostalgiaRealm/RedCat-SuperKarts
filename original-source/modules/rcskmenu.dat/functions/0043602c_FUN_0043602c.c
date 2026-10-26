/*
 * FUN_0043602c at 0043602c
 * undefined FUN_0043602c(void)
 * Address ranges: 0043602c-00436049
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043602c(int *param_1,uint *param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x20))();
  if (cVar1 != '\0') {
    FUN_00437eec((int *)param_1[6],param_2);
  }
  return;
}

