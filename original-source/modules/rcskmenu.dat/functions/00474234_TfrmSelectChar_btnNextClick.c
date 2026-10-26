/*
 * TfrmSelectChar_btnNextClick at 00474234
 * undefined TfrmSelectChar_btnNextClick(void)
 * Address ranges: 00474234-00474264
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectChar_btnNextClick; original record 00072d0f
 */

/* Named by original Delphi published-method table: TfrmSelectChar_btnNextClick; original record
   00072d0f */

void TfrmSelectChar_btnNextClick(int param_1)

{
  if (*(byte *)(param_1 + 0x338) < 3) {
    FUN_0045c668(0x2f,1);
    *(char *)(param_1 + 0x338) = *(char *)(param_1 + 0x338) + '\x01';
    FUN_004740f8(param_1);
    FUN_0045c5cc(*(byte *)(param_1 + 0x338),0);
  }
  return;
}

