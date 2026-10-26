/*
 * FUN_00460af8 at 00460af8
 * undefined __register FUN_00460af8(int param_1)
 * Address ranges: 00460af8-00460b5a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460af8(int param_1)

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
  puStack_18 = &LAB_00460b5b;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0045c4c8(0x2a,(int *)&local_8);
  FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_8);
  FUN_0045c4c8(0x2b,(int *)&local_c);
  FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_c);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00460b62;
  puStack_18 = (undefined1 *)0x460b5a;
  FUN_00403b74((int *)&local_c,2);
  return;
}

