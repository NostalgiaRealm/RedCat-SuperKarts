/*
 * FUN_00439ff8 at 00439ff8
 * undefined FUN_00439ff8(void)
 * Address ranges: 00439ff8-0043a007
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00439ff8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x48) != 0) {
    return *(int *)(param_1 + 0x48);
  }
  iVar1 = FUN_00439300(param_1);
  return iVar1;
}

