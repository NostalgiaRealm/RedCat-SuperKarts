/*
 * FUN_004a23d0 at 004a23d0
 * undefined FUN_004a23d0(void)
 * Address ranges: 004a23d0-004a2409
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a23d0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0x24);
  uVar2 = *(undefined4 *)(param_2 + 0x28);
  *param_1 = *(undefined4 *)(param_2 + 0x20);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}

