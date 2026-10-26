/*
 * TfrmHighscore_btnRightClick at 00477284
 * undefined TfrmHighscore_btnRightClick(void)
 * Address ranges: 00477284-004772ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmHighscore_btnRightClick; original record 00075bf4
 */

/* Named by original Delphi published-method table: TfrmHighscore_btnRightClick; original record
   00075bf4 */

void TfrmHighscore_btnRightClick(int param_1)

{
  undefined4 extraout_EDX;
  
  if (*(char *)(param_1 + 900) != '\x05') {
    FUN_0045c668(0x2f,1);
    *(char *)(param_1 + 900) = *(char *)(param_1 + 900) + '\x01';
    FUN_00476cd8(param_1,extraout_EDX);
    FUN_00476eb8(param_1);
  }
  return;
}

