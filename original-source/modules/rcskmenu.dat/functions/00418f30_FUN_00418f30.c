/*
 * FUN_00418f30 at 00418f30
 * undefined __register FUN_00418f30(HDC param_1, int param_2, int param_3, int param_4, int param_5, HDC param_6, int param_7, int param_8, int param_9, int param_10, HDC param_11, int param_12, int param_13)
 * Address ranges: 00418f30-00419002;0041900a-004191af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418f30(HDC param_1,int param_2,int param_3,int param_4,int param_5,HDC param_6,
                 int param_7,int param_8,int param_9,int param_10,HDC param_11,int param_12,
                 int param_13)

{
  HBITMAP pHVar1;
  HGDIOBJ pvVar2;
  uint rop;
  HDC pHVar3;
  HGDIOBJ h;
  HPALETTE hPal;
  COLORREF color;
  COLORREF color_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar4;
  HPALETTE local_28;
  
  if (((*(int *)PTR_DAT_0047c9d4 == 2) && (param_8 == param_13)) && (param_7 == param_12)) {
    pHVar1 = CreateCompatibleBitmap(param_11,1,1);
    pvVar2 = (HGDIOBJ)FUN_00418d8c((int)pHVar1);
    pHVar1 = SelectObject(param_6,pvVar2);
    uVar4 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffc0;
    rop = FUN_00406c14(0xaa0029,0xcc0020);
    MaskBlt(param_1,param_2,param_3,param_13,param_12,param_11,param_10,param_9,pHVar1,param_5,
            param_4,rop);
    *in_FS_OFFSET = uVar4;
    pvVar2 = SelectObject(param_6,pHVar1);
    DeleteObject(pvVar2);
    return;
  }
  pHVar3 = CreateCompatibleDC((HDC)0x0);
  pHVar3 = (HDC)FUN_00418d8c((int)pHVar3);
  uVar4 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffc0;
  pHVar1 = CreateCompatibleBitmap(param_11,param_8,param_7);
  pvVar2 = (HGDIOBJ)FUN_00418d8c((int)pHVar1);
  h = SelectObject(pHVar3,pvVar2);
  hPal = SelectPalette(param_11,DAT_0047d67c,0);
  SelectPalette(param_11,hPal,0);
  if (hPal == (HPALETTE)0x0) {
    local_28 = SelectPalette(pHVar3,DAT_0047d67c,-1);
  }
  else {
    local_28 = SelectPalette(pHVar3,hPal,-1);
  }
  RealizePalette(pHVar3);
  StretchBlt(pHVar3,0,0,param_8,param_7,param_6,param_5,param_4,param_8,param_7,0xcc0020);
  StretchBlt(pHVar3,0,0,param_8,param_7,param_11,param_10,param_9,param_8,param_7,0x440328);
  color = SetTextColor(param_1,0);
  color_00 = SetBkColor(param_1,0xffffff);
  StretchBlt(param_1,param_2,param_3,param_13,param_12,param_6,param_5,param_4,param_8,param_7,
             0x8800c6);
  StretchBlt(param_1,param_2,param_3,param_13,param_12,pHVar3,0,0,param_8,param_7,0x660046);
  SetTextColor(param_1,color);
  SetBkColor(param_1,color_00);
  if (h != (HGDIOBJ)0x0) {
    SelectObject(pHVar3,h);
  }
  DeleteObject(pvVar2);
  *in_FS_OFFSET = uVar4;
  if (local_28 != (HPALETTE)0x0) {
    SelectPalette(pHVar3,local_28,0);
  }
  DeleteDC(pHVar3);
  return;
}

