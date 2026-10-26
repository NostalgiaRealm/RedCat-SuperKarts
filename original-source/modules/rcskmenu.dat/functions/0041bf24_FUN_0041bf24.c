/*
 * FUN_0041bf24 at 0041bf24
 * HPALETTE __register FUN_0041bf24(HBITMAP param_1, HPALETTE param_2, HPALETTE param_3, int param_4, int param_5)
 * Address ranges: 0041bf24-0041c275;0041c27d-0041c4bf;0041c4c7-0041c4e9;0041c573-0041c57e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HPALETTE FUN_0041bf24(HBITMAP param_1,HPALETTE param_2,HPALETTE param_3,int param_4,int param_5)

{
  int iVar1;
  HDC pHVar2;
  HBITMAP pHVar3;
  int iVar4;
  UINT UVar5;
  HGDIOBJ pvVar6;
  HBRUSH hbr;
  COLORREF CVar7;
  uint uVar8;
  HPALETTE pHVar9;
  DWORD *pDVar10;
  LPBITMAPINFO ptVar11;
  undefined4 *in_FS_OFFSET;
  byte bVar12;
  undefined4 uVar13;
  RECT local_9c;
  undefined1 local_8c [4];
  int local_88;
  int local_84;
  int local_78;
  int local_74;
  HPALETTE local_38;
  RGBQUAD local_34;
  undefined4 local_30;
  LPVOID local_2c;
  LPBITMAPINFO local_28;
  HDC local_24;
  HDC local_20;
  HDC local_1c;
  HGDIOBJ local_18;
  HPALETTE local_14;
  HPALETTE local_10;
  HPALETTE local_c;
  HBITMAP local_8;
  
  bVar12 = 0;
  local_14 = (HPALETTE)0x0;
  if (((*(int *)(param_5 + 0x18) == 0) ||
      ((*(int *)(param_5 + 0x1c) != 0 && (*(int *)(param_5 + 0x20) != 0)))) &&
     ((*(int *)(param_5 + 0x18) != 0 ||
      ((*(int *)(param_5 + 4) != 0 && (*(int *)(param_5 + 8) != 0)))))) {
    local_10 = param_3;
    local_c = param_2;
    local_8 = param_1;
    FUN_0041bae0((int)param_1);
    local_74 = 0;
    if (local_8 != (HBITMAP)0x0) {
      iVar1 = GetObjectA(local_8,0x54,local_8c);
      if (iVar1 < 0x18) {
        FUN_00418c6c();
      }
    }
    pHVar2 = GetDC((HWND)0x0);
    local_1c = (HDC)FUN_00418d8c((int)pHVar2);
    pHVar2 = CreateCompatibleDC(local_1c);
    local_20 = (HDC)FUN_00418d8c((int)pHVar2);
    *in_FS_OFFSET = &stack0xffffff4c;
    if (*(uint *)(param_5 + 0x18) < 0x28) {
      if ((*(ushort *)(param_5 + 0x10) | *(ushort *)(param_5 + 0x12)) == 1) {
        pHVar3 = CreateBitmap(*(int *)(param_5 + 4),*(int *)(param_5 + 8),1,1,(void *)0x0);
        local_14 = (HPALETTE)FUN_00418d8c((int)pHVar3);
      }
      else {
        pHVar3 = CreateCompatibleBitmap(local_1c,*(int *)(param_5 + 4),*(int *)(param_5 + 8));
        local_14 = (HPALETTE)FUN_00418d8c((int)pHVar3);
      }
      FUN_00418d8c((int)local_14);
      pvVar6 = SelectObject(local_20,local_14);
      local_18 = (HGDIOBJ)FUN_00418d8c((int)pvVar6);
      *in_FS_OFFSET = &stack0xffffff40;
      *in_FS_OFFSET = &stack0xffffff34;
      local_38 = (HPALETTE)0x0;
      pHVar9 = (HPALETTE)0x0;
      if (local_10 != (HPALETTE)0x0) {
        local_38 = SelectPalette(local_20,local_10,0);
        RealizePalette(local_20);
      }
      uVar13 = *in_FS_OFFSET;
      *in_FS_OFFSET = &stack0xffffff28;
      if (param_4 == 0) {
        PatBlt(local_20,0,0,*(int *)(param_5 + 4),*(int *)(param_5 + 8),0xff0062);
      }
      else {
        hbr = (HBRUSH)FUN_00417ed4(*(int *)(param_4 + 0x14));
        FUN_0040ebe8(0,0,*(undefined4 *)(param_5 + 4),&local_9c.left,*(undefined4 *)(param_5 + 8));
        FillRect(local_20,&local_9c,hbr);
        CVar7 = FUN_00417210(*(uint *)(*(int *)(param_4 + 0xc) + 0x18));
        SetTextColor(local_20,CVar7);
        uVar8 = FUN_00417e98(*(int *)(param_4 + 0x14));
        CVar7 = FUN_00417210(uVar8);
        SetBkColor(local_20,CVar7);
        if ((*(short *)(param_5 + 0x26) == 1) && (*(int *)(param_5 + 0x14) != 0)) {
          local_34 = (RGBQUAD)FUN_00417210(*(uint *)(*(int *)(param_4 + 0xc) + 0x18));
          uVar8 = FUN_00417e98(*(int *)(param_4 + 0x14));
          local_30 = FUN_00417210(uVar8);
          SetDIBColorTable(local_20,0,2,&local_34);
        }
      }
      if (local_8 != (HBITMAP)0x0) {
        pHVar2 = CreateCompatibleDC(local_1c);
        local_24 = (HDC)FUN_00418d8c((int)pHVar2);
        uVar13 = *in_FS_OFFSET;
        *in_FS_OFFSET = &stack0xffffff1c;
        pvVar6 = SelectObject(local_24,local_8);
        pvVar6 = (HGDIOBJ)FUN_00418d8c((int)pvVar6);
        if (local_c != (HPALETTE)0x0) {
          pHVar9 = SelectPalette(local_24,local_c,0);
          RealizePalette(local_24);
        }
        if (param_4 != 0) {
          CVar7 = FUN_00417210(*(uint *)(*(int *)(param_4 + 0xc) + 0x18));
          SetTextColor(local_24,CVar7);
          uVar8 = FUN_00417e98(*(int *)(param_4 + 0x14));
          CVar7 = FUN_00417210(uVar8);
          SetBkColor(local_24,CVar7);
        }
        BitBlt(local_20,0,0,*(int *)(param_5 + 4),*(int *)(param_5 + 8),local_24,0,0,0xcc0020);
        if (local_c != (HPALETTE)0x0) {
          SelectPalette(local_24,pHVar9,-1);
        }
        pvVar6 = SelectObject(local_24,pvVar6);
        FUN_00418d8c((int)pvVar6);
        *in_FS_OFFSET = uVar13;
        pHVar9 = (HPALETTE)DeleteDC(local_24);
        return pHVar9;
      }
      pHVar9 = (HPALETTE)0x0;
      *in_FS_OFFSET = uVar13;
      if (local_10 != (HPALETTE)0x0) {
        pHVar9 = SelectPalette(local_20,local_38,-1);
      }
      return pHVar9;
    }
    local_28 = (LPBITMAPINFO)FUN_00402714(0x42c);
    uVar13 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffff40;
    *(undefined4 *)(param_5 + 0x18) = 0x28;
    *(undefined2 *)(param_5 + 0x24) = 1;
    if (*(short *)(param_5 + 0x26) == 0) {
      iVar1 = GetDeviceCaps(local_1c,0xc);
      iVar4 = GetDeviceCaps(local_1c,0xe);
      *(short *)(param_5 + 0x26) = (short)iVar1 * (short)iVar4;
    }
    pDVar10 = (DWORD *)(param_5 + 0x18);
    ptVar11 = local_28;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      (ptVar11->bmiHeader).biSize = *pDVar10;
      pDVar10 = pDVar10 + (uint)bVar12 * -2 + 1;
      ptVar11 = (LPBITMAPINFO)((int)ptVar11 + (uint)bVar12 * -8 + 4);
    }
    *(undefined4 *)(param_5 + 4) = *(undefined4 *)(param_5 + 0x1c);
    *(undefined4 *)(param_5 + 8) = *(undefined4 *)(param_5 + 0x20);
    if (*(ushort *)(param_5 + 0x26) < 9) {
      if ((*(short *)(param_5 + 0x26) == 1) && (local_78 == 0)) {
        local_28->bmiColors[0].rgbBlue = '\0';
        local_28->bmiColors[0].rgbGreen = '\0';
        local_28->bmiColors[0].rgbRed = '\0';
        local_28->bmiColors[0].rgbReserved = '\0';
        local_28[1].bmiHeader.biSize = 0xffffff;
      }
      else if (local_10 == (HPALETTE)0x0) {
        if (local_8 != (HBITMAP)0x0) {
          local_18 = SelectObject(local_20,local_8);
          if ((local_74 == 0) || (local_78 == 0)) {
            uVar8 = (int)*(uint *)(param_5 + 0x20) >> 0x1f;
            GetDIBits(local_20,local_8,0,(*(uint *)(param_5 + 0x20) ^ uVar8) - uVar8,(LPVOID)0x0,
                      local_28,0);
          }
          else {
            UVar5 = GetDIBColorTable(local_20,0,0x100,local_28->bmiColors);
            *(UINT *)(param_5 + 0x38) = UVar5;
          }
          SelectObject(local_20,local_18);
        }
      }
      else {
        FUN_00419520(local_10,(LPPALETTEENTRY)local_28->bmiColors,0xff);
      }
    }
    else if (((*(short *)(param_5 + 0x26) == 0x10) || (*(short *)(param_5 + 0x26) == 0x20)) &&
            ((*(byte *)(param_5 + 0x28) & 3) != 0)) {
      FUN_0041bed8(param_5);
      FUN_0040282c((undefined4 *)(param_5 + 0x40),local_28->bmiColors,0xc);
    }
    pHVar3 = CreateDIBSection(local_1c,local_28,0,&local_2c,(HANDLE)0x0,0);
    local_14 = (HPALETTE)FUN_00418d8c((int)pHVar3);
    if (local_2c == (LPVOID)0x0) {
      FUN_00418ce4();
    }
    if ((((local_8 == (HBITMAP)0x0) || (*(int *)(param_5 + 0x1c) != local_88)) ||
        (*(int *)(param_5 + 0x20) != local_84)) || (*(ushort *)(param_5 + 0x26) < 9)) {
      *in_FS_OFFSET = uVar13;
      pHVar9 = (HPALETTE)FUN_0040272c((int)local_28);
      return pHVar9;
    }
    uVar8 = (int)*(uint *)(param_5 + 0x20) >> 0x1f;
    GetDIBits(local_20,local_8,0,(*(uint *)(param_5 + 0x20) ^ uVar8) - uVar8,local_2c,local_28,0);
    FUN_004036a4();
    FUN_004036a4();
  }
  return local_14;
}

