/*
 * FUN_0043610c at 0043610c
 * undefined FUN_0043610c(void)
 * Address ranges: 0043610c-00436129
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043610c(int *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x3c))();
  if (cVar1 != '\0') {
    FUN_004380cc((int *)param_1[6],param_2);
  }
  return;
}

