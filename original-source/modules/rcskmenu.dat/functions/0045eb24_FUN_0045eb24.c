/*
 * FUN_0045eb24 at 0045eb24
 * undefined FUN_0045eb24(void)
 * Address ranges: 0045eb24-0045eb42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045eb24(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0xb4))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0xb8))(param_1,1);
  }
  return;
}

