/*
 * TfrmOptions_rdoLowQualClick at 0046b6e0
 * undefined TfrmOptions_rdoLowQualClick(void)
 * Address ranges: 0046b6e0-0046b75a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmOptions_rdoLowQualClick; original record 0006a16f
 */

/* Named by original Delphi published-method table: TfrmOptions_rdoLowQualClick; original record
   0006a16f */

void TfrmOptions_rdoLowQualClick(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined *puStack_14;
  undefined1 *puStack_10;
  uint *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  puStack_14 = &UNK_0046b75b;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  if (*(char *)(param_1 + 0x365) == '\x01') {
    *(undefined1 *)(param_1 + 0x366) = 3;
  }
  else {
    *(undefined1 *)(param_1 + 0x366) = 0;
  }
  FUN_0046b8dc(param_1,*(int *)(PTR_PTR_0047c934 + (uint)*(byte *)(param_1 + 0x366) * 4),&puStack_8)
  ;
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x348) + 300),puStack_8);
  FUN_0045c720(0xf);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &UNK_0046b762;
  puStack_14 = (undefined *)0x46b75a;
  FUN_00403b50((int *)&puStack_8);
  return;
}

