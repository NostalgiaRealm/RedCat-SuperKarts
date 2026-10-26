/*
 * FUN_004113c0 at 004113c0
 * undefined FUN_004113c0(void)
 * Address ranges: 004113c0-00411405
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004113c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_1 * 0x50 + 8 + DAT_00680ae0;
  uVar2 = *(undefined4 *)(param_1 * 0x50 + 8 + DAT_00680ae0);
  uVar3 = *(undefined4 *)(iVar1 + 8);
  param_2[1] = *(undefined4 *)(iVar1 + 4);
  *param_2 = uVar2;
  param_2[2] = uVar3;
  return 1;
}

