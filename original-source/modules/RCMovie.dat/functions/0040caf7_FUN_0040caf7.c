/*
 * FUN_0040caf7 at 0040caf7
 * undefined4 __cdecl FUN_0040caf7(void * param_1)
 * Address ranges: 0040caf7-0040cb3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040caf7(void *param_1)

{
  undefined4 local_8;
  
  if (DAT_0043d6f4 != 0) {
    for (local_8 = 0; -1 < *(int *)((int)param_1 + local_8 * 4); local_8 = local_8 + 1) {
      FUN_0040c32a(param_1,*(int *)((int)param_1 + local_8 * 4));
    }
  }
  return 0;
}

