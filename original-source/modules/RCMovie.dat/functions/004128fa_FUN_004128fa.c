/*
 * FUN_004128fa at 004128fa
 * undefined4 __cdecl FUN_004128fa(int param_1)
 * Address ranges: 004128fa-0041294d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004128fa(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_type__cont_00434824);
  }
  return *(undefined4 *)(DAT_0043d850 + 8 + param_1 * 0x1c);
}

