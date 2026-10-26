/*
 * FUN_00427031 at 00427031
 * undefined4 * __cdecl FUN_00427031(int param_1)
 * Address ranges: 00427031-00427075
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __cdecl FUN_00427031(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00437130;
  if (DAT_00437134 != param_1) {
    puVar3 = puVar2;
    do {
      puVar2 = puVar3 + 3;
      if (&DAT_00437130 + DAT_004371b0 * 3 <= puVar2) break;
      piVar1 = puVar3 + 4;
      puVar3 = puVar2;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_00437130 + DAT_004371b0 * 3 <= puVar2) || (puVar2[1] != param_1)) {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

