/*
 * TfrmSelectChar_FormShow at 004742d4
 * undefined __register TfrmSelectChar_FormShow(int param_1)
 * Address ranges: 004742d4-00474323
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectChar_FormShow; original record 00072d50
 */

/* Named by original Delphi published-method table: TfrmSelectChar_FormShow; original record
   00072d50 */

void TfrmSelectChar_FormShow(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x02') {
    cVar1 = FUN_0045d4a0(param_1,*(int *)(param_1 + 0x2d0));
    if (cVar1 == '\0') {
      FUN_0045c720(0x35);
    }
    else {
      FUN_0045c720(0x1f);
    }
  }
  else {
    FUN_0045c720(0x35);
  }
  (**(code **)(**(int **)(param_1 + 0x2e8) + 0xb0))();
  return;
}

