/*
 * FUN_00412330 at 00412330
 * undefined FUN_00412330(void)
 * Address ranges: 00412330-00412383
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412330(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 * 0xd0 + 0xac + DAT_0067ee20) = 0;
  iVar2 = *param_1 * 0xd0 + DAT_0067ee20;
  iVar1 = FUN_0040c9a0();
  *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(iVar1 + 8);
  param_1[0x26] = 0;
  return;
}

