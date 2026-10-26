/*
 * TfrmControlSettings_btnCancelClick at 004618d0
 * undefined __register TfrmControlSettings_btnCancelClick(int * param_1)
 * Address ranges: 004618d0-004618fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmControlSettings_btnCancelClick; original record 000606f9
 */

/* Named by original Delphi published-method table: TfrmControlSettings_btnCancelClick; original
   record 000606f9 */

void TfrmControlSettings_btnCancelClick(int *param_1)

{
  int extraout_ECX;
  undefined4 extraout_EDX;
  
  FUN_00458d6c(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88));
  *(undefined1 *)(param_1 + 0xb5) = 2;
  *(undefined1 *)((int)param_1 + 0x34f) = 1;
  FUN_0042eb18(param_1,extraout_EDX,extraout_ECX);
  return;
}

