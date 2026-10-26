/*
 * TfrmHighscore_btnLeftClick at 004772b0
 * undefined __register TfrmHighscore_btnLeftClick(int param_1)
 * Address ranges: 004772b0-004772da
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmHighscore_btnLeftClick; original record 00075c08
 */

/* Named by original Delphi published-method table: TfrmHighscore_btnLeftClick; original record
   00075c08 */

void TfrmHighscore_btnLeftClick(int param_1)

{
  undefined4 extraout_EDX;
  
  if (*(char *)(param_1 + 900) != '\0') {
    FUN_0045c668(0x30,1);
    *(char *)(param_1 + 900) = *(char *)(param_1 + 900) + -1;
    FUN_00476cd8(param_1,extraout_EDX);
    FUN_00476eb8(param_1);
  }
  return;
}

