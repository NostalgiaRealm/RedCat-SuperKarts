/*
 * FUN_0040cb40 at 0040cb40
 * undefined4 __stdcall FUN_0040cb40(void)
 * Address ranges: 0040cb40-0040cb81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040cb40(void)

{
  undefined4 local_8;
  
  if (DAT_0043d6f4 != 0) {
    for (local_8 = (void *)0x0; (int)local_8 < DAT_00431b64; local_8 = (void *)((int)local_8 + 1)) {
      FUN_0040c32a(local_8,(int)local_8);
    }
  }
  return 0;
}

