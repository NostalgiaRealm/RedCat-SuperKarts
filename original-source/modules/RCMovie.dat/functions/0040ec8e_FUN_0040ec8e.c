/*
 * FUN_0040ec8e at 0040ec8e
 * int __cdecl FUN_0040ec8e(int param_1)
 * Address ranges: 0040ec8e-0040ed2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0040ed2a) */

int __cdecl FUN_0040ec8e(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = 1;
  }
  else {
    if (DAT_0043d7ec == 0) {
      FUN_0040187a((byte *)s_s__d____error_attempting_to_find_00432c60);
    }
    for (; DAT_0043d7fc != DAT_0043d79c; DAT_0043d7fc = DAT_0043d7fc + 1) {
      if (*(int *)(DAT_0043d798 + 4 + DAT_0043d7fc * 8) == 3) {
        iVar1 = DAT_0043d7fc + 0x41;
        DAT_0043d7fc = DAT_0043d7fc + 1;
        return iVar1;
      }
    }
    iVar1 = -1;
  }
  DAT_0043d7fc = 0;
  return iVar1;
}

