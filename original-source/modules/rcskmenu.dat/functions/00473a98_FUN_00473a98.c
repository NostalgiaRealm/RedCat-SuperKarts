/*
 * FUN_00473a98 at 00473a98
 * undefined __register FUN_00473a98(int param_1)
 * Address ranges: 00473a98-00473ba5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473a98(int param_1)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_2c = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_18 = (uint *)0x0;
  local_1c = (uint *)0x0;
  local_20 = (uint *)0x0;
  local_24 = (uint *)0x0;
  puStack_30 = &LAB_00473ba6;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x01') {
    FUN_0045c4c8(0xe,(int *)&local_8);
    FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_8);
  }
  else {
    FUN_0045c4c8(0x2f,(int *)&local_c);
    FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_c);
  }
  FUN_0045c4c8(0xf,(int *)&local_10);
  FUN_0043f67c(*(int *)(param_1 + 0x2e4),local_10);
  FUN_0045c4c8(2,(int *)&local_14);
  FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_14);
  FUN_0045c4c8(4,(int *)&local_18);
  FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_18);
  FUN_0045c4c8(8,(int *)&local_1c);
  FUN_0043f67c(*(int *)(param_1 + 0x328),local_1c);
  FUN_0045c4c8(9,(int *)&local_20);
  FUN_0043f67c(*(int *)(param_1 + 0x2f0),local_20);
  FUN_0045c4c8(10,(int *)&local_24);
  FUN_0043f67c(*(int *)(param_1 + 0x2f4),local_24);
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_00473bad;
  puStack_30 = (undefined1 *)0x473ba5;
  FUN_00403b74((int *)&local_24,8);
  return;
}

