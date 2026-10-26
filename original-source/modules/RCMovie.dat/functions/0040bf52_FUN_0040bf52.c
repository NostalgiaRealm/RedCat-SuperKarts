/*
 * FUN_0040bf52 at 0040bf52
 * undefined4 __stdcall FUN_0040bf52(void)
 * Address ranges: 0040bf52-0040bfeb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040bf52(void)

{
  void *local_8;
  
  if ((DAT_0043d6f0 != 0) && (DAT_0043d6f4 != 0)) {
    for (local_8 = (void *)0x0; (int)local_8 < DAT_00431b64; local_8 = (void *)((int)local_8 + 1)) {
      FUN_0040c32a(local_8,(int)local_8);
    }
    if (DAT_0043d6f0 != 0) {
      if (DAT_0043d6e8 != (LPVOID)0x0) {
        FUN_0041fd93(DAT_0043d6e8);
      }
      DAT_0043d6f0 = 0;
    }
    DAT_00431b64 = -1;
    DAT_0043d6e8 = (LPVOID)0x0;
    DAT_0043d6f4 = 0;
  }
  return 0;
}

