/*
 * FUN_00460b88 at 00460b88
 * undefined __register FUN_00460b88(int param_1, uint * param_2)
 * Address ranges: 00460b88-00460bdc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460b88(int param_1,uint *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  uint *local_8;
  
  puStack_10 = (undefined1 *)0x460b9a;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_14 = &LAB_00460bdd;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2e8) + 300),local_8);
  FUN_0043fb28(*(int **)(param_1 + 0x2e8));
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00460be4;
  puStack_14 = (undefined1 *)0x460bdc;
  FUN_00403b50((int *)&local_8);
  return;
}

