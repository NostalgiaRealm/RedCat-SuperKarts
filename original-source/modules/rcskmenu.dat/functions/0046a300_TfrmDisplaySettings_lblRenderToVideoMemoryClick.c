/*
 * TfrmDisplaySettings_lblRenderToVideoMemoryClick at 0046a300
 * undefined TfrmDisplaySettings_lblRenderToVideoMemoryClick(void)
 * Address ranges: 0046a300-0046a325
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_lblRenderToVideoMemoryClick; original record 000691ab
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_lblRenderToVideoMemoryClick;
   original record 000691ab */

void TfrmDisplaySettings_lblRenderToVideoMemoryClick(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x324);
  uVar2 = (**(code **)(*piVar1 + 0xb4))();
  (**(code **)(*piVar1 + 0xb8))(piVar1,uVar2 ^ 1);
  return;
}

