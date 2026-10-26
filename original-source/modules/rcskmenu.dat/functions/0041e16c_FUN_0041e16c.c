/*
 * FUN_0041e16c at 0041e16c
 * undefined FUN_0041e16c(void)
 * Address ranges: 0041e16c-0041e180
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041e16c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if ((*(int *)(iVar1 + 8) == 0) && (*(int *)(iVar1 + 0xc) == 0)) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return 0;
}

