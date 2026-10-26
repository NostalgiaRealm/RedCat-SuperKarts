/*
 * FUN_0040664a at 0040664a
 * undefined4 __stdcall FUN_0040664a(void)
 * Address ranges: 0040664a-0040669f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040664a(void)

{
  undefined4 local_8;
  
  if (DAT_0043d43c != 0) {
    for (local_8 = 0; local_8 < DAT_0043d414; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d420 + 0x30 + local_8 * 0x44) != 0) {
        FUN_004063fa(local_8);
      }
    }
  }
  return 0;
}

