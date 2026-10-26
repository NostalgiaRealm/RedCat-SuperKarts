/*
 * FUN_00460cb8 at 00460cb8
 * undefined __register FUN_00460cb8(int param_1, undefined4 * param_2)
 * Address ranges: 00460cb8-00460cfb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460cb8(int param_1,undefined4 *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *local_8;
  
  puStack_10 = (undefined1 *)0x460cca;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_14 = &LAB_00460cfc;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_00403ba4((int *)(param_1 + 0x2ec),local_8);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00460d03;
  puStack_14 = (undefined1 *)0x460cfb;
  FUN_00403b50((int *)&local_8);
  return;
}

