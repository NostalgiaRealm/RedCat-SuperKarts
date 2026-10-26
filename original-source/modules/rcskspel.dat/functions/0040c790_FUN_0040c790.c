/*
 * FUN_0040c790 at 0040c790
 * undefined FUN_0040c790(void)
 * Address ranges: 0040c790-0040c81f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_0040c790(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  iVar1 = FUN_004be6c9();
  param_1[3] = iVar1 % 7;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return param_1;
}

