/*
 * FUN_00406951 at 00406951
 * undefined4 __cdecl FUN_00406951(int param_1)
 * Address ranges: 00406951-00406a0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00406951(int param_1)

{
  if (DAT_0043d43c != 0) {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_0042f704);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) != 0) {
      FUN_004066a0(param_1);
      (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 8))
                (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
      *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 0;
      *(undefined4 *)(DAT_0043d420 + 0x38 + param_1 * 0x44) = 0;
    }
  }
  return 0;
}

