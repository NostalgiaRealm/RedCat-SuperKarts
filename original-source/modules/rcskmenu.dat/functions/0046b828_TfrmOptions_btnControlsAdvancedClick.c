/*
 * TfrmOptions_btnControlsAdvancedClick at 0046b828
 * undefined TfrmOptions_btnControlsAdvancedClick(void)
 * Address ranges: 0046b828-0046b88d;0046b898-0046b8ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmOptions_btnControlsAdvancedClick; original record 0006a1d3
 */

/* Named by original Delphi published-method table: TfrmOptions_btnControlsAdvancedClick; original
   record 0006a1d3 */

void TfrmOptions_btnControlsAdvancedClick(void)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  puStack_1c = &UNK_0046b8ae;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &UNK_0046b88e;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  FUN_0045c720(0xc);
  piVar1 = FUN_004615d8((int *)&PTR_FUN_00460fd0,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  if (piVar1 != (int *)0x0) {
    FUN_00461858((int)piVar1,'\x01',extraout_ECX);
    (**(code **)(*piVar1 + 0xd8))();
  }
  *in_FS_OFFSET = uStack_2c;
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &UNK_0046b8b5;
  puStack_1c = (undefined *)0x46b8ad;
  FUN_00402eac(piVar1);
  return;
}

