/*
 * FUN_0044f288 at 0044f288
 * bool __register FUN_0044f288(uint param_1, uint param_2, ushort param_3)
 * Address ranges: 0044f288-0044f2fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0044f288(uint param_1,uint param_2,ushort param_3)

{
  LONG LVar1;
  BOOL BVar2;
  DWORD iModeNum;
  bool bVar3;
  DEVMODEA local_ae;
  
  bVar3 = false;
  iModeNum = 0;
  while( true ) {
    if (bVar3 != false) {
      return bVar3;
    }
    BVar2 = EnumDisplaySettingsA((LPCSTR)0x0,iModeNum,&local_ae);
    if (BVar2 == 0) break;
    if ((((param_1 & 0xffff) == local_ae.dmPelsWidth) &&
        ((param_2 & 0xffff) == local_ae.dmPelsHeight)) && (param_3 == local_ae.dmBitsPerPel)) {
      local_ae.dmFields = 0x1c0000;
      LVar1 = ChangeDisplaySettingsA(&local_ae,0);
      bVar3 = LVar1 == 0;
    }
    if (bVar3 == false) {
      iModeNum = iModeNum + 1;
    }
  }
  return false;
}

