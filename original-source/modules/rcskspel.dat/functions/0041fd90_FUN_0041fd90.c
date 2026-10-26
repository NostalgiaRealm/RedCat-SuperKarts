/*
 * FUN_0041fd90 at 0041fd90
 * undefined FUN_0041fd90(void)
 * Address ranges: 0041fd90-0041fe4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041fd90(void)

{
  DWORD DVar1;
  int iVar2;
  
  if (DAT_004e3a80 == 0xffffffff) {
    DAT_004e3a80 = GetTickCount();
  }
  DVar1 = GetTickCount();
  if (DVar1 - DAT_004e3a80 < 0x5dc) {
    return 0;
  }
  if ((DAT_0053b9f0 != 0) && (DAT_005086a4 == 0)) {
    FUN_00423230(1);
    DAT_005086a4 = 1;
  }
  DVar1 = GetTickCount();
  if (DVar1 - DAT_004e3a80 < 0x1f41) {
    iVar2 = FUN_004b3830(0x1b);
    if (iVar2 == 0) {
      iVar2 = FUN_004b3830(0xd);
      if (iVar2 == 0) {
        iVar2 = FUN_004b3830(0x20);
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
    do {
      do {
        do {
          iVar2 = FUN_004b3830(0x1b);
        } while (iVar2 != 0);
        iVar2 = FUN_004b3830(0xd);
      } while (iVar2 != 0);
      iVar2 = FUN_004b3830(0x20);
    } while (iVar2 != 0);
  }
  return 1;
}

