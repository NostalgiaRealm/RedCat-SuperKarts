/*
 * FUN_004b3bc0 at 004b3bc0
 * undefined FUN_004b3bc0(void)
 * Address ranges: 004b3bc0-004b3bdb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b3bc0(void)

{
  int iVar1;
  
  iVar1 = FUN_004b3a20(0x14);
  if (iVar1 == 0) {
    DirectSoundEnumerateA(FUN_004b3aa0,0);
    iVar1 = 0;
  }
  return iVar1;
}

