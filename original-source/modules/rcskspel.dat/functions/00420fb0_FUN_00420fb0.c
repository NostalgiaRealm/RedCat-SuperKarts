/*
 * FUN_00420fb0 at 00420fb0
 * undefined FUN_00420fb0(void)
 * Address ranges: 00420fb0-00420fd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00420fb0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < DAT_00543760) {
    piVar2 = &DAT_0053f668;
    do {
      if (*piVar2 == 1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xd0;
    } while (iVar1 < DAT_00543760);
  }
  return -1;
}

