/*
 * FUN_00451af0 at 00451af0
 * undefined __register FUN_00451af0(int * param_1, int * param_2, int * param_3)
 * Address ranges: 00451af0-00451c57;00451c88-00451c8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451af0(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  HPALETTE hPal;
  HDC pHVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HDC hdcDest;
  undefined4 *in_FS_OFFSET;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  void *lpBits;
  BITMAPINFO *lpbmi;
  UINT iUsage;
  DWORD DVar12;
  undefined4 uVar13;
  BOOL bForceBkgd;
  
  if (param_1[0x1f] < 1) {
    return;
  }
  iVar2 = FUN_00451ea0((int)param_1);
  if (0 < iVar2) {
    bForceBkgd = 0;
    hPal = (HPALETTE)(**(code **)(*param_1 + 0x24))();
    pHVar3 = (HDC)FUN_00418994(param_2);
    SelectPalette(pHVar3,hPal,bForceBkgd);
    pHVar3 = (HDC)FUN_00418994(param_2);
    RealizePalette(pHVar3);
  }
  *in_FS_OFFSET = &stack0xffffffd8;
  iVar2 = 3;
  pHVar3 = (HDC)FUN_00418994(param_2);
  iVar2 = SetStretchBltMode(pHVar3,iVar2);
  uVar13 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffcc;
  GdiFlush();
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    if (*(char *)(param_1[9] + 0x42c) == '\0') {
      DVar12 = param_2[8];
      iVar4 = param_1[0x10];
      iVar11 = param_1[0x23];
      iVar10 = 0;
      iVar9 = 0;
      pHVar3 = *(HDC *)(param_1[9] + 0x420);
      iVar5 = param_3[3] - param_3[1];
      iVar7 = *param_3;
      iVar6 = param_3[2] - iVar7;
      iVar8 = param_3[1];
      hdcDest = (HDC)FUN_00418994(param_2);
      StretchBlt(hdcDest,iVar7,iVar8,iVar6,iVar5,pHVar3,iVar9,iVar10,iVar11,iVar4,DVar12);
    }
    else {
      DVar12 = param_2[8];
      iUsage = 0;
      lpbmi = *(BITMAPINFO **)(param_1[9] + 0xc);
      lpBits = *(void **)(param_1[9] + 0x440);
      iVar4 = param_1[0x10];
      iVar11 = param_1[0x23];
      iVar10 = 0;
      iVar9 = 0;
      iVar5 = param_3[3] - param_3[1];
      iVar7 = *param_3;
      iVar6 = param_3[2] - iVar7;
      iVar8 = param_3[1];
      pHVar3 = (HDC)FUN_00418994(param_2);
      StretchDIBits(pHVar3,iVar7,iVar8,iVar6,iVar5,iVar9,iVar10,iVar11,iVar4,lpBits,lpbmi,iUsage,
                    DVar12);
    }
  }
  else {
    iVar4 = FUN_00451ed0((int)param_1);
    FUN_00450024(param_2,param_3,(int)param_1,iVar4);
  }
  *in_FS_OFFSET = uVar13;
  pHVar3 = (HDC)FUN_00418994(param_2);
  SetStretchBltMode(pHVar3,iVar2);
  return;
}

