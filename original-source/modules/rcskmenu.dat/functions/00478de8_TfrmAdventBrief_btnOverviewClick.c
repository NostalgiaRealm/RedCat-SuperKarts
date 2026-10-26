/*
 * TfrmAdventBrief_btnOverviewClick at 00478de8
 * undefined TfrmAdventBrief_btnOverviewClick(void)
 * Address ranges: 00478de8-00478e48;00478e53-00478e68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventBrief_btnOverviewClick; original record 000776e0
 */

/* Named by original Delphi published-method table: TfrmAdventBrief_btnOverviewClick; original
   record 000776e0 */

void TfrmAdventBrief_btnOverviewClick(void)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x478dfb;
  FUN_0045c720(0x2e);
  puStack_20 = &UNK_00478e69;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_2c = &UNK_00478e49;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  puStack_1c = &stack0xfffffffc;
  piVar1 = FUN_0047790c((int *)&PTR_FUN_00477644,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xd8))();
  }
  *in_FS_OFFSET = uStack_30;
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &UNK_00478e70;
  puStack_20 = (undefined *)0x478e68;
  FUN_00402eac(piVar1);
  return;
}

