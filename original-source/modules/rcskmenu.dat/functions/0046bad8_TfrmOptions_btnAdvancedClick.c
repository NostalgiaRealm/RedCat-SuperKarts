/*
 * TfrmOptions_btnAdvancedClick at 0046bad8
 * undefined TfrmOptions_btnAdvancedClick(void)
 * Address ranges: 0046bad8-0046bb48;0046bb53-0046bb60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmOptions_btnAdvancedClick; original record 0006a21e
 */

/* Named by original Delphi published-method table: TfrmOptions_btnAdvancedClick; original record
   0006a21e */

void TfrmOptions_btnAdvancedClick(void)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_1c = &UNK_0046bb49;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  piVar1 = (int *)FUN_0042adf0((int *)&PTR_FUN_00469a64,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  FUN_0045ba6c(piVar1[0xce],*(int **)(*(int *)PTR_DAT_0047c670 + 0x7c));
  (**(code **)(*piVar1 + 0xd8))();
  FUN_0045ba6c(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),(int *)piVar1[0xce]);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = (undefined1 *)0x46bb5b;
  FUN_00402eac(piVar1);
  return;
}

