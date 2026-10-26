/*
 * TfrmDisplaySettings_lblWaitVblClick at 0046a328
 * undefined TfrmDisplaySettings_lblWaitVblClick(void)
 * Address ranges: 0046a328-0046a34d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_lblWaitVblClick; original record 000691cd
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_lblWaitVblClick; original
   record 000691cd */

void TfrmDisplaySettings_lblWaitVblClick(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x328);
  uVar2 = (**(code **)(*piVar1 + 0xb4))();
  (**(code **)(*piVar1 + 0xb8))(piVar1,uVar2 ^ 1);
  return;
}

