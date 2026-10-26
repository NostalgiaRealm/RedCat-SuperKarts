/*
 * TfrmHighscore_btnQuitClick at 004771f8
 * undefined TfrmHighscore_btnQuitClick(void)
 * Address ranges: 004771f8-00477275
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmHighscore_btnQuitClick; original record 00075be1
 */

/* Named by original Delphi published-method table: TfrmHighscore_btnQuitClick; original record
   00075be1 */

void TfrmHighscore_btnQuitClick(int *param_1)

{
  char cVar1;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined *puStack_14;
  undefined1 *puStack_10;
  undefined4 *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_14 = &UNK_00477276;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  (**(code **)(*param_1 + 0x5c))(param_1,0);
  FUN_0045c4c8(0x24,(int *)&puStack_8);
  cVar1 = FUN_00460d08(puStack_8);
  if (cVar1 == '\x01') {
    FUN_0045bbac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),5);
    (**(code **)**(undefined4 **)PTR_DAT_0047c740)();
    *(undefined1 *)(param_1 + 0xb5) = 4;
    FUN_0042eb18(param_1,extraout_EDX,extraout_ECX);
  }
  (**(code **)(*param_1 + 0x5c))(param_1,1);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &UNK_0047727d;
  puStack_14 = (undefined *)0x477275;
  FUN_00403b50((int *)&puStack_8);
  return;
}

