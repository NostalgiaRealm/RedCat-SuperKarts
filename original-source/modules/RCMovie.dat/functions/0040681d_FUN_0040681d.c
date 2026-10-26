/*
 * FUN_0040681d at 0040681d
 * undefined4 __stdcall FUN_0040681d(void)
 * Address ranges: 0040681d-00406872
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040681d(void)

{
  undefined4 local_8;
  
  if (DAT_0043d43c != 0) {
    for (local_8 = 0; local_8 < DAT_0043d414; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) {
        FUN_004066a0(local_8);
      }
    }
  }
  return 0;
}

