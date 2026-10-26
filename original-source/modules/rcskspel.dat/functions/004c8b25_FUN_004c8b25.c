/*
 * FUN_004c8b25 at 004c8b25
 * undefined FUN_004c8b25(void)
 * Address ranges: 004c8b25-004c8b7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c8b25(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = DAT_006b66ec;
  if ((param_1 < DAT_006b6b60) &&
     ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_004c0be4(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    if (DVar2 == 0) {
      return 0;
    }
  }
  DAT_006b66ec = DVar2;
  _DAT_006b66e8 = 9;
  return 0xffffffff;
}

