/*
 * FUN_00407cb0 at 00407cb0
 * undefined FUN_00407cb0(void)
 * Address ranges: 00407cb0-00407ce2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00407cb0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (DAT_00505108 != param_1) {
    puVar3 = &DAT_00505108;
    do {
      if (0x50580f < (int)puVar3) break;
      piVar1 = puVar3 + 9;
      puVar3 = puVar3 + 9;
      iVar2 = iVar2 + 1;
    } while (*piVar1 != param_1);
    if (iVar2 == 0x32) {
      iVar2 = -1;
    }
  }
  return iVar2;
}

