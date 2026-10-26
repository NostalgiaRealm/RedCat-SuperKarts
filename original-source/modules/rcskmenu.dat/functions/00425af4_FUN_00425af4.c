/*
 * FUN_00425af4 at 00425af4
 * undefined FUN_00425af4(void)
 * Address ranges: 00425af4-00425b30
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00425af4(int *param_1)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_1 + 0x1fa);
  if (cVar1 == '\0') {
    if (*(char *)((int)param_1 + 0x1f9) == '\0') {
      FUN_00425b7c(param_1,'\x01');
      return;
    }
    FUN_00425b7c(param_1,'\x02');
  }
  else {
    if (cVar1 == '\x01') {
      FUN_00425b7c(param_1,'\0');
      return;
    }
    if (cVar1 == '\x02') {
      FUN_00425b7c(param_1,'\x01');
    }
  }
  return;
}

