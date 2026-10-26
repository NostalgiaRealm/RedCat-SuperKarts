/*
 * FUN_00408659 at 00408659
 * undefined4 __cdecl FUN_00408659(int param_1)
 * Address ranges: 00408659-00408698
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00408659(int param_1)

{
  if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
    FUN_0040187a((byte *)s__s__d____sound_buffer_index_ille_004304a4);
  }
  return *(undefined4 *)(DAT_0043d420 + 0x40 + param_1 * 0x44);
}

