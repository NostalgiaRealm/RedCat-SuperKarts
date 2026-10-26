/*
 * FUN_0041947c at 0041947c
 * HPALETTE __register FUN_0041947c(HGDIOBJ param_1, undefined4 * param_2, int param_3)
 * Address ranges: 0041947c-0041951c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HPALETTE FUN_0041947c(HGDIOBJ param_1,undefined4 *param_2,int param_3)

{
  HDC hdc;
  HGDIOBJ h;
  UINT UVar1;
  int iVar2;
  HPALETTE pHVar3;
  LOGPALETTE local_410 [128];
  
  local_410[0].palVersion = 0x300;
  if (param_1 == (HGDIOBJ)0x0) {
    local_410[0].palNumEntries = (WORD)param_3;
    FUN_0040282c(param_2,local_410[0].palPalEntry,param_3 << 2);
  }
  else {
    hdc = CreateCompatibleDC((HDC)0x0);
    h = SelectObject(hdc,param_1);
    UVar1 = GetDIBColorTable(hdc,0,0x100,(RGBQUAD *)local_410[0].palPalEntry);
    local_410[0].palNumEntries = (WORD)UVar1;
    SelectObject(hdc,h);
    DeleteDC(hdc);
  }
  if (local_410[0].palNumEntries != 0) {
    if ((local_410[0].palNumEntries != 0x10) ||
       (iVar2 = FUN_004193e4((int)local_410), (char)iVar2 == '\0')) {
      FUN_00419274((int)local_410[0].palPalEntry,(uint)local_410[0].palNumEntries);
    }
    pHVar3 = CreatePalette(local_410);
    return pHVar3;
  }
  return (HPALETTE)0x0;
}

