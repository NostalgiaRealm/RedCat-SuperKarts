/*
 * TfrmSelectCountry_btnLeftClick at 0046fdc4
 * undefined __register TfrmSelectCountry_btnLeftClick(int param_1)
 * Address ranges: 0046fdc4-0046fdee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectCountry_btnLeftClick; original record 0006e800
 */

/* Named by original Delphi published-method table: TfrmSelectCountry_btnLeftClick; original record
   0006e800 */

void TfrmSelectCountry_btnLeftClick(int param_1)

{
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  if (*(char *)(param_1 + 0x338) != '\0') {
    FUN_0045c668(0x30,1);
    *(char *)(param_1 + 0x338) = *(char *)(param_1 + 0x338) + -1;
    FUN_0046f84c(param_1,extraout_EDX);
    FUN_0046fcc4(param_1,extraout_EDX_00);
  }
  return;
}

