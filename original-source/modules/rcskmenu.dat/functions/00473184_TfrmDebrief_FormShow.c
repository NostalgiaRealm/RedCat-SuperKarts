/*
 * TfrmDebrief_FormShow at 00473184
 * undefined TfrmDebrief_FormShow(void)
 * Address ranges: 00473184-004731c6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDebrief_FormShow; original record 00070bc3
 */

/* Named by original Delphi published-method table: TfrmDebrief_FormShow; original record 00070bc3
    */

void TfrmDebrief_FormShow(int param_1)

{
  char cVar1;
  
  FUN_004731c8(param_1,*(undefined4 *)(param_1 + 0x330));
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x03') {
    (**(code **)(**(int **)(param_1 + 0x2e8) + 0xb0))();
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x2e4) + 0xb0))();
  return;
}

