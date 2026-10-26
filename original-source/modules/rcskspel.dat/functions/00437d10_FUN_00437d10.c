/*
 * FUN_00437d10 at 00437d10
 * undefined FUN_00437d10(void)
 * Address ranges: 00437d10-00437d44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437d10(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar3 = 0;
  if (0 < DAT_00508610) {
    do {
      if (cVar1 != '\0') {
        return;
      }
      uVar2 = FUN_00437ea0(iVar3);
      cVar1 = FUN_00437cc0(uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00508610);
  }
  return;
}

