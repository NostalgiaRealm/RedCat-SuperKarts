/*
 * FUN_0041294e at 0041294e
 * undefined4 __cdecl FUN_0041294e(int param_1)
 * Address ranges: 0041294e-004129a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041294e(int param_1)

{
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____get_control_state__con_0043486c);
  }
  return *(undefined4 *)(DAT_0043d850 + 0x10 + param_1 * 0x1c);
}

