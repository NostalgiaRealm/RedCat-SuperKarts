/*
 * TfrmMain_FormShow at 00474b00
 * undefined TfrmMain_FormShow(void)
 * Address ranges: 00474b00-00474b33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmMain_FormShow; original record 00073b09
 */

/* Named by original Delphi published-method table: TfrmMain_FormShow; original record 00073b09 */

void TfrmMain_FormShow(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0045d4a0(param_1,*(int *)(param_1 + 0x2d0));
  if (cVar1 == '\0') {
    FUN_0045c720(1);
  }
  else {
    FUN_0045c720(0);
  }
  (**(code **)(**(int **)(param_1 + 0x2e0) + 0xb0))();
  return;
}

