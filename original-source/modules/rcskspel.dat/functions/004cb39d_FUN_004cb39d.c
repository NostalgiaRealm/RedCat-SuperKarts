/*
 * FUN_004cb39d at 004cb39d
 * undefined FUN_004cb39d(void)
 * Address ranges: 004cb39d-004cb4e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004cb39d(uint param_1,int param_2)

{
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  int iVar3;
  undefined1 local_1004 [4060];
  undefined4 uStackY_28;
  uint uStackY_24;
  uint uStackY_20;
  
  FUN_004c0200();
  iVar3 = 0;
  if ((param_1 < DAT_006b6b60) &&
     ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    iVar1 = FUN_004c736a();
    if ((iVar1 != -1) && (iVar1 = FUN_004c736a(), iVar1 != -1)) {
      param_2 = param_2 - iVar1;
      if (param_2 < 1) {
        if (param_2 < 0) {
          uStackY_20 = 0x4cb48c;
          FUN_004c736a();
          uStackY_20 = param_1;
          uStackY_24 = 0x4cb492;
          hFile = (HANDLE)FUN_004c0be4();
          BVar2 = SetEndOfFile(hFile);
          iVar3 = (BVar2 != 0) - 1;
          if (iVar3 == -1) {
            _DAT_006b66e8 = 0xd;
            DAT_006b66ec = GetLastError();
          }
        }
      }
      else {
        uStackY_20 = 0x4cb422;
        _memset(local_1004,0,0x1000);
        uStackY_20 = 0x8000;
        uStackY_24 = param_1;
        uStackY_28 = 0x4cb42d;
        FUN_004cb81d();
        do {
          uStackY_20 = 0x4cb44c;
          iVar1 = FUN_004c37d3();
          if (iVar1 == -1) {
            if (DAT_006b66ec == 5) {
              _DAT_006b66e8 = 0xd;
            }
            iVar3 = -1;
            break;
          }
          param_2 = param_2 - iVar1;
        } while (0 < param_2);
        FUN_004cb81d();
      }
      uStackY_20 = 0x4cb4ca;
      FUN_004c736a();
      return iVar3;
    }
  }
  else {
    _DAT_006b66e8 = 9;
  }
  return -1;
}

