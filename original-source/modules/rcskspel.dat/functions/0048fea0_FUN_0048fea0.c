/*
 * FUN_0048fea0 at 0048fea0
 * undefined FUN_0048fea0(void)
 * Address ranges: 0048fea0-0048fee3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048fea0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
  *(undefined1 *)(DAT_0067ee30 + param_1) = 0;
  *(undefined1 *)(DAT_006a5c38 + iVar1 * 0xa9 + 0x90) = 0;
  FUN_0049f570(iVar1);
  return;
}

