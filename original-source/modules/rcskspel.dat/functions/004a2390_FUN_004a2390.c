/*
 * FUN_004a2390 at 004a2390
 * undefined FUN_004a2390(void)
 * Address ranges: 004a2390-004a23c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2390(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0x14);
  uVar2 = *(undefined4 *)(param_2 + 0x18);
  *param_1 = *(undefined4 *)(param_2 + 0x10);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}

