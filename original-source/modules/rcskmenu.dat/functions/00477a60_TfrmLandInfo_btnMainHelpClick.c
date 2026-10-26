/*
 * TfrmLandInfo_btnMainHelpClick at 00477a60
 * undefined __register TfrmLandInfo_btnMainHelpClick(void)
 * Address ranges: 00477a60-00477a9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmLandInfo_btnMainHelpClick; original record 00076c29
 */

/* Named by original Delphi published-method table: TfrmLandInfo_btnMainHelpClick; original record
   00076c29 */

void TfrmLandInfo_btnMainHelpClick(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  undefined4 *local_8;
  
  puStack_c = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_10 = &LAB_00477a9b;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  FUN_0045c4c8(0x2e,(int *)&local_8);
  FUN_00460d08(local_8);
  *in_FS_OFFSET = uStack_14;
  puStack_c = &LAB_00477aa2;
  puStack_10 = (undefined1 *)0x477a9a;
  FUN_00403b50((int *)&local_8);
  return;
}

