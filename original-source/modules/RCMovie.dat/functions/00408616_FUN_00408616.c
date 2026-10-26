/*
 * FUN_00408616 at 00408616
 * undefined __cdecl FUN_00408616(int param_1, undefined4 param_2)
 * Address ranges: 00408616-00408658
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00408616(int param_1,undefined4 param_2)

{
  if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
    FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_0043046c);
  }
  *(undefined4 *)(DAT_0043d420 + 0x40 + param_1 * 0x44) = param_2;
  return;
}

