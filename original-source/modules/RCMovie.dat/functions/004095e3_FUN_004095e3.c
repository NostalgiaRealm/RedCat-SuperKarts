/*
 * FUN_004095e3 at 004095e3
 * undefined4 __cdecl FUN_004095e3(int param_1)
 * Address ranges: 004095e3-0040976a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004095e3(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    if ((param_1 < 0) || (DAT_0043d414 < param_1)) {
      FUN_0040187a((byte *)s__s__d____illegal_sound_buffer_in_00430dbc);
    }
    if (*(int *)(DAT_0043d420 + 0x30 + param_1 * 0x44) == 0) {
      uVar1 = 0;
    }
    else {
      local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                          (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
      if (local_8 != 0) {
        FUN_00405af0(local_8);
        FUN_0040187a((byte *)s__s__d____getting_sound_status_fa_00430dfc);
      }
      if ((local_c & 1) == 1) {
        local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x48))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
        if (local_8 != 0) {
          FUN_00405af0(local_8);
          FUN_0040187a((byte *)s__s__d____error_releasing_sound_b_00430e38);
        }
        (**(code **)(**(int **)(DAT_0043d420 + 0x2c + param_1 * 0x44) + 8))
                  (*(undefined4 *)(DAT_0043d420 + 0x2c + param_1 * 0x44));
        (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 8))
                  (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44));
        *(undefined4 *)(DAT_0043d420 + 0x30 + param_1 * 0x44) = 0;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

