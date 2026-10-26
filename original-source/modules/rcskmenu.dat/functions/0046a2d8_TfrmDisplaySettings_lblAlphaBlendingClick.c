/*
 * TfrmDisplaySettings_lblAlphaBlendingClick at 0046a2d8
 * undefined TfrmDisplaySettings_lblAlphaBlendingClick(void)
 * Address ranges: 0046a2d8-0046a2fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_lblAlphaBlendingClick; original record 0006918f
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_lblAlphaBlendingClick;
   original record 0006918f */

void TfrmDisplaySettings_lblAlphaBlendingClick(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x31c);
  uVar2 = (**(code **)(*piVar1 + 0xb4))();
  (**(code **)(*piVar1 + 0xb8))(piVar1,uVar2 ^ 1);
  return;
}

