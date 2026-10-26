/*
 * TfrmDebrief_btnMainStopClick at 00471f8c
 * undefined TfrmDebrief_btnMainStopClick(void)
 * Address ranges: 00471f8c-00471ff7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDebrief_btnMainStopClick; original record 00070bac
 */

/* Named by original Delphi published-method table: TfrmDebrief_btnMainStopClick; original record
   00070bac */

void TfrmDebrief_btnMainStopClick(int *param_1)

{
  char cVar1;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined4 *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (undefined4 *)0x0;
  puStack_14 = &LAB_00471ff8;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  FUN_0045c4c8(0x24,(int *)&puStack_8);
  cVar1 = FUN_00460d08(puStack_8);
  if (cVar1 == '\x01') {
    (**(code **)**(undefined4 **)PTR_DAT_0047c740)();
    FUN_0045bbac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),5);
    *(undefined1 *)(param_1 + 0xb5) = 4;
    FUN_0042eb18(param_1,extraout_EDX,extraout_ECX);
  }
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00471fff;
  puStack_14 = (undefined1 *)0x471ff7;
  FUN_00403b50((int *)&puStack_8);
  return;
}

