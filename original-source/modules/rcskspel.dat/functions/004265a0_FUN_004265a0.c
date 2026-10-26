/*
 * FUN_004265a0 at 004265a0
 * undefined FUN_004265a0(void)
 * Address ranges: 004265a0-004265d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004265a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_00426540(iVar2);
    if (*(int *)(&DAT_0050f8b4 + iVar1 * 0x1910) == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  return -1;
}

