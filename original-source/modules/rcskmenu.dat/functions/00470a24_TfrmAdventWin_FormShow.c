/*
 * TfrmAdventWin_FormShow at 00470a24
 * undefined __register TfrmAdventWin_FormShow(int param_1)
 * Address ranges: 00470a24-00470a58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventWin_FormShow; original record 0006fcf8
 */

/* Named by original Delphi published-method table: TfrmAdventWin_FormShow; original record 0006fcf8
    */

void TfrmAdventWin_FormShow(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x2ec) != '\0') {
    FUN_0046e0a0(*(int *)(param_1 + 0x2d8),'\x01');
    cVar1 = FUN_0046e554(*(int *)(param_1 + 0x2d8));
    if (cVar1 == '\x06') {
      FUN_0046d694(*(int **)(param_1 + 0x2d8));
    }
  }
  return;
}

