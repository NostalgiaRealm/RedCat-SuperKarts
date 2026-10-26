/*
 * FUN_00466e9c at 00466e9c
 * undefined __register FUN_00466e9c(int param_1)
 * Address ranges: 00466e9c-00466eb9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466e9c(int param_1)

{
  char cVar1;
  
  if ((*(int *)(param_1 + 500) == 0) || (*(char *)(param_1 + 0x1f8) == '\0')) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  FUN_00466e44(param_1,cVar1);
  return;
}

