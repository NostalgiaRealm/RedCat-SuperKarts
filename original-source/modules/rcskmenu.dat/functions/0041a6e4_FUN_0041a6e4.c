/*
 * FUN_0041a6e4 at 0041a6e4
 * undefined __register FUN_0041a6e4(int param_1, uint param_2, int param_3)
 * Address ranges: 0041a6e4-0041a727;0041a745-0041a74b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a6e4(int param_1,uint param_2,int param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x41a6ff;
  FUN_0040f504(*(int **)(param_1 + 4),param_3);
  puStack_20 = &LAB_0041a728;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_1c = &stack0xfffffffc;
  FUN_0040f504(*(int **)(param_1 + 8),param_2 & 0xffff);
  *in_FS_OFFSET = uStack_24;
  return;
}

