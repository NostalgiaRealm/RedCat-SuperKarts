/*
 * TfrmSelectChar_btnOkClick at 00473cec
 * undefined TfrmSelectChar_btnOkClick(void)
 * Address ranges: 00473cec-00473d4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectChar_btnOkClick; original record 00072ce7
 */

/* Named by original Delphi published-method table: TfrmSelectChar_btnOkClick; original record
   00072ce7 */

void TfrmSelectChar_btnOkClick(int *param_1)

{
  char cVar1;
  int extraout_ECX;
  undefined4 extraout_EDX;
  
  FUN_0045a9e4(*(undefined4 *)(*(int *)PTR_DAT_0047c670 + 0x80),
               *(undefined1 *)((int)param_1 + 0x339));
  *(char *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22) = (char)param_1[0xce];
  FUN_00473db4(param_1);
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x01') {
    *(undefined1 *)(param_1 + 0xb5) = 8;
  }
  else {
    *(undefined1 *)(param_1 + 0xb5) = 1;
  }
  FUN_0042eb18(param_1,extraout_EDX,extraout_ECX);
  return;
}

