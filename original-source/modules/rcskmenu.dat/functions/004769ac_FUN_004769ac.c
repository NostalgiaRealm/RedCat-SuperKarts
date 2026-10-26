/*
 * FUN_004769ac at 004769ac
 * undefined __register FUN_004769ac(int param_1)
 * Address ranges: 004769ac-00476a0e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004769ac(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *local_c;
  uint *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  puStack_18 = &LAB_00476a0f;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0045c4c8(4,(int *)&local_8);
  FUN_0043f67c(*(int *)(param_1 + 0x374),local_8);
  FUN_0045c4c8(0xe,(int *)&local_c);
  FUN_0043f67c(*(int *)(param_1 + 0x2d8),local_c);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00476a16;
  puStack_18 = (undefined1 *)0x476a0e;
  FUN_00403b74((int *)&local_c,2);
  return;
}

