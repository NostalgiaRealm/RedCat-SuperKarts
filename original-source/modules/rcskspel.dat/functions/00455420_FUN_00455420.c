/*
 * FUN_00455420 at 00455420
 * undefined FUN_00455420(void)
 * Address ranges: 00455420-00455440
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00455420(undefined4 *param_1)

{
  FUN_0044fa10(4);
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[8] = 0xffffffff;
  param_1[9] = 0xffffffff;
  *param_1 = &PTR_FUN_004d27f8;
  return param_1;
}

