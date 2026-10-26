/*
 * FUN_00422460 at 00422460
 * undefined FUN_00422460(void)
 * Address ranges: 00422460-004224ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00422460(int param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_004a0620(param_1);
  piVar1 = (int *)(*(int *)(DAT_006a5c38 + param_1 * 0xa9 + 0xc) * 0x44 + 0x34 + DAT_005090d0);
  iVar2 = *piVar1 + -1;
  *piVar1 = iVar2;
  if (iVar2 == 0) {
    FUN_00421f90(param_1);
  }
  return 1;
}

