/*
 * FUN_0040c820 at 0040c820
 * undefined FUN_0040c820(void)
 * Address ranges: 0040c820-0040c8ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_0040c820(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = param_2;
  uVar1 = FUN_004503c0();
  param_1[1] = uVar1;
  uVar1 = FUN_004500b0();
  param_1[2] = uVar1;
  iVar2 = FUN_004be6c9();
  param_1[3] = iVar2 % 7;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return param_1;
}

