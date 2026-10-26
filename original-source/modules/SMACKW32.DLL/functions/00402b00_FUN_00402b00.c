/*
 * FUN_00402b00 at 00402b00
 * undefined __stdcall FUN_00402b00(void)
 * Address ranges: 00402b00-00402bdc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402b00(void)

{
  UINT uMode;
  
  uMode = SetErrorMode(0x8000);
  DAT_0040e800 = LoadLibraryA(s_WING32_DLL_0040e058);
  SetErrorMode(uMode);
  if ((HMODULE)0x1f < DAT_0040e800) {
    DAT_00410458 = GetProcAddress(DAT_0040e800,s_WinGCreateDC_0040e064);
    DAT_00410460 = GetProcAddress(DAT_0040e800,s_WinGCreateBitmap_0040e074);
    DAT_00410450 = GetProcAddress(DAT_0040e800,s_WinGBitBlt_0040e088);
    DAT_0041044c = GetProcAddress(DAT_0040e800,s_WinGStretchBlt_0040e094);
    DAT_0041045c = GetProcAddress(DAT_0040e800,s_WinGRecommendDIBFormat_0040e0a4);
    DAT_00410454 = GetProcAddress(DAT_0040e800,s_WinGSetDIBColorTable_0040e0bc);
    return;
  }
  DAT_0040e800 = (HMODULE)0x1;
  return;
}

