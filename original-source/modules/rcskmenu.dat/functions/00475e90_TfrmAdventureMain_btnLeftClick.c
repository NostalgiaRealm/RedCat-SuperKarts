/*
 * TfrmAdventureMain_btnLeftClick at 00475e90
 * undefined __register TfrmAdventureMain_btnLeftClick(int param_1)
 * Address ranges: 00475e90-00475ebe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventureMain_btnLeftClick; original record 00074686
 */

/* Named by original Delphi published-method table: TfrmAdventureMain_btnLeftClick; original record
   00074686 */

void TfrmAdventureMain_btnLeftClick(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00457cac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),*(int *)(param_1 + 0x3a4));
  if (iVar1 != -1) {
    *(int *)(param_1 + 0x3a4) = iVar1;
    FUN_00475ab4(param_1);
  }
  return;
}

