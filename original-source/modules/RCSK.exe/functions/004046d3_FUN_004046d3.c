/*
 * FUN_004046d3 at 004046d3
 * undefined4 __cdecl FUN_004046d3(uint param_1)
 * Address ranges: 004046d3-00404729
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004046d3(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = DAT_00408c08;
  if ((param_1 < DAT_0040a120) &&
     ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_00404696(param_1);
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
  DAT_00408c08 = DVar2;
  DAT_00408c04 = 9;
  return 0xffffffff;
}

