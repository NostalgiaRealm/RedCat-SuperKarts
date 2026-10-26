/*
 * FUN_004c1c4b at 004c1c4b
 * undefined FUN_004c1c4b(void)
 * Address ranges: 004c1c4b-004c1c6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c1c4b(char *param_1,int param_2)

{
  size_t sVar1;
  
  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_004bef90(param_1 + param_2,param_1,sVar1 + 1);
  }
  return;
}

