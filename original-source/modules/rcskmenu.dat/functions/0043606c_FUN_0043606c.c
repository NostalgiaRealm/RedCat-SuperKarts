/*
 * FUN_0043606c at 0043606c
 * undefined FUN_0043606c(void)
 * Address ranges: 0043606c-00436089
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043606c(int *param_1,byte param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 != '\0') {
    FUN_00437fb0((int *)param_1[6],param_2);
  }
  return;
}

