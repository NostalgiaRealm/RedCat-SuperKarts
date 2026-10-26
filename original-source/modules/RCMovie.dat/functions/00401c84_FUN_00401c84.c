/*
 * FUN_00401c84 at 00401c84
 * undefined1 __cdecl FUN_00401c84(int param_1)
 * Address ranges: 00401c84-00401cc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 __cdecl FUN_00401c84(int param_1)

{
  undefined1 local_8;
  
  if ((((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) || (param_1 == 3)) {
    DAT_0042c348 = param_1;
    local_8 = 1;
  }
  else {
    local_8 = 0;
    DAT_0042c348 = 0;
  }
  return local_8;
}

