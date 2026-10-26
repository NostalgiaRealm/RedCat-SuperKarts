/*
 * FUN_004458c0 at 004458c0
 * undefined FUN_004458c0(void)
 * Address ranges: 004458c0-004458f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004458c0(void)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_0053f4fc;
  do {
    if (puVar2[-4] != '\0') {
      cVar1 = FUN_00445650(puVar2);
      if (cVar1 != '\0') {
        FUN_00445800(iVar3);
      }
    }
    puVar2 = puVar2 + 0x24;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x53f664);
  return;
}

