/*
 * FUN_00475490 at 00475490
 * undefined __register FUN_00475490(int param_1)
 * Address ranges: 00475490-00475556
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475490(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_18 = (uint *)0x0;
  local_1c = (uint *)0x0;
  puStack_28 = &LAB_00475557;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  FUN_0045c4c8(2,(int *)&local_8);
  FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_8);
  FUN_0045c4c8(4,(int *)&local_c);
  FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_c);
  FUN_0045c4c8(0xe,(int *)&local_10);
  FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_10);
  FUN_0045c4c8(0x3a,(int *)&local_14);
  FUN_0043f67c(*(int *)(param_1 + 0x2e4),local_14);
  FUN_0045c4c8(0x2c,(int *)&local_18);
  FUN_0043f67c(*(int *)(param_1 + 0x318),local_18);
  FUN_0045c4c8(0x2d,(int *)&local_1c);
  FUN_0043f67c(*(int *)(param_1 + 0x398),local_1c);
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_0047555e;
  puStack_28 = (undefined1 *)0x475556;
  FUN_00403b74((int *)&local_1c,6);
  return;
}

