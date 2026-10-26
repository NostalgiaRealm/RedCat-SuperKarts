/*
 * FUN_00422500 at 00422500
 * undefined FUN_00422500(void)
 * Address ranges: 00422500-00422540
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00422500(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(int *)(DAT_006a5c38 + param_1 * 0xa9 + 0xc) * 0x44 + 0x34 + DAT_005090d0);
  iVar2 = *piVar1 + -1;
  *piVar1 = iVar2;
  if (iVar2 == 0) {
    FUN_00421f90(param_1);
  }
  return 1;
}

