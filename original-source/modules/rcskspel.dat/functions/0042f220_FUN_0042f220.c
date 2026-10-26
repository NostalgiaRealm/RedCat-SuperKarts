/*
 * FUN_0042f220 at 0042f220
 * undefined FUN_0042f220(void)
 * Address ranges: 0042f220-0042f287
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f220(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = false;
  iVar2 = FUN_004b3830(0x50);
  while (iVar2 != 0) {
    iVar2 = FUN_004b3830(0x50);
  }
  do {
    iVar2 = 0;
    do {
      iVar3 = FUN_004b3830(iVar2);
      if (iVar3 != 0) {
        bVar1 = true;
        iVar3 = FUN_004b3830(iVar2);
        while (iVar3 != 0) {
          iVar3 = FUN_004b3830(iVar2);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
  } while (!bVar1);
  FUN_00430610(2);
  return;
}

