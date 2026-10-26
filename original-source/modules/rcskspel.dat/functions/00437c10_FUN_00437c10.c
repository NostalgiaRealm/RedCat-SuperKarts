/*
 * FUN_00437c10 at 00437c10
 * undefined FUN_00437c10(void)
 * Address ranges: 00437c10-00437c39
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437c10(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00437550();
  if (cVar1 != '\0') {
    iVar2 = 0;
    do {
      FUN_00436760();
      iVar2 = iVar2 + 0x44;
    } while (iVar2 < 0x2ec);
  }
  return;
}

