/*
 * FUN_00454f40 at 00454f40
 * undefined __register FUN_00454f40(int param_1, int param_2)
 * Address ranges: 00454f40-00454f74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454f40(int param_1,int param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = &stack0xfffffffc;
  puStack_14 = &LAB_00454f75;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    FUN_0040f504(*(int **)(param_1 + 4),param_2);
  }
  *in_FS_OFFSET = uStack_18;
  return;
}

