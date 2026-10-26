/*
 * FUN_004a16d0 at 004a16d0
 * undefined FUN_004a16d0(void)
 * Address ranges: 004a16d0-004a16e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a16d0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

