/*
 * FUN_00418e33 at 00418e33
 * undefined __cdecl FUN_00418e33(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00418e33-00418e75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418e33(undefined4 param_1,undefined4 param_2)

{
  if ((1.0 < (double)CONCAT44(param_2,param_1)) || ((double)CONCAT44(param_2,param_1) < 0.05)) {
    FUN_0040187a((byte *)s__set_joystick_sencesibility__inv_00435e08);
  }
  _DAT_00435c40 = param_1;
  _DAT_00435c44 = param_2;
  return;
}

