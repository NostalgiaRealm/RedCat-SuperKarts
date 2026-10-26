/*
 * FUN_004289d0 at 004289d0
 * undefined FUN_004289d0(void)
 * Address ranges: 004289d0-004289f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004289d0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_00427ed0(iVar2);
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_00535148 + iVar1 * 300) = 0;
  } while (iVar2 < 0x46);
  return;
}

