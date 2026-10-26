/*
 * FUN_00407580 at 00407580
 * undefined FUN_00407580(void)
 * Address ranges: 00407580-004075bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00407580(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (DAT_00503ef0 != param_1) {
    puVar3 = &DAT_00503ef0;
    do {
      if (DAT_00508610 <= iVar2) break;
      piVar1 = puVar3 + 0x47;
      puVar3 = puVar3 + 0x47;
      iVar2 = iVar2 + 1;
    } while (*piVar1 != param_1);
  }
  if (iVar2 == DAT_00508610) {
    iVar2 = -1;
  }
  return iVar2;
}

