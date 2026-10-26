/*
 * TfrmOptions_rdoKeyboardClick at 0046b554
 * undefined TfrmOptions_rdoKeyboardClick(void)
 * Address ranges: 0046b554-0046b5c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmOptions_rdoKeyboardClick; original record 0006a12b
 */

/* Named by original Delphi published-method table: TfrmOptions_rdoKeyboardClick; original record
   0006a12b */

void TfrmOptions_rdoKeyboardClick(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined *puStack_14;
  undefined1 *puStack_10;
  uint *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  puStack_14 = &UNK_0046b5ca;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  *(undefined1 *)(param_1 + 0x364) = 0;
  (**(code **)(**(int **)(param_1 + 0x334) + 0x5c))(*(int **)(param_1 + 0x334),1);
  FUN_0046b8dc(param_1,*(int *)(PTR_PTR_0047c99c + (uint)*(byte *)(param_1 + 0x364) * 4),&puStack_8)
  ;
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x34c) + 300),puStack_8);
  FUN_0045c720(9);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &UNK_0046b5d1;
  puStack_14 = (undefined *)0x46b5c9;
  FUN_00403b50((int *)&puStack_8);
  return;
}

