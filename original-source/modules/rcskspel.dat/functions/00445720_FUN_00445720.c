/*
 * FUN_00445720 at 00445720
 * undefined FUN_00445720(void)
 * Address ranges: 00445720-0044573b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00445720(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = &DAT_0053f4f8;
  do {
    if (*pcVar2 == '\0') {
      return iVar1;
    }
    pcVar2 = pcVar2 + 0x24;
    iVar1 = iVar1 + 1;
  } while ((int)pcVar2 < 0x53f660);
  return -1;
}

