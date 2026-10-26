/*
 * FUN_004261a0 at 004261a0
 * int __cdecl FUN_004261a0(uint param_1, int param_2)
 * Address ranges: 004261a0-004262e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_004261a0(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  HANDLE hFile;
  BOOL BVar6;
  int iVar7;
  uint uVar8;
  char local_1004 [4060];
  undefined4 uStackY_28;
  
  FUN_004265d0();
  iVar7 = 0;
  if ((param_1 < DAT_0043f920) &&
     ((*(byte *)((&DAT_0043f820)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    DVar1 = FUN_00422935(param_1,0,1);
    if ((DVar1 != 0xffffffff) && (DVar2 = FUN_00422935(param_1,0,2), DVar2 != 0xffffffff)) {
      uVar8 = param_2 - DVar2;
      if ((int)uVar8 < 1) {
        if ((int)uVar8 < 0) {
          FUN_00422935(param_1,param_2,0);
          hFile = (HANDLE)FUN_004242f5(param_1);
          BVar6 = SetEndOfFile(hFile);
          iVar7 = (BVar6 != 0) - 1;
          if (iVar7 == -1) {
            _DAT_0043e2c0 = 0xd;
            DAT_0043e2c4 = GetLastError();
          }
        }
      }
      else {
        _memset(local_1004,0,0x1000);
        uStackY_28 = 0x426230;
        iVar3 = FUN_00427076(param_1,0x8000);
        do {
          uVar4 = 0x1000;
          if ((int)uVar8 < 0x1000) {
            uVar4 = uVar8;
          }
          iVar5 = FUN_00423666(param_1,local_1004,uVar4);
          if (iVar5 == -1) {
            if (DAT_0043e2c4 == 5) {
              _DAT_0043e2c0 = 0xd;
            }
            iVar7 = -1;
            break;
          }
          uVar8 = uVar8 - iVar5;
        } while (0 < (int)uVar8);
        FUN_00427076(param_1,iVar3);
      }
      FUN_00422935(param_1,DVar1,0);
      return iVar7;
    }
  }
  else {
    _DAT_0043e2c0 = 9;
  }
  return -1;
}

