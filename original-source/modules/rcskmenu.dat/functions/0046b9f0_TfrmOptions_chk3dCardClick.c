/*
 * TfrmOptions_chk3dCardClick at 0046b9f0
 * undefined TfrmOptions_chk3dCardClick(void)
 * Address ranges: 0046b9f0-0046bacc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmOptions_chk3dCardClick; original record 0006a209
 */

/* Named by original Delphi published-method table: TfrmOptions_chk3dCardClick; original record
   0006a209 */

void TfrmOptions_chk3dCardClick(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined *puStack_14;
  undefined1 *puStack_10;
  uint *puStack_8;
  
  puStack_10 = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  puStack_14 = &UNK_0046bacd;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  cVar1 = (**(code **)(**(int **)(param_1 + 0x344) + 0xb4))();
  if (cVar1 == '\0') {
    FUN_0045c720(0xe);
    *(undefined1 *)(param_1 + 0x365) = 0;
    *(undefined1 *)(param_1 + 0x366) = 1;
  }
  else {
    FUN_0045c720(0xd);
    *(undefined1 *)(param_1 + 0x365) = 1;
    *(undefined1 *)(param_1 + 0x366) = 3;
  }
  FUN_0046b8dc(param_1,*(int *)(PTR_PTR_0047c934 + (uint)*(byte *)(param_1 + 0x366) * 4),&puStack_8)
  ;
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x348) + 300),puStack_8);
  if ((*(char *)(param_1 + 0x366) == '\0') || (*(char *)(param_1 + 0x366) == '\x03')) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x318) + 0xb8))(*(int **)(param_1 + 0x318),uVar2);
  if ((*(char *)(param_1 + 0x366) == '\x01') || (*(char *)(param_1 + 0x366) == '\x04')) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x31c) + 0xb8))(*(int **)(param_1 + 0x31c),uVar2);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &UNK_0046bad4;
  puStack_14 = (undefined *)0x46bacc;
  FUN_00403b50((int *)&puStack_8);
  return;
}

