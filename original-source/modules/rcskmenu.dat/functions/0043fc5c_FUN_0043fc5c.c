/*
 * FUN_0043fc5c at 0043fc5c
 * undefined4 __register FUN_0043fc5c(int param_1)
 * Address ranges: 0043fc5c-0043fc75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043fc5c(int param_1)

{
  int iVar1;
  
  if ((PTR_DAT_0047c9d8[9] != '\0') &&
     (iVar1 = CONCAT31((int3)((uint)param_1 >> 8),*(undefined1 *)(param_1 + 0x4f)) + -1,
     (byte)iVar1 < 2)) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return 0;
}

