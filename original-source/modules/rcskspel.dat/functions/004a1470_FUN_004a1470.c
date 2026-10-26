/*
 * FUN_004a1470 at 004a1470
 * undefined FUN_004a1470(void)
 * Address ranges: 004a1470-004a148c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a1470(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar3 = 1;
  iVar2 = 0;
  do {
    if ((param_1 & uVar3) != 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    uVar3 = uVar3 << 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x20);
  return iVar1;
}

