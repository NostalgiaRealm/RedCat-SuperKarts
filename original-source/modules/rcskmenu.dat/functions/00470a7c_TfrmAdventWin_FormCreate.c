/*
 * TfrmAdventWin_FormCreate at 00470a7c
 * undefined TfrmAdventWin_FormCreate(void)
 * Address ranges: 00470a7c-00470b34
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventWin_FormCreate; original record 0006fd1a
 */

/* Named by original Delphi published-method table: TfrmAdventWin_FormCreate; original record
   0006fd1a */

void TfrmAdventWin_FormCreate(int param_1)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined1 *puStack_14;
  char *pcStack_c;
  uint *puStack_8;
  
  puStack_14 = &stack0xfffffffc;
  puStack_8 = (uint *)0x0;
  pcStack_c = (char *)0x0;
  puStack_18 = &UNK_00470b35;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  *(undefined1 *)(param_1 + 0x2ec) = 0;
  FUN_00470c4c(param_1,*(undefined4 *)
                        (PTR_PTR_0047c5e0 +
                        (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22) * 4),
               &puStack_8);
  FUN_00407ca8((byte *)puStack_8,(int *)&pcStack_c);
  iVar1 = FUN_004040bc("BMP",pcStack_c);
  if (iVar1 < 1) {
    *(undefined1 *)(param_1 + 0x2ec) = 1;
    FUN_00403ba4((int *)(param_1 + 0x2e8),puStack_8);
    FUN_00470b50(param_1);
  }
  else {
    FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2e0) + 300),puStack_8);
    FUN_0044b72c(*(undefined4 *)(param_1 + 0x2e4),1);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &UNK_00470b3c;
  puStack_18 = (undefined *)0x470b34;
  FUN_00403b74((int *)&pcStack_c,2);
  return;
}

