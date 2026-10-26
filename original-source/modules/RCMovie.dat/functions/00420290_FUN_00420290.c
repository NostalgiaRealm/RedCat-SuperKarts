/*
 * FUN_00420290 at 00420290
 * undefined FUN_00420290(void)
 * Address ranges: 00420290-004202b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00420290(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(uint *)(param_1 + 4) & 6) != 0) {
    *param_4 = param_2;
    uVar1 = 3;
  }
  return uVar1;
}

