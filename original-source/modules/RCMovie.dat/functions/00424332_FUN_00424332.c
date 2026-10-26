/*
 * FUN_00424332 at 00424332
 * undefined4 __cdecl FUN_00424332(uint param_1)
 * Address ranges: 00424332-00424388
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00424332(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = DAT_0043e2c4;
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_004242f5(param_1);
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
  DAT_0043e2c4 = DVar2;
  _DAT_0043e2c0 = 9;
  return 0xffffffff;
}

