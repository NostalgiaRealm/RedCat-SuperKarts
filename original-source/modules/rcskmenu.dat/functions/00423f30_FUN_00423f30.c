/*
 * FUN_00423f30 at 00423f30
 * undefined FUN_00423f30(void)
 * Address ranges: 00423f30-00423f6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423f30(int *param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  int *piStack_8;
  
  puStack_c = &stack0xfffffffc;
  *(undefined1 *)(param_1 + 0x7f) = 1;
  puStack_10 = &LAB_00423f6f;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  piStack_8 = param_1;
  FUN_00442914(param_1);
  *in_FS_OFFSET = uStack_14;
  *(undefined1 *)(piStack_8 + 0x7f) = 0;
  return;
}

