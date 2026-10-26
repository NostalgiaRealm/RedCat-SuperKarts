/*
 * FUN_004021bf at 004021bf
 * DWORD __cdecl FUN_004021bf(uint param_1, LONG param_2, DWORD param_3)
 * Address ranges: 004021bf-00402258
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD __cdecl FUN_004021bf(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 < DAT_0040a120) {
    iVar4 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      hFile = (HANDLE)FUN_00404696(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        DAT_00408c04 = 9;
        return 0xffffffff;
      }
      DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
      if (DVar2 == 0xffffffff) {
        uVar3 = GetLastError();
      }
      else {
        uVar3 = 0;
      }
      if (uVar3 != 0) {
        FUN_00402a47(uVar3);
        return 0xffffffff;
      }
      pbVar1 = (byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + iVar4);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar2;
    }
  }
  DAT_00408c08 = 0;
  DAT_00408c04 = 9;
  return 0xffffffff;
}

