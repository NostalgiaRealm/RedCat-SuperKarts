/*
 * FUN_00407e4b at 00407e4b
 * undefined4 __cdecl FUN_00407e4b(int param_1, undefined4 param_2)
 * Address ranges: 00407e4b-00407f2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00407e4b(int param_1,undefined4 param_2)

{
  uint local_c;
  int local_8;
  
  if (DAT_0043d43c != 0) {
    local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x24))
                        (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),&local_c);
    if (local_8 != 0) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_playing_sound__d___00430270);
    }
    if (((local_c & 1) != 1) &&
       (local_8 = (**(code **)(**(int **)(DAT_0043d420 + 0x28 + param_1 * 0x44) + 0x30))
                            (*(undefined4 *)(DAT_0043d420 + 0x28 + param_1 * 0x44),0,0,param_2),
       local_8 != 0)) {
      FUN_00405af0(local_8);
      FUN_0040187a((byte *)s__s__d____error_playing_sound__d___004302a4);
    }
  }
  return 0;
}

