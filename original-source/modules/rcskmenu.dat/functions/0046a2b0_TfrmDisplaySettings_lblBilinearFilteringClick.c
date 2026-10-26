/*
 * TfrmDisplaySettings_lblBilinearFilteringClick at 0046a2b0
 * undefined TfrmDisplaySettings_lblBilinearFilteringClick(void)
 * Address ranges: 0046a2b0-0046a2d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_lblBilinearFilteringClick; original record 0006916f
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_lblBilinearFilteringClick;
   original record 0006916f */

void TfrmDisplaySettings_lblBilinearFilteringClick(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x314);
  uVar2 = (**(code **)(*piVar1 + 0xb4))();
  (**(code **)(*piVar1 + 0xb8))(piVar1,uVar2 ^ 1);
  return;
}

