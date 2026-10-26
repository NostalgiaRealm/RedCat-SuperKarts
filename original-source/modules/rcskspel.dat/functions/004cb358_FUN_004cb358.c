/*
 * FUN_004cb358 at 004cb358
 * undefined FUN_004cb358(void)
 * Address ranges: 004cb358-004cb39c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004cb358(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00503448;
  if (DAT_0050344c != param_1) {
    puVar3 = puVar2;
    do {
      puVar2 = puVar3 + 3;
      if (&DAT_00503448 + DAT_005034c8 * 3 <= puVar2) break;
      piVar1 = puVar3 + 4;
      puVar3 = puVar2;
    } while (*piVar1 != param_1);
  }
  if ((&DAT_00503448 + DAT_005034c8 * 3 <= puVar2) || (puVar2[1] != param_1)) {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

