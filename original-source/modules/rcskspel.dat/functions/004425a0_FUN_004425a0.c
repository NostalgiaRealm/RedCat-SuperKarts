/*
 * FUN_004425a0 at 004425a0
 * undefined FUN_004425a0(void)
 * Address ranges: 004425a0-004425ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004425a0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < _DAT_0053d33c) {
    piVar2 = (int *)0x53d218;
    do {
      if ((*piVar2 + -1 <= DAT_0053be40) && (DAT_0053be40 <= *piVar2 + 1)) {
        return 0;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < _DAT_0053d33c);
  }
  *(int *)(_DAT_0053d33c * 4 + 0x53d218) = DAT_0053be40;
  _DAT_0053d33c = _DAT_0053d33c + 1;
  return 1;
}

