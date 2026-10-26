/*
 * FUN_00428460 at 00428460
 * undefined FUN_00428460(void)
 * Address ranges: 00428460-0042848e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00428460(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_00427ed0(iVar2);
    if (*(int *)(&DAT_00535148 + iVar1 * 300) == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x46);
  return -1;
}

