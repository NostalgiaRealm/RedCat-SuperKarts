/*
 * FUN_0041e6f0 at 0041e6f0
 * undefined4 __cdecl FUN_0041e6f0(int param_1)
 * Address ranges: 0041e6f0-0041e714
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041e6f0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_0043e210;
  do {
    if (*piVar1 == param_1) {
      return (&DAT_0043e214)[iVar2 * 2];
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x43e2b0);
  return 0;
}

