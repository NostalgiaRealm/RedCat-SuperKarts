/*
 * FUN_0047851c at 0047851c
 * undefined __register FUN_0047851c(int param_1)
 * Address ranges: 0047851c-004785fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047851c(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_28 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_18 = (uint *)0x0;
  local_1c = (uint *)0x0;
  local_20 = (uint *)0x0;
  puStack_2c = &LAB_004785fc;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  FUN_0045c4c8(0x41,(int *)&local_8);
  FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_8);
  FUN_0045c4c8(0xf,(int *)&local_c);
  FUN_0043f67c(*(int *)(param_1 + 0x2e4),local_c);
  FUN_0045c4c8(0x4d,(int *)&local_10);
  FUN_0043f67c(*(int *)(param_1 + 0x2ec),local_10);
  FUN_0045c4c8(2,(int *)&local_14);
  FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_14);
  FUN_0045c4c8(4,(int *)&local_18);
  FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_18);
  FUN_0045c4c8(0x43,(int *)&local_1c);
  FUN_0043f67c(*(int *)(param_1 + 0x37c),local_1c);
  FUN_0045c4c8(0x44,(int *)&local_20);
  FUN_0043f67c(*(int *)(param_1 + 0x380),local_20);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_00478603;
  puStack_2c = (undefined1 *)0x4785fb;
  FUN_00403b74((int *)&local_20,7);
  return;
}

