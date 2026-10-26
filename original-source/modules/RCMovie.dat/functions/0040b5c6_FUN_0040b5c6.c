/*
 * FUN_0040b5c6 at 0040b5c6
 * undefined4 __cdecl FUN_0040b5c6(int param_1)
 * Address ranges: 0040b5c6-0040b643
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040b5c6(int param_1)

{
  int local_8;
  
  if (DAT_0043d5b4 != 0) {
    for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
      if (((*(int *)(DAT_0043d5ac + local_8 * 0xc) == param_1) &&
          (*(int *)(DAT_0043d5ac + 4 + local_8 * 0xc) != -1)) &&
         (*(int *)(DAT_0043d5ac + 8 + local_8 * 0xc) != 0)) {
        (**(code **)(DAT_0043d5ac + 8 + local_8 * 0xc))();
      }
    }
  }
  return 0;
}

