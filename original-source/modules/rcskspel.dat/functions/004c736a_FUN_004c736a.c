/*
 * FUN_004c736a at 004c736a
 * undefined FUN_004c736a(void)
 * Address ranges: 004c736a-004c7403
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD FUN_004c736a(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  
  if (param_1 < DAT_006b6b60) {
    iVar4 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      hFile = (HANDLE)FUN_004c0be4(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_006b66e8 = 9;
        return 0xffffffff;
      }
      DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
      if (DVar2 == 0xffffffff) {
        DVar3 = GetLastError();
      }
      else {
        DVar3 = 0;
      }
      if (DVar3 != 0) {
        FUN_004c6e51(DVar3);
        return 0xffffffff;
      }
      pbVar1 = (byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + iVar4);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar2;
    }
  }
  DAT_006b66ec = 0;
  _DAT_006b66e8 = 9;
  return 0xffffffff;
}

