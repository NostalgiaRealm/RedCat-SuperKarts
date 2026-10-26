/*
 * TfrmStarAnim_FormCreate at 004710c0
 * undefined TfrmStarAnim_FormCreate(void)
 * Address ranges: 004710c0-00471178
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmStarAnim_FormCreate; original record 00070366
 */

/* Named by original Delphi published-method table: TfrmStarAnim_FormCreate; original record
   00070366 */

void TfrmStarAnim_FormCreate(int param_1)

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
  puStack_18 = &UNK_00471179;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  *(undefined1 *)(param_1 + 0x2ec) = 0;
  FUN_00471290(param_1,*(undefined4 *)
                        (PTR_PTR_0047c804 +
                        (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x25) * 4),
               &puStack_8);
  FUN_00407ca8((byte *)puStack_8,(int *)&pcStack_c);
  iVar1 = FUN_004040bc("BMP",pcStack_c);
  if (iVar1 < 1) {
    *(undefined1 *)(param_1 + 0x2ec) = 1;
    FUN_00403ba4((int *)(param_1 + 0x2e8),puStack_8);
    FUN_00471194(param_1);
  }
  else {
    FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2e0) + 300),puStack_8);
    FUN_0044b72c(*(undefined4 *)(param_1 + 0x2e4),1);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &UNK_00471180;
  puStack_18 = (undefined *)0x471178;
  FUN_00403b74((int *)&pcStack_c,2);
  return;
}

