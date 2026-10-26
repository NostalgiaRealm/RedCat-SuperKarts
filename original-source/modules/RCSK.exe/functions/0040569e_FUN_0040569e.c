/*
 * FUN_0040569e at 0040569e
 * int __cdecl FUN_0040569e(uint param_1, int param_2)
 * Address ranges: 0040569e-004057e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0040569e(uint param_1,int param_2)

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
  
  FUN_00405c60();
  iVar7 = 0;
  if ((param_1 < DAT_0040a120) &&
     ((*(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    DVar1 = FUN_004021bf(param_1,0,1);
    if ((DVar1 != 0xffffffff) && (DVar2 = FUN_004021bf(param_1,0,2), DVar2 != 0xffffffff)) {
      uVar8 = param_2 - DVar2;
      if ((int)uVar8 < 1) {
        if ((int)uVar8 < 0) {
          FUN_004021bf(param_1,param_2,0);
          hFile = (HANDLE)FUN_00404696(param_1);
          BVar6 = SetEndOfFile(hFile);
          iVar7 = (BVar6 != 0) - 1;
          if (iVar7 == -1) {
            DAT_00408c04 = 0xd;
            DAT_00408c08 = GetLastError();
          }
        }
      }
      else {
        _memset(local_1004,0,0x1000);
        uStackY_28 = 0x40572e;
        iVar3 = FUN_00405be8(param_1,0x8000);
        do {
          uVar4 = 0x1000;
          if ((int)uVar8 < 0x1000) {
            uVar4 = uVar8;
          }
          iVar5 = FUN_0040289a(param_1,local_1004,uVar4);
          if (iVar5 == -1) {
            if (DAT_00408c08 == 5) {
              DAT_00408c04 = 0xd;
            }
            iVar7 = -1;
            break;
          }
          uVar8 = uVar8 - iVar5;
        } while (0 < (int)uVar8);
        FUN_00405be8(param_1,iVar3);
      }
      FUN_004021bf(param_1,DVar1,0);
      return iVar7;
    }
  }
  else {
    DAT_00408c04 = 9;
  }
  return -1;
}

