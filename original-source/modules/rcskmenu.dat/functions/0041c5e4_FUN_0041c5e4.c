/*
 * FUN_0041c5e4 at 0041c5e4
 * BOOL __register FUN_0041c5e4(HPALETTE param_1, HPALETTE param_2, COLORREF param_3)
 * Address ranges: 0041c5e4-0041c796;0041c79e-0041c7de;0041c7e6-0041c7ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

BOOL FUN_0041c5e4(HPALETTE param_1,HPALETTE param_2,COLORREF param_3)

{
  int iVar1;
  HDC pHVar2;
  COLORREF color;
  BOOL BVar3;
  int *in_FS_OFFSET;
  int iVar4;
  undefined1 local_74 [4];
  int local_70;
  int local_6c;
  int local_60;
  undefined4 local_5c;
  HGDIOBJ local_20;
  HGDIOBJ local_1c;
  char local_15;
  HDC local_14;
  HDC local_10;
  HDC local_c;
  HBITMAP local_8;
  
  local_8 = (HBITMAP)0x0;
  if (param_1 != (HPALETTE)0x0) {
    iVar1 = GetObjectA(param_1,0x54,local_74);
    if (iVar1 != 0) {
      FUN_0041bae0((int)param_1);
      local_c = (HDC)0x0;
      local_14 = (HDC)0x0;
      iVar1 = *in_FS_OFFSET;
      *in_FS_OFFSET = (int)&stack0xffffff74;
      pHVar2 = GetDC((HWND)0x0);
      local_c = (HDC)FUN_00418d8c((int)pHVar2);
      pHVar2 = CreateCompatibleDC(local_c);
      local_14 = (HDC)FUN_00418d8c((int)pHVar2);
      iVar4 = local_70;
      local_8 = CreateBitmap(local_70,local_6c,1,1,(void *)0x0);
      if (local_8 != (HBITMAP)0x0) {
        local_20 = SelectObject(local_14,local_8);
        if (param_3 != 0x1fffffff) {
          pHVar2 = CreateCompatibleDC(local_c);
          local_10 = (HDC)FUN_00418d8c((int)pHVar2);
          *in_FS_OFFSET = (int)&stack0xffffff68;
          if (local_60 == 0) {
            local_15 = '\0';
          }
          else {
            local_15 = '\x01';
            local_5c = 0;
            iVar4 = 0;
            param_1 = FUN_0041bf24((HBITMAP)param_1,param_2,param_2,0,(int)local_74);
          }
          local_1c = SelectObject(local_10,param_1);
          if (param_2 != (HPALETTE)0x0) {
            SelectPalette(local_10,param_2,0);
            RealizePalette(local_10);
            SelectPalette(local_14,param_2,0);
            RealizePalette(local_14);
          }
          color = SetBkColor(local_10,param_3);
          BitBlt(local_14,0,0,local_70,local_6c,local_10,0,0,0xcc0020);
          SetBkColor(local_10,color);
          if (local_1c != (HGDIOBJ)0x0) {
            SelectObject(local_10,local_1c);
          }
          if (local_15 != '\0') {
            DeleteObject(param_1);
          }
          *in_FS_OFFSET = iVar4;
          BVar3 = DeleteDC(local_10);
          return BVar3;
        }
        PatBlt(local_14,0,0,local_70,local_6c,0x42);
        if (local_20 != (HGDIOBJ)0x0) {
          SelectObject(local_14,local_20);
        }
      }
      BVar3 = 0;
      *in_FS_OFFSET = iVar1;
      if (local_14 != (HDC)0x0) {
        BVar3 = DeleteDC(local_14);
      }
      if (local_c != (HDC)0x0) {
        BVar3 = ReleaseDC((HWND)0x0,local_c);
      }
      return BVar3;
    }
  }
  return (BOOL)local_8;
}

