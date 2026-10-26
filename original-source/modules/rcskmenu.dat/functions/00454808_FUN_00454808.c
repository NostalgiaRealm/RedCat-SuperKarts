/*
 * FUN_00454808 at 00454808
 * undefined4 __register FUN_00454808(int param_1, uint param_2, uint param_3)
 * Address ranges: 00454808-00454817
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00454808(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = param_1 + (param_2 & 0x7f) * 5;
  return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(iVar1 + 4 + (param_3 & 0x7f)));
}

