/*
 * TfrmEditBox_FormShow at 00470678
 * undefined __register TfrmEditBox_FormShow(int param_1)
 * Address ranges: 00470678-0047071c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmEditBox_FormShow; original record 0006f754
 */

/* Named by original Delphi published-method table: TfrmEditBox_FormShow; original record 0006f754
    */

void TfrmEditBox_FormShow(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  puStack_20 = &LAB_0047071d;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  if (*(char *)(param_1 + 0x2f0) == '\0') {
    FUN_0045c4c8(0x2a,(int *)&local_8);
    FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_8);
    FUN_0045c4c8(0x2b,(int *)&local_c);
    FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_c);
  }
  else if (*(char *)(param_1 + 0x2f0) == '\x01') {
    puStack_1c = &stack0xfffffffc;
    FUN_0045c4c8(0xe,(int *)&local_10);
    FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_10);
    FUN_0045c4c8(0x40,(int *)&local_14);
    FUN_0043f67c(*(int *)(param_1 + 0x2e0),local_14);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00470724;
  puStack_20 = (undefined1 *)0x47071c;
  FUN_00403b74((int *)&local_14,4);
  return;
}

