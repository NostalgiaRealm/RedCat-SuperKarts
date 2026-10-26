/*
 * FUN_00415b90 at 00415b90
 * undefined FUN_00415b90(void)
 * Address ranges: 00415b90-00415bdf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415b90(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_004906b0(param_3);
  iVar1 = DAT_006a5c38 + iVar1 * 0xa9;
  *param_1 = *(undefined4 *)(iVar1 + 0x50);
  param_1[1] = *(undefined4 *)(iVar1 + 0x54);
  param_1[2] = *(undefined4 *)(iVar1 + 0x58);
  return;
}

