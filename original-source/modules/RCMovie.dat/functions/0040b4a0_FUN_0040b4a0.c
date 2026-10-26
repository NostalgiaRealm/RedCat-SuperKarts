/*
 * FUN_0040b4a0 at 0040b4a0
 * undefined4 __cdecl FUN_0040b4a0(int param_1)
 * Address ranges: 0040b4a0-0040b541
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040b4a0(int param_1)

{
  undefined4 local_8;
  
  if (DAT_0043d5b4 != 0) {
    for (local_8 = 0; local_8 < DAT_0043d5b0; local_8 = local_8 + 1) {
      if (*(int *)(DAT_0043d5ac + local_8 * 0xc) == param_1) {
        *(undefined4 *)(DAT_0043d5ac + local_8 * 0xc) = 0xffffffff;
        *(undefined4 *)(DAT_0043d5ac + 4 + local_8 * 0xc) = 0xffffffff;
        *(undefined4 *)(DAT_0043d5ac + 8 + local_8 * 0xc) = 0;
        KillTimer(DAT_0043842c,*(UINT_PTR *)(DAT_0043d5ac + local_8 * 0xc));
      }
    }
  }
  return 0;
}

