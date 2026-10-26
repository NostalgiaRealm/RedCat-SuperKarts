/*
 * FUN_0041cd44 at 0041cd44
 * undefined FUN_0041cd44(void)
 * Address ranges: 0041cd44-0041cd58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041cd44(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if ((*(int *)(iVar1 + 8) == 0) && (*(int *)(iVar1 + 0x14) == 0)) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return 0;
}

