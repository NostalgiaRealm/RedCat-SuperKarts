/*
 * FUN_0040b542 at 0040b542
 * undefined4 __stdcall FUN_0040b542(void)
 * Address ranges: 0040b542-0040b5c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040b542(void)

{
  int local_8;
  
  if (DAT_0043d5b4 != 0) {
    for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
      if (((*(int *)(DAT_0043d5ac + local_8 * 0xc) != -1) &&
          (*(int *)(DAT_0043d5ac + 4 + local_8 * 0xc) != -1)) &&
         (*(int *)(DAT_0043d5ac + 8 + local_8 * 0xc) != 0)) {
        FUN_0040b4a0(*(int *)(DAT_0043d5ac + local_8 * 0xc));
      }
    }
  }
  return 0;
}

