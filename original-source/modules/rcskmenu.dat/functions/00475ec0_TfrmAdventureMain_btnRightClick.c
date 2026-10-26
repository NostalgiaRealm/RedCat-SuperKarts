/*
 * TfrmAdventureMain_btnRightClick at 00475ec0
 * undefined __register TfrmAdventureMain_btnRightClick(int param_1)
 * Address ranges: 00475ec0-00475eee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventureMain_btnRightClick; original record 00074699
 */

/* Named by original Delphi published-method table: TfrmAdventureMain_btnRightClick; original record
   00074699 */

void TfrmAdventureMain_btnRightClick(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00457c88(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),*(int *)(param_1 + 0x3a4));
  if (iVar1 != -1) {
    *(int *)(param_1 + 0x3a4) = iVar1;
    FUN_00475ab4(param_1);
  }
  return;
}

