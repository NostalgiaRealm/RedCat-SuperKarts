/*
 * FUN_0042f290 at 0042f290
 * undefined FUN_0042f290(void)
 * Address ranges: 0042f290-0042f34a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f290(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = false;
  iVar3 = FUN_004b3830(0x1b);
  while (iVar3 != 0) {
    iVar3 = FUN_004b3830(0x1b);
  }
  FUN_004707f0();
  cVar2 = FUN_00471740();
  if (cVar2 == '\0') {
    while( true ) {
      iVar3 = FUN_004b3830(0x4a);
      if ((iVar3 != 0) || (iVar3 = FUN_004b3830(0x59), iVar3 != 0)) {
        bVar1 = true;
        FUN_0042f740(4);
      }
      iVar3 = FUN_004b3830(0x1b);
      if ((iVar3 != 0) || (iVar3 = FUN_004b3830(0x4e), iVar3 != 0)) break;
      if (bVar1) {
        return;
      }
    }
    iVar3 = FUN_004b3830(0x1b);
    while (iVar3 != 0) {
      iVar3 = FUN_004b3830(0x1b);
    }
    return;
  }
  cVar2 = FUN_00473780();
  if (cVar2 == '\0') {
    FUN_0042f740(0);
    return;
  }
  FUN_0042f740(4);
  return;
}

