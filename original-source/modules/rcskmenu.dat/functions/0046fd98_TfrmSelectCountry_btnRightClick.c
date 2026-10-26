/*
 * TfrmSelectCountry_btnRightClick at 0046fd98
 * undefined TfrmSelectCountry_btnRightClick(void)
 * Address ranges: 0046fd98-0046fdc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectCountry_btnRightClick; original record 0006e7ec
 */

/* Named by original Delphi published-method table: TfrmSelectCountry_btnRightClick; original record
   0006e7ec */

void TfrmSelectCountry_btnRightClick(int param_1)

{
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  if (*(char *)(param_1 + 0x338) != '\x05') {
    FUN_0045c668(0x2f,1);
    *(char *)(param_1 + 0x338) = *(char *)(param_1 + 0x338) + '\x01';
    FUN_0046f84c(param_1,extraout_EDX);
    FUN_0046fcc4(param_1,extraout_EDX_00);
  }
  return;
}

