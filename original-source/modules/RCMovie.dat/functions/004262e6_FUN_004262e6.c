/*
 * FUN_004262e6 at 004262e6
 * undefined4 __cdecl FUN_004262e6(undefined4 param_1)
 * Address ranges: 004262e6-00426300
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004262e6(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_0043e57c != (code *)0x0) {
    iVar1 = (*DAT_0043e57c)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

