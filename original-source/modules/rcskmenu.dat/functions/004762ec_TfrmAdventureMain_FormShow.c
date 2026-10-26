/*
 * TfrmAdventureMain_FormShow at 004762ec
 * undefined TfrmAdventureMain_FormShow(void)
 * Address ranges: 004762ec-0047633f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventureMain_FormShow; original record 000746f7
 */

/* Named by original Delphi published-method table: TfrmAdventureMain_FormShow; original record
   000746f7 */

void TfrmAdventureMain_FormShow(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0045d4a0(param_1,*(int *)(param_1 + 0x2d0));
  if (cVar1 == '\0') {
    FUN_0045c720(0x19);
  }
  else {
    FUN_0045c720(0x18);
  }
  cVar1 = (**(code **)(**(int **)(param_1 + 0x2e8) + 0x4c))();
  if (cVar1 != '\0') {
    (**(code **)(**(int **)(param_1 + 0x2e8) + 0xb0))();
  }
  return;
}

