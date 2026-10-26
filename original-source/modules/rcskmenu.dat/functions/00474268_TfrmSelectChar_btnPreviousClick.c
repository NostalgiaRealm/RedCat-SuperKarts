/*
 * TfrmSelectChar_btnPreviousClick at 00474268
 * undefined TfrmSelectChar_btnPreviousClick(void)
 * Address ranges: 00474268-00474298
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectChar_btnPreviousClick; original record 00072d22
 */

/* Named by original Delphi published-method table: TfrmSelectChar_btnPreviousClick; original record
   00072d22 */

void TfrmSelectChar_btnPreviousClick(int param_1)

{
  if (*(char *)(param_1 + 0x338) != '\0') {
    FUN_0045c668(0x30,1);
    *(char *)(param_1 + 0x338) = *(char *)(param_1 + 0x338) + -1;
    FUN_004740f8(param_1);
    FUN_0045c5cc(*(byte *)(param_1 + 0x338),0);
  }
  return;
}

