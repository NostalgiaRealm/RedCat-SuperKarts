/*
 * FUN_0043604c at 0043604c
 * undefined FUN_0043604c(void)
 * Address ranges: 0043604c-00436069
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043604c(int *param_1,byte param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x24))();
  if (cVar1 != '\0') {
    FUN_00437f5c(param_1[6],param_2);
  }
  return;
}

