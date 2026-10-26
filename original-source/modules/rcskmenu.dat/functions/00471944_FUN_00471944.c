/*
 * FUN_00471944 at 00471944
 * undefined __register FUN_00471944(int param_1)
 * Address ranges: 00471944-00471a06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471944(int param_1)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_18 = (uint *)0x0;
  puStack_24 = &LAB_00471a07;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x01') {
    FUN_0045c4c8(0xe,(int *)&local_8);
    FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_8);
  }
  else {
    FUN_0045c4c8(0x3f,(int *)&local_c);
    FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_c);
  }
  FUN_0045c4c8(0x3a,(int *)&local_10);
  FUN_0043f67c(*(int *)(param_1 + 0x2e4),local_10);
  FUN_0045c4c8(2,(int *)&local_14);
  FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_14);
  FUN_0045c4c8(4,(int *)&local_18);
  FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_18);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00471a0e;
  puStack_24 = (undefined1 *)0x471a06;
  FUN_00403b74((int *)&local_18,5);
  return;
}

