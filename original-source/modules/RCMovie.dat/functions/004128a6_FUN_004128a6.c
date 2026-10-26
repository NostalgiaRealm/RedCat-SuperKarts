/*
 * FUN_004128a6 at 004128a6
 * undefined4 __cdecl FUN_004128a6(int param_1)
 * Address ranges: 004128a6-004128f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004128a6(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_old_control_state__004347d8);
  }
  return *(undefined4 *)(DAT_0043d850 + 0x14 + param_1 * 0x1c);
}

