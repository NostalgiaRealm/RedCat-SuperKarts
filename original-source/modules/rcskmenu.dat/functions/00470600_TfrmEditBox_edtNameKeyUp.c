/*
 * TfrmEditBox_edtNameKeyUp at 00470600
 * undefined TfrmEditBox_edtNameKeyUp(void)
 * Address ranges: 00470600-00470668
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmEditBox_edtNameKeyUp; original record 0006f741
 */

/* Named by original Delphi published-method table: TfrmEditBox_edtNameKeyUp; original record
   0006f741 */

void TfrmEditBox_edtNameKeyUp(int *param_1,undefined4 param_2,short *param_3)

{
  int iVar1;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined1 *puStack_14;
  int iStack_8;
  
  puStack_14 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_18 = &UNK_00470669;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0043f64c(param_1[0xb9],&iStack_8);
  iVar1 = FUN_00403dd0(iStack_8);
  (**(code **)(*(int *)param_1[0xb7] + 0x5c))((int *)param_1[0xb7],0 < iVar1);
  if (*param_3 == 0xd) {
    *(undefined1 *)(param_1 + 0xb5) = 4;
    FUN_0042eb18(param_1,extraout_EDX,extraout_ECX);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &UNK_00470670;
  puStack_18 = (undefined *)0x470668;
  FUN_00403b50(&iStack_8);
  return;
}

