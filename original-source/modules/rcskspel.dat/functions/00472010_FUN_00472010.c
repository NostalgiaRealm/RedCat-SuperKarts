/*
 * FUN_00472010 at 00472010
 * undefined FUN_00472010(void)
 * Address ranges: 00472010-0047202b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00472010(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = &DAT_00544bc0;
  do {
    if (*pcVar2 == '\0') {
      return iVar1;
    }
    pcVar2 = pcVar2 + 0xe;
    iVar1 = iVar1 + 1;
  } while ((int)pcVar2 < 0x544d80);
  return -1;
}

