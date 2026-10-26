/* Ghidra-generated C-like pseudocode for inspection. Not original source and not a buildable reconstruction. */
/*
 * FUN_00401010 at 00401010
 * undefined4 __stdcall FUN_00401010(undefined4 param_1, int param_2)
 * Address ranges: 00401010-00401033
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00401010(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_00405da0();
    FUN_00406c10();
  }
  _DAT_0041043c = param_1;
  return 1;
}


/*
 * _SmackBufferCopyPalette@12 at 00401040
 * undefined __stdcall _SmackBufferCopyPalette@12(uint param_1, int param_2, short param_3)
 * Address ranges: 00401040-0040113b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackBufferCopyPalette_12(uint param_1,int param_2,short param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  UINT UVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  
                    /* 0x1040  13  _SmackBufferCopyPalette@12 */
  if ((param_1 != 0) && (param_2 != 0)) {
    if (param_3 != 0) {
      pbVar7 = *(byte **)(param_1 + 0x448);
      if (*(int *)(param_2 + 0x458) == 0) {
        FUN_00402940();
      }
      uVar6 = param_1;
      puVar9 = (undefined1 *)(param_1 + 0x3c);
      do {
        puVar1 = (undefined1 *)(uVar6 + 0x3d);
        puVar2 = (undefined1 *)(uVar6 + 0x3e);
        puVar3 = (undefined1 *)(uVar6 + 0x3c);
        uVar6 = uVar6 + 4;
        UVar4 = GetNearestPaletteIndex
                          (*(HPALETTE *)(param_2 + 0x458),
                           (uint)CONCAT12(*puVar3,CONCAT11(*puVar1,*puVar2)));
        *puVar9 = (char)UVar4;
        puVar9 = puVar9 + 1;
      } while (uVar6 != param_1 + 0x400);
      uVar6 = uVar6 ^ param_1 + 0x400;
      if (*(int *)(param_1 + 0x14) != 0) {
        do {
          uVar6 = uVar6 + 1;
          FUN_0040661d(pbVar7,*(int *)(param_1 + 0x10),(int)(param_1 + 0x3c));
          pbVar7 = pbVar7 + *(int *)(param_1 + 0x18);
        } while (uVar6 < *(uint *)(param_1 + 0x14));
      }
    }
    puVar8 = (undefined4 *)(param_2 + 0x3c);
    puVar10 = (undefined4 *)(param_1 + 0x3c);
    for (iVar5 = 0x100; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    if (*(HGDIOBJ *)(param_1 + 0x458) != (HGDIOBJ)0x0) {
      DeleteObject(*(HGDIOBJ *)(param_1 + 0x458));
      *(undefined4 *)(param_1 + 0x458) = 0;
    }
  }
  return;
}


/*
 * _SmackBufferFromScreen@16 at 00401140
 * undefined __stdcall _SmackBufferFromScreen@16(int param_1, HWND param_2, uint param_3, uint param_4)
 * Address ranges: 00401140-00401408
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SmackBufferFromScreen_16(int param_1,HWND param_2,uint param_3,uint param_4)

{
  BOOL BVar1;
  HDC hdc;
  int iVar2;
  HDC hdc_00;
  HBITMAP hbm;
  BYTE BVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  LOGPALETTE local_430 [128];
  tagPOINT local_2c;
  HPALETTE local_24;
  HGDIOBJ local_20;
  HPALETTE local_1c;
  HPALETTE local_18;
  uint local_14;
  
                    /* 0x1140  12  _SmackBufferFromScreen@16 */
  if (param_1 != 0) {
    if (param_2 != (HWND)0x0) {
      BVar1 = IsWindow(param_2);
      if (BVar1 != 0) {
        local_2c.x = param_3 & 0xffff;
        local_2c.y = param_4 & 0xffff;
        ClientToScreen(param_2,&local_2c);
        param_3 = local_2c.x;
        param_4 = local_2c.y;
      }
      param_2 = (HWND)0x0;
    }
    hdc = GetDC(param_2);
    local_430[0].palVersion = 0x300;
    local_430[0].palNumEntries = *(WORD *)(param_1 + 0x2c);
    GetSystemPaletteEntries(hdc,0,*(UINT *)(param_1 + 0x2c),local_430[0].palPalEntry);
    local_14 = 0;
    if (*(int *)(param_1 + 0x2c) != 0) {
      iVar2 = 0;
      do {
        if ((local_14 < *(uint *)(param_1 + 0x34)) || (*(uint *)(param_1 + 0x38) <= local_14)) {
          BVar3 = '\0';
        }
        else {
          BVar3 = '\x04';
        }
        (&local_430[0].palPalEntry[0].peFlags)[iVar2] = BVar3;
        iVar2 = iVar2 + 4;
        local_14 = local_14 + 1;
      } while (local_14 < *(uint *)(param_1 + 0x2c));
    }
    local_18 = CreatePalette(local_430);
    local_1c = SelectPalette(hdc,local_18,0);
    RealizePalette(hdc);
    hdc_00 = CreateCompatibleDC(hdc);
    local_24 = SelectPalette(hdc_00,local_18,0);
    RealizePalette(hdc_00);
    hbm = CreateCompatibleBitmap(hdc,*(int *)(param_1 + 0x10),*(int *)(param_1 + 0x14));
    local_20 = SelectObject(hdc_00,hbm);
    BitBlt(hdc_00,0,0,*(int *)(param_1 + 0x10),*(int *)(param_1 + 0x14),hdc,param_3 & 0xffff,
           param_4 & 0xffff,0xcc0020);
    _DAT_00410020 = 0;
    _DAT_0041001e = 8;
    _DAT_00410014 = *(undefined4 *)(param_1 + 0x18);
    DAT_00410018 = *(UINT *)(param_1 + 0x14);
    DAT_00410010 = 0x28;
    _DAT_0041001c = 1;
    GetDIBits(hdc_00,hbm,0,DAT_00410018,*(LPVOID *)(param_1 + 0x448),(LPBITMAPINFO)&DAT_00410010,0);
    SelectPalette(hdc_00,local_24,0);
    SelectPalette(hdc,local_1c,0);
    DeleteObject(local_18);
    SelectObject(hdc_00,local_20);
    DeleteDC(hdc_00);
    DeleteObject(hbm);
    ReleaseDC(param_2,hdc);
    puVar5 = (undefined4 *)&DAT_00410038;
    puVar6 = (undefined4 *)(param_1 + 0x3c);
    for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    local_14 = 0;
    iVar2 = 0;
    do {
      iVar4 = local_14 + 1;
      *(short *)((int)&DAT_00410038 + iVar2) = (short)local_14;
      iVar2 = iVar2 + 2;
      local_14 = iVar4;
    } while (iVar4 < 0x100);
  }
  return;
}


/*
 * _SmackBufferToBufferTrans@36 at 00401410
 * undefined8 __stdcall _SmackBufferToBufferTrans@36(int * param_1, ushort param_2, uint param_3, int * param_4, ushort param_5, uint param_6, uint param_7, uint param_8, char param_9)
 * Address ranges: 00401410-004014fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8
_SmackBufferToBufferTrans_36
          (int *param_1,ushort param_2,uint param_3,int *param_4,ushort param_5,uint param_6,
          uint param_7,uint param_8,char param_9)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
                    /* 0x1410  11  _SmackBufferToBufferTrans@36 */
  uVar3 = CONCAT44(param_6,param_4);
  if ((param_1 != (int *)0x0) && (uVar3 = CONCAT44(param_6,param_4), param_4 != (int *)0x0)) {
    if (*param_1 == 0) {
      if (*param_4 == 0) {
        iVar2 = param_4[6] - (param_7 & 0xffff);
      }
      else {
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - 1;
        iVar2 = -((param_7 & 0xffff) + param_4[6]);
      }
    }
    else {
      param_3 = (*(ushort *)(param_1 + 5) - param_3) - param_8;
      if (*param_4 == 0) {
        param_6 = (param_6 + param_8) - 1;
        iVar2 = -((param_7 & 0xffff) + param_4[6]);
      }
      else {
        iVar2 = param_4[6] - (param_7 & 0xffff);
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - param_8;
      }
    }
    uVar1 = param_7 & 0xffff;
    uVar3 = FUN_004065df(param_4[0x112],uVar1,param_1[0x112],param_1[6] - uVar1,param_4[0x112],iVar2
                         ,uVar1,param_8 & 0xffff,(param_3 & 0xffff) * param_1[4] + (uint)param_2,
                         (uint)param_5 + param_4[6] * (param_6 & 0xffff),param_9);
  }
  return uVar3;
}


/*
 * _SmackBufferToBuffer@32 at 00401500
 * undefined __stdcall _SmackBufferToBuffer@32(int * param_1, ushort param_2, uint param_3, int * param_4, ushort param_5, uint param_6, uint param_7, uint param_8)
 * Address ranges: 00401500-004015e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackBufferToBuffer_32
               (int *param_1,ushort param_2,uint param_3,int *param_4,ushort param_5,uint param_6,
               uint param_7,uint param_8)

{
  int iVar1;
  
                    /* 0x1500  10  _SmackBufferToBuffer@32 */
  if ((param_1 != (int *)0x0) && (param_4 != (int *)0x0)) {
    if (*param_1 == 0) {
      if (*param_4 == 0) {
        iVar1 = param_4[6] - (param_7 & 0xffff);
      }
      else {
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - 1;
        iVar1 = -((param_7 & 0xffff) + param_4[6]);
      }
    }
    else {
      param_3 = (*(ushort *)(param_1 + 5) - param_3) - param_8;
      if (*param_4 == 0) {
        param_6 = (param_6 + param_8) - 1;
        iVar1 = -((param_7 & 0xffff) + param_4[6]);
      }
      else {
        iVar1 = param_4[6] - (param_7 & 0xffff);
        param_6 = (*(ushort *)(param_4 + 5) - param_6) - param_8;
      }
    }
    FUN_004065a0(param_1[0x112],param_1[6] - (param_7 & 0xffff),param_4[0x112],iVar1,
                 param_7 & 0xffff,param_8 & 0xffff,(uint)param_2 + param_1[6] * (param_3 & 0xffff),
                 (uint)param_5 + param_4[6] * (param_6 & 0xffff));
  }
  return;
}


/*
 * _SmackSetSystemRes@4 at 004015f0
 * bool __stdcall _SmackSetSystemRes@4(uint param_1)
 * Address ranges: 004015f0-004016fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool _SmackSetSystemRes_4(uint param_1)

{
  HMODULE hModule;
  int iVar1;
  bool bVar2;
  undefined1 *puVar3;
  char *lpProcName;
  undefined1 local_a4 [36];
  undefined2 local_80;
  undefined4 local_7c;
  undefined4 local_38;
  undefined4 local_34;
  
                    /* 0x15f0  9  _SmackSetSystemRes@4 */
  if (param_1 < 5) {
    if (DAT_0040e838 == (FARPROC)0x0) {
      lpProcName = s_ChangeDisplaySettingsA_0040e104;
      hModule = GetModuleHandleA(s_user32_dll_0040e0f8);
      DAT_0040e838 = GetProcAddress(hModule,lpProcName);
      if (DAT_0040e838 == (FARPROC)0x0) {
        DAT_0040e838 = (FARPROC)0xffffffff;
      }
    }
    puVar3 = local_a4;
    if (DAT_0040e838 == (FARPROC)0xffffffff) {
      return false;
    }
    if (param_1 == 0) {
      puVar3 = (undefined1 *)0x0;
    }
    else {
      if (param_1 == 1) {
        local_38 = 0x280;
        local_34 = 400;
      }
      else if (param_1 == 2) {
        local_38 = 0x280;
        local_34 = 0x1e0;
      }
      else if (param_1 == 3) {
        local_38 = 800;
        local_34 = 600;
      }
      else if (param_1 == 4) {
        local_38 = 0x400;
        local_34 = 0x300;
      }
      local_7c = 0x180000;
      local_80 = 0x94;
    }
    iVar1 = (*DAT_0040e838)(puVar3,0);
    bVar2 = iVar1 == 0;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


/*
 * _SmackBufferClear@8 at 00401700
 * undefined __stdcall _SmackBufferClear@8(int param_1, undefined1 param_2)
 * Address ranges: 00401700-00401760
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackBufferClear_8(int param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint local_14;
  
                    /* 0x1700  8  _SmackBufferClear@8 */
  if (param_1 != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0x448);
    local_14 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        uVar2 = *(uint *)(param_1 + 0x10);
        puVar4 = puVar3;
        for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = param_2;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        local_14 = local_14 + 1;
        puVar3 = (undefined4 *)((int)puVar3 + *(int *)(param_1 + 0x18));
      } while (local_14 < *(uint *)(param_1 + 0x14));
    }
  }
  return;
}


/*
 * _SmackBufferSetPalette@4 at 00401770
 * UINT __stdcall _SmackBufferSetPalette@4(int param_1)
 * Address ranges: 00401770-0040180f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


UINT _SmackBufferSetPalette_4(int param_1)

{
  HDC hdc;
  HPALETTE hPal;
  UINT UVar1;
  
                    /* 0x1770  7  _SmackBufferSetPalette@4 */
  if ((param_1 != 0) && (*(int *)(param_1 + 0xc) == 0)) {
    if (*(int *)(param_1 + 0x458) == 0) {
      FUN_00402940();
    }
    hdc = GetDC(*(HWND *)(param_1 + 0x464));
    hPal = SelectPalette(hdc,*(HPALETTE *)(param_1 + 0x458),0);
    UVar1 = RealizePalette(hdc);
    if (*(int *)(param_1 + 0x444) != 0) {
      InvalidateRect(*(HWND *)(param_1 + 0x464),(RECT *)0x0,0);
    }
    SelectPalette(hdc,hPal,0);
    ReleaseDC(*(HWND *)(param_1 + 0x464),hdc);
    return UVar1;
  }
  return 0;
}


/*
 * _SmackBufferClose@4 at 00401820
 * undefined __stdcall _SmackBufferClose@4(int param_1)
 * Address ranges: 00401820-00401907
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackBufferClose_4(int param_1)

{
                    /* 0x1820  6  _SmackBufferClose@4 */
  if (param_1 == 0) {
    return;
  }
  switch(*(undefined4 *)(param_1 + 8)) {
  case 1:
    goto LAB_0040186a;
  case 2:
LAB_0040186a:
    FUN_0040650f();
    if (*(HWND *)(param_1 + 0x470) != (HWND)0x0) {
      ShowWindow(*(HWND *)(param_1 + 0x470),0);
      SendMessageA(*(HWND *)(param_1 + 0x470),0x402,0,0);
    }
    break;
  case 3:
    FUN_0040650f();
    break;
  case 4:
    if (*(int *)(param_1 + 0x450) != 0) {
      SelectObject(*(HDC *)(param_1 + 0x45c),*(HGDIOBJ *)(param_1 + 0x454));
      DeleteObject(*(HGDIOBJ *)(param_1 + 0x450));
      if (*(HDC *)(param_1 + 0x45c) != (HDC)0x0) {
        DeleteDC(*(HDC *)(param_1 + 0x45c));
      }
    }
  }
  if (*(HGDIOBJ *)(param_1 + 0x458) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x458));
  }
  FUN_0040650f();
  return;
}


/*
 * _SmackBufferNewPalette@12 at 00401910
 * undefined __stdcall _SmackBufferNewPalette@12(int param_1, int param_2, byte param_3)
 * Address ranges: 00401910-00401b3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SmackBufferNewPalette_12(int param_1,int param_2,byte param_3)

{
  PALETTEENTRY *pPVar1;
  int iVar2;
  byte bVar3;
  HPALETTE pHVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  LOGPALETTE local_420 [128];
  int local_1c;
  uint local_18;
  byte local_14;
  
                    /* 0x1910  5  _SmackBufferNewPalette@12 */
  if ((param_1 != 0) && (*(undefined4 *)(param_1 + 0x444) = 1, 0xff < *(uint *)(param_1 + 0x2c))) {
    if (*(int *)(param_1 + 0x34) != 0) {
      uVar6 = 0;
      do {
        uVar7 = uVar6;
        if (uVar6 == *(uint *)(param_1 + 0x34)) {
          uVar7 = *(uint *)(param_1 + 0x38);
        }
        uVar6 = uVar7 + 1;
        local_420[0].palPalEntry[uVar7].peRed = *(BYTE *)(param_1 + 0x3a + uVar6 * 4);
        local_420[0].palPalEntry[uVar7].peGreen = *(BYTE *)(param_1 + 0x39 + uVar6 * 4);
        local_420[0].palPalEntry[uVar7].peBlue = *(BYTE *)(param_1 + 0x38 + uVar6 * 4);
        local_420[0].palPalEntry[uVar7].peFlags = '\0';
      } while (uVar6 < 0x100);
    }
    local_18 = *(uint *)(param_1 + 0x34);
    if (local_18 < *(uint *)(param_1 + 0x38)) {
      local_1c = local_18 * 4 + param_1;
      pbVar8 = (byte *)(*(int *)(param_1 + 0x34) * (((param_3 & 1) != 0) + 3) + param_2);
      do {
        iVar2 = local_1c;
        pbVar9 = pbVar8 + 3;
        if ((param_3 & 4) == 0) {
          bVar3 = *pbVar8;
          bVar5 = pbVar8[1];
          local_14 = pbVar8[2];
        }
        else {
          local_14 = *pbVar8;
          bVar5 = pbVar8[1];
          bVar3 = pbVar8[2];
        }
        if ((param_3 & 2) == 0) {
          bVar3 = bVar3 << 2;
          local_14 = local_14 << 2;
          bVar5 = bVar5 << 2;
        }
        if ((param_3 & 1) != 0) {
          pbVar9 = pbVar8 + 4;
        }
        if (*(uint *)(param_1 + 0x38) < 0x100) {
          uVar6 = *(uint *)(param_1 + 0x38) * 4 + param_1;
          do {
            if ((bVar3 == *(byte *)(uVar6 + 0x3e)) && (bVar5 == *(byte *)(uVar6 + 0x3d))) {
              if (local_14 == *(byte *)(uVar6 + 0x3c)) {
                if ((bVar3 & 3) == 3) {
                  bVar3 = bVar3 - 1;
                }
                else {
                  bVar3 = bVar3 + 1;
                }
              }
            }
            uVar6 = uVar6 + 4;
          } while (uVar6 < param_1 + 0x400U);
        }
        local_420[0].palPalEntry[local_18].peRed = bVar3;
        *(byte *)(iVar2 + 0x3e) = bVar3;
        local_420[0].palPalEntry[local_18].peGreen = bVar5;
        bVar3 = local_14;
        *(byte *)(iVar2 + 0x3d) = bVar5;
        uVar6 = local_18 + 1;
        local_420[0].palPalEntry[local_18].peBlue = local_14;
        *(byte *)(iVar2 + 0x3c) = bVar3;
        pPVar1 = local_420[0].palPalEntry + local_18;
        local_18 = uVar6;
        pPVar1->peFlags = '\x04';
        local_1c = local_1c + 4;
        pbVar8 = pbVar9;
      } while (uVar6 < *(uint *)(param_1 + 0x38));
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      if (*(HGDIOBJ *)(param_1 + 0x458) != (HGDIOBJ)0x0) {
        DeleteObject(*(HGDIOBJ *)(param_1 + 0x458));
      }
      local_420[0].palVersion = 0x300;
      local_420[0].palNumEntries = *(WORD *)(param_1 + 0x2c);
      pHVar4 = CreatePalette(local_420);
      *(HPALETTE *)(param_1 + 0x458) = pHVar4;
      if (*(int *)(param_1 + 8) == 4) {
        (*DAT_00410454)(*(undefined4 *)(param_1 + 0x45c),0,*(undefined4 *)(param_1 + 0x2c),
                        param_1 + 0x3c);
      }
    }
    else {
      FUN_00402a00();
    }
    if (0x100 < _DAT_0040e808) {
      *(undefined4 *)(param_1 + 0x440) = 1;
    }
  }
  return;
}


/*
 * _SmackBufferFocused@4 at 00401b40
 * bool __stdcall _SmackBufferFocused@4(int param_1)
 * Address ranges: 00401b40-00401b7f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


bool _SmackBufferFocused_4(int param_1)

{
  HWND pHVar1;
  uint uVar2;
  
                    /* 0x1b40  4  _SmackBufferFocused@4 */
  if (param_1 == 0) {
    return false;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    pHVar1 = GetFocus();
    uVar2 = (uint)(pHVar1 == *(HWND *)(param_1 + 0x464));
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x460);
  }
  return uVar2 != 0;
}


/*
 * _SmackBufferBlit@32 at 00401b80
 * undefined4 __stdcall _SmackBufferBlit@32(int param_1, HDC param_2, uint param_3, uint param_4, ushort param_5, ushort param_6, ushort param_7, ushort param_8)
 * Address ranges: 00401b80-00401eef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_SmackBufferBlit_32(int param_1,HDC param_2,uint param_3,uint param_4,ushort param_5,ushort param_6,
                   ushort param_7,ushort param_8)

{
  uint uVar1;
  uint SrcWidth;
  uint SrcHeight;
  bool bVar2;
  undefined4 local_1c;
  HPALETTE local_18;
  
                    /* 0x1b80  3  _SmackBufferBlit@32 */
  local_1c = 0;
  if (param_1 == 0) {
    local_1c = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x444) = 1;
    if (*(int *)(param_1 + 0xc) == 0) {
      bVar2 = param_2 == (HDC)0x0;
      if (bVar2) {
        param_2 = GetDC(*(HWND *)(param_1 + 0x464));
      }
      if (*(int *)(param_1 + 0x458) == 0) {
        FUN_00402940();
      }
      local_18 = SelectPalette(param_2,*(HPALETTE *)(param_1 + 0x458),0);
      RealizePalette(param_2);
      if (*(int *)(param_1 + 0x440) != 0) {
        local_1c = 0x100;
        if (!bVar2) {
          SelectPalette(param_2,local_18,0);
          param_2 = GetDC(*(HWND *)(param_1 + 0x464));
          local_18 = SelectPalette(param_2,*(HPALETTE *)(param_1 + 0x458),0);
          RealizePalette(param_2);
        }
        bVar2 = true;
        param_7 = *(ushort *)(param_1 + 0x10);
        param_5 = 0;
        param_8 = *(ushort *)(param_1 + 0x14);
        param_6 = 0;
      }
      SrcWidth = (uint)param_7;
      SrcHeight = (uint)param_8;
      if ((SrcWidth != 0 || SrcHeight != 0) && (uVar1 = *(uint *)(param_1 + 8), 2 < uVar1)) {
        if (uVar1 < 4) {
          DAT_00410010 = 0x28;
          _DAT_00410020 = 0;
          _DAT_0041001e = 8;
          _DAT_00410014 = *(undefined4 *)(param_1 + 0x18);
          DAT_00410018 = *(int *)(param_1 + 0x14);
          _DAT_0041001c = 1;
          SetStretchBltMode(param_2,3);
          StretchDIBits(param_2,(int)(((ulonglong)param_5 * (ulonglong)*(uint *)(param_1 + 0x20)) /
                                     (ulonglong)*(uint *)(param_1 + 0x10)) + param_3 & 0xffff,
                        (int)(((ulonglong)param_6 * (ulonglong)*(uint *)(param_1 + 0x24)) /
                             (ulonglong)*(uint *)(param_1 + 0x14)) + param_4 & 0xffff,
                        (uint)(((ulonglong)param_7 * (ulonglong)*(uint *)(param_1 + 0x20)) /
                              (ulonglong)*(uint *)(param_1 + 0x10)) & 0xffff,
                        (uint)(((ulonglong)param_8 * (ulonglong)*(uint *)(param_1 + 0x24)) /
                              (ulonglong)*(uint *)(param_1 + 0x14)) & 0xffff,(uint)param_5,
                        (uint)(ushort)(*(short *)(param_1 + 0x14) - (param_6 + param_8)),SrcWidth,
                        SrcHeight,*(void **)(param_1 + 0x448),(BITMAPINFO *)&DAT_00410010,1,0xcc0020
                       );
        }
        else if (uVar1 == 4) {
          if (*(int *)(param_1 + 0x1c) == 0) {
            (*DAT_00410450)(param_2,(param_3 & 0xffff) + (uint)param_5,
                            (uint)param_6 + (param_4 & 0xffff),SrcWidth,SrcHeight,
                            *(undefined4 *)(param_1 + 0x45c),(uint)param_5,(uint)param_6);
          }
          else {
            (*DAT_0041044c)(param_2,(param_3 & 0xffff) +
                                    (uint)(ushort)(((ulonglong)param_5 *
                                                   (ulonglong)*(uint *)(param_1 + 0x20)) /
                                                  (ulonglong)*(uint *)(param_1 + 0x10)),
                            (param_4 & 0xffff) +
                            (uint)(ushort)(((ulonglong)param_6 *
                                           (ulonglong)*(uint *)(param_1 + 0x24)) /
                                          (ulonglong)*(uint *)(param_1 + 0x14)),
                            (uint)(((ulonglong)param_7 * (ulonglong)*(uint *)(param_1 + 0x20)) /
                                  (ulonglong)*(uint *)(param_1 + 0x10)) & 0xffff,
                            (uint)(((ulonglong)param_8 * (ulonglong)*(uint *)(param_1 + 0x24)) /
                                  (ulonglong)*(uint *)(param_1 + 0x14)) & 0xffff,
                            *(undefined4 *)(param_1 + 0x45c),param_5,param_6,SrcWidth,SrcHeight);
          }
        }
      }
      SelectPalette(param_2,local_18,0);
      if (bVar2) {
        ReleaseDC(*(HWND *)(param_1 + 0x464),param_2);
      }
    }
    else if (*(int *)(param_1 + 8) == 1) {
      _DAT_0041001e = 8;
      _DAT_00410014 = *(undefined4 *)(param_1 + 0x18);
      DAT_00410018 = *(int *)(param_1 + 0x14);
      _DAT_00410020 = 0;
      DAT_00410010 = 0x28;
      _DAT_0041001c = 1;
      FUN_00402be0(DAT_00410018 * *(int *)(param_1 + 0x10),0);
    }
  }
  return local_1c;
}


/*
 * _SmackBufferOpen@24 at 00401f10
 * uint * __stdcall _SmackBufferOpen@24(HWND param_1, ushort param_2, ushort param_3, uint param_4, ushort param_5, uint param_6)
 * Address ranges: 00401f10-00402762
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * _SmackBufferOpen_24(HWND param_1,ushort param_2,ushort param_3,uint param_4,ushort param_5,
                          uint param_6)

{
  BYTE BVar1;
  DWORD DVar2;
  HDC pHVar3;
  int iVar4;
  int iVar5;
  HPALETTE pHVar6;
  UINT UVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  HGDIOBJ pvVar12;
  uint *puVar13;
  HINSTANCE hInstance;
  HWND hWnd;
  uint uVar14;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_EDX;
  uint uVar15;
  LOGPALETTE *pLVar16;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  ulonglong uVar20;
  undefined8 uVar21;
  BOOL bForceBkgd;
  LPVOID lpParam;
  LOGPALETTE local_42c [128];
  int aiStack_28 [2];
  undefined4 *puStack_20;
  uint local_1c;
  char local_18;
  byte local_14;
  
                    /* 0x1f10  2  _SmackBufferOpen@24 */
  uVar17 = param_4;
  if (_DAT_0040e808 == 0) {
    DVar2 = GetVersion();
    if ((byte)DVar2 < 4) {
      DAT_00410444 = 0xb0000;
    }
    else {
      DAT_00410444 = 0xa0000;
    }
    pHVar3 = GetDC((HWND)0x0);
    iVar4 = GetDeviceCaps(pHVar3,0xc);
    iVar5 = GetDeviceCaps(pHVar3,0xe);
    _DAT_0040e808 = iVar4 * iVar5;
    if (0x18 < _DAT_0040e808) {
      _DAT_0040e808 = 0x18;
    }
    _DAT_0040e808 = 1 << (DAT_0040e808 & 0x1f);
    if (_DAT_0040e808 < 0x100) {
      DAT_00410468 = (ushort)_DAT_0040e808;
    }
    else {
      DAT_00410468 = 0x100;
    }
    if (_DAT_0040e808 == 0x100) {
      iVar4 = GetDeviceCaps(pHVar3,0x18);
      DAT_0041046c = (ushort)(iVar4 / 2);
    }
    else {
      DAT_0041046c = 0;
    }
    pLVar16 = local_42c;
    puVar11 = &DAT_00410010;
    for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    uVar15 = 0;
    iVar4 = 0;
    do {
      *(short *)((int)&DAT_00410038 + iVar4) = (short)uVar15;
      uVar15 = uVar15 + 1;
      iVar4 = iVar4 + 2;
    } while (uVar15 < 0x100);
    local_42c[0].palVersion = 0x300;
    local_42c[0].palNumEntries = 0x100;
    for (iVar4 = 0x100; pLVar16 = (LOGPALETTE *)((int)pLVar16 + 4), iVar4 != 0; iVar4 = iVar4 + -1)
    {
      *(undefined4 *)pLVar16 = 0;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pLVar16 = 0;
      pLVar16 = (LOGPALETTE *)((int)pLVar16 + 1);
    }
    iVar4 = 0;
    do {
      iVar5 = iVar4 + 4;
      (&local_42c[0].palPalEntry[0].peFlags)[iVar4] = '\x04';
      iVar4 = iVar5;
    } while (iVar5 != 0x400);
    bForceBkgd = 1;
    pHVar6 = CreatePalette(local_42c);
    pHVar6 = SelectPalette(pHVar3,pHVar6,bForceBkgd);
    RealizePalette(pHVar3);
    pHVar6 = SelectPalette(pHVar3,pHVar6,1);
    DeleteObject(pHVar6);
    ReleaseDC((HWND)0x0,pHVar3);
  }
  pHVar3 = GetDC((HWND)0x0);
  UVar7 = GetSystemPaletteUse(pHVar3);
  DAT_0041046a = DAT_0041046c;
  if (UVar7 == 2) {
    DAT_0041046a = 1;
  }
  ReleaseDC((HWND)0x0,pHVar3);
  if (param_5 == 0) {
    param_5 = param_3;
  }
  if ((ushort)param_6 == 0) {
    param_6 = param_4;
  }
  if ((param_5 == param_3) && ((ushort)param_6 == (ushort)param_4)) {
    local_14 = 0;
  }
  else {
    local_14 = 1;
  }
  uVar15 = ((uint)param_5 << 2) % (uint)param_3;
  if ((uVar15 == 0) && (uVar15 = ((param_6 & 0xffff) << 2) % (param_4 & 0xffff), uVar15 == 0)) {
    local_18 = '\0';
  }
  else {
    local_18 = '\x01';
  }
  if (param_2 == 0) {
    local_1c = 5;
  }
  else {
    local_1c = param_2 + 1;
  }
  uVar14 = 0;
  do {
    uVar8 = local_1c - 1;
    uVar9 = local_1c - 2;
    uVar20 = CONCAT44(uVar15,uVar9);
    local_1c = uVar8;
    if (3 < (ushort)uVar9) goto switchD_004021d3_default;
    uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff;
    switch(uVar9 & 0xffff) {
    case 0:
      if (param_3 < 0x141) {
        bVar18 = (ushort)param_4 < 0xf0;
        bVar19 = (ushort)param_4 == 0xf0;
LAB_00402207:
        uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff;
        if ((bVar18 || bVar19) &&
           (uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff, (byte)uVar14 == local_14)) {
          uVar20 = FUN_00402aa0(uVar14,uVar15);
          uVar15 = (uint)(uVar20 >> 0x20);
          uVar14 = extraout_ECX_00;
          if ((char)uVar20 != '\0') goto switchD_004021d3_caseD_2;
        }
      }
      break;
    case 1:
      uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff;
      if (param_3 < 0x141) {
        bVar18 = (ushort)param_4 < 200;
        bVar19 = (ushort)param_4 == 200;
        goto LAB_00402207;
      }
      break;
    case 2:
switchD_004021d3_caseD_2:
      uVar21 = FUN_00402c30(uVar14,uVar15,0x478);
      puVar10 = (uint *)uVar21;
      if (puVar10 == (uint *)0x0) {
        return (uint *)0x0;
      }
      puVar13 = puVar10;
      for (iVar4 = 0x11e; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar13 = 0;
        puVar13 = (uint *)((int)puVar13 + 1);
      }
      puVar10[2] = local_1c & 0xffff;
      puVar10[4] = (uint)param_3;
      puVar10[5] = param_4 & 0xffff;
      puVar10[6] = puVar10[4] + 3 & 0xfffffffc;
      puVar10[10] = _DAT_0040e808;
      puVar10[8] = (uint)param_5;
      puVar10[9] = param_6 & 0xffff;
      puVar10[7] = (uint)local_14;
      puVar10[0x10f] = 7;
      switch(local_1c - 1 & 0xffff) {
      case 0:
        puVar10[0xb] = 0x100;
        puVar10[0xd] = 0;
        puVar10[0xe] = 0x100;
        puVar10[1] = 1;
        puVar10[3] = 1;
        if ((ushort)param_4 < 0xc9) {
          puVar10[5] = 0xcc;
          param_4 = 0xcc;
        }
        goto LAB_00402339;
      case 1:
        puVar10[0xb] = 0x100;
        puVar10[0xd] = 0;
        puVar10[0xe] = 0x100;
        puVar10[1] = 2;
        puVar10[3] = 1;
        puVar10[4] = 0x140;
        uVar17 = DAT_00410444;
        puVar10[5] = 200;
        puVar10[0x112] = uVar17;
        puVar11 = (undefined4 *)FUN_00402c30(0,(int)((ulonglong)uVar21 >> 0x20),64000);
        puVar10[0x113] = (uint)puVar11;
        for (iVar4 = 16000; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar11 = 0;
          puVar11 = puVar11 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar11 = 0;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        break;
      case 2:
        puVar10[0xb] = (uint)DAT_00410468;
        uVar15 = (uint)DAT_0041046a;
        puVar10[0xd] = (uint)DAT_0041046a;
        uVar17 = (uint)DAT_00410468;
        puVar10[1] = 1;
        puVar10[0xe] = uVar17 - uVar15 & 0xffff;
        uVar17 = 0;
LAB_00402339:
        *puVar10 = 1;
        uVar17 = FUN_00402c30(uVar17,puVar10[6],(param_4 & 0xffff) * puVar10[6]);
        puVar10[0x112] = uVar17;
        if (uVar17 == 0) {
          FUN_0040650f();
          return (uint *)0x0;
        }
        break;
      case 3:
        puVar10[0xb] = (uint)DAT_00410468;
        uVar17 = (uint)DAT_0041046a;
        puVar10[0xd] = (uint)DAT_0041046a;
        puVar10[0xe] = DAT_00410468 - uVar17 & 0xffff;
        puVar10[1] = (uint)(local_18 != '\0');
        (*DAT_0041045c)(&DAT_00410010);
        *puVar10 = (uint)(-1 < (int)DAT_00410018);
        _DAT_00410014 = puVar10[6];
        DAT_00410018 = DAT_00410018 * param_3;
        uVar17 = (*DAT_00410458)();
        puVar10[0x117] = uVar17;
        if (uVar17 == 0) {
          FUN_0040650f();
          return (uint *)0x0;
        }
        pvVar12 = (HGDIOBJ)(*DAT_00410460)(puVar10[0x117],&DAT_00410010,puVar10 + 0x112);
        puVar10[0x114] = (uint)pvVar12;
        if ((pvVar12 == (HGDIOBJ)0x0) || (puVar10[0x112] == 0)) {
          DeleteDC((HDC)puVar10[0x117]);
          FUN_0040650f();
          return (uint *)0x0;
        }
        pvVar12 = SelectObject((HDC)puVar10[0x117],pvVar12);
        puVar10[0x115] = (uint)pvVar12;
      }
      puVar10[0xc] = (uint)(ushort)((short)puVar10[0xe] - (short)puVar10[0xd]);
      if (puVar10[1] != 2) {
        _SmackBufferClear_8((int)puVar10,0);
      }
      if (_DAT_0040e808 < 0x101) {
        pHVar3 = GetDC((HWND)0x0);
        GetSystemPaletteEntries(pHVar3,0,(uint)(ushort)puVar10[0xb],local_42c[0].palPalEntry);
        ReleaseDC((HWND)0x0,pHVar3);
        uVar17 = 0;
        puVar13 = puVar10;
        if (puVar10[0xb] != 0) {
          do {
            *(BYTE *)((int)puVar13 + 0x3e) = local_42c[0].palPalEntry[uVar17].peRed;
            *(BYTE *)((int)puVar13 + 0x3d) = local_42c[0].palPalEntry[uVar17].peGreen;
            BVar1 = local_42c[0].palPalEntry[uVar17].peBlue;
            *(undefined1 *)((int)puVar13 + 0x3f) = 0;
            *(BYTE *)(puVar13 + 0xf) = BVar1;
            uVar17 = uVar17 + 1;
            puVar13 = puVar13 + 1;
          } while (uVar17 < puVar10[0xb]);
        }
      }
      puVar10[0x119] = (uint)param_1;
      if (puVar10[3] == 0) {
        return puVar10;
      }
      lpParam = (LPVOID)0x0;
      hInstance = (HINSTANCE)GetWindowLongA(param_1,-6);
      hWnd = CreateWindowExA(0,s_DisplayDibWindow_0040e0e0,&DAT_0040e0f4,0x80000000,0,0,0x20,0x20,
                             param_1,(HMENU)0x0,hInstance,lpParam);
      puVar10[0x11c] = (uint)hWnd;
      if (hWnd != (HWND)0x0) {
        DAT_00410440 = puVar10;
        uVar17 = SetWindowLongA(hWnd,-4,0x402770);
        puVar10[0x11b] = uVar17;
        uVar17 = SetWindowLongA((HWND)puVar10[0x119],-4,0x4028a0);
        puVar10[0x11a] = uVar17;
        DAT_00410010 = 0x28;
        _DAT_00410020 = 0;
        _DAT_00410014 = puVar10[6];
        _DAT_0041001c = 1;
        DAT_00410018 = puVar10[5];
        _DAT_0041001e = 8;
        if (puVar10[2] == 1) {
          uVar17 = 5;
        }
        else {
          uVar17 = 1;
        }
        aiStack_28[0] = (uVar17 | 0x8ad0) * 0x10000 + 0x400;
        puStack_20 = &DAT_00410010;
        aiStack_28[1] = 0x428;
        SendMessageA((HWND)puVar10[0x11c],0x4a,0,(LPARAM)aiStack_28);
        ShowWindow((HWND)puVar10[0x119],6);
        ShowWindow((HWND)puVar10[0x11c],1);
        return puVar10;
      }
      FUN_0040650f();
      FUN_0040650f();
      return (uint *)0x0;
    case 3:
      if (uVar14 == DAT_0040e800) {
        FUN_00402b00();
        uVar14 = extraout_ECX;
        uVar15 = extraout_EDX;
      }
      uVar20 = (ulonglong)uVar15 << 0x20;
      if (0x1f < DAT_0040e800) goto switchD_004021d3_caseD_2;
    }
switchD_004021d3_default:
    uVar15 = (uint)(uVar20 >> 0x20);
    if (param_2 != 0) {
      return (uint *)0x0;
    }
  } while( true );
}


/*
 * FUN_00402770 at 00402770
 * undefined FUN_00402770(void)
 * Address ranges: 00402770-00402893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LRESULT FUN_00402770(HWND param_1,UINT param_2,ushort param_3,LPARAM param_4)

{
  int *piVar1;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_2 == 6) {
    SendMessageA(*(HWND *)(DAT_00410440 + 0x464),0x5a78,(uint)param_3,param_4);
    iVar3 = DAT_00410440;
    if (param_3 != 0) {
      puVar5 = (undefined4 *)(DAT_00410440 + 0x46c);
      *(undefined4 *)(DAT_00410440 + 0x460) = 1;
      LVar2 = CallWindowProcA((WNDPROC)*puVar5,param_1,6,(uint)param_3,param_4);
      if (*(int *)(DAT_00410440 + 8) == 2) {
        puVar5 = *(undefined4 **)(DAT_00410440 + 0x44c);
        puVar6 = *(undefined4 **)(DAT_00410440 + 0x448);
        for (iVar3 = 16000; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
      }
      else {
        FUN_00402be0(*(int *)(DAT_00410440 + 0x10) * *(int *)(DAT_00410440 + 0x14),0);
      }
      return LVar2;
    }
    piVar1 = (int *)(DAT_00410440 + 8);
    *(undefined4 *)(DAT_00410440 + 0x460) = 0;
    if (*piVar1 == 2) {
      puVar5 = *(undefined4 **)(iVar3 + 0x448);
      puVar6 = *(undefined4 **)(iVar3 + 0x44c);
      for (iVar4 = 16000; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
    }
  }
  LVar2 = CallWindowProcA(*(WNDPROC *)(DAT_00410440 + 0x46c),param_1,param_2,(uint)param_3,param_4);
  return LVar2;
}


/*
 * FUN_004028a0 at 004028a0
 * undefined FUN_004028a0(void)
 * Address ranges: 004028a0-004028fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


LRESULT FUN_004028a0(HWND param_1,UINT param_2,ushort param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if ((param_2 == 0x112) && ((param_3 & 0xfff0) == 0xf120)) {
    SetFocus(*(HWND *)(DAT_00410440 + 0x470));
    LVar1 = 0;
  }
  else {
    LVar1 = CallWindowProcA(*(WNDPROC *)(DAT_00410440 + 0x468),param_1,param_2,(uint)param_3,param_4
                           );
  }
  return LVar1;
}


/*
 * _SmackBufferString@8 at 00402900
 * char * __stdcall _SmackBufferString@8(char * param_1, ushort param_2)
 * Address ranges: 00402900-00402933
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * _SmackBufferString_8(char *param_1,ushort param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
                    /* 0x2900  1  _SmackBufferString@8 */
  if (4 < param_2) {
    param_2 = 4;
  }
  pcVar2 = (&PTR_s_Automatic_0040e824)[param_2];
  do {
    pcVar3 = param_1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar3 = cVar1;
    param_1 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return pcVar3;
}


/*
 * FUN_00402940 at 00402940
 * undefined __stdcall FUN_00402940(void)
 * Address ranges: 00402940-004029f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00402940(void)

{
  int in_EAX;
  int iVar1;
  HPALETTE pHVar2;
  int iVar3;
  uint uVar4;
  LOGPALETTE local_420 [128];
  undefined4 local_1c;
  
  local_420[0].palVersion = 0x300;
  local_420[0].palNumEntries = *(WORD *)(in_EAX + 0x2c);
  uVar4 = 0;
  if (*(int *)(in_EAX + 0x2c) != 0) {
    iVar1 = 0;
    iVar3 = in_EAX;
    do {
      (&local_420[0].palPalEntry[0].peRed)[iVar1] = *(BYTE *)(iVar3 + 0x3e);
      (&local_420[0].palPalEntry[0].peBlue)[iVar1] = *(BYTE *)(iVar3 + 0x3c);
      (&local_420[0].palPalEntry[0].peGreen)[iVar1] = *(BYTE *)(iVar3 + 0x3d);
      if ((uVar4 < *(uint *)(in_EAX + 0x34)) || (*(uint *)(in_EAX + 0x38) <= uVar4)) {
        local_1c = 0;
      }
      else {
        local_1c = 4;
      }
      iVar3 = iVar3 + 4;
      (&local_420[0].palPalEntry[0].peFlags)[iVar1] = (BYTE)local_1c;
      uVar4 = uVar4 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar4 < *(uint *)(in_EAX + 0x2c));
  }
  pHVar2 = CreatePalette(local_420);
  *(HPALETTE *)(in_EAX + 0x458) = pHVar2;
  if (*(int *)(in_EAX + 8) == 4) {
    (*DAT_00410454)(*(undefined4 *)(in_EAX + 0x45c),0,*(undefined4 *)(in_EAX + 0x2c),in_EAX + 0x3c);
  }
  return;
}


/*
 * FUN_00402a00 at 00402a00
 * undefined __stdcall FUN_00402a00(void)
 * Address ranges: 00402a00-00402a91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00402a00(void)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_24 [2];
  undefined4 *local_1c;
  
  puVar4 = (undefined4 *)(in_EAX + 0x3c);
  puVar5 = (undefined4 *)&DAT_00410038;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  if (*(int *)(in_EAX + 8) == 1) {
    uVar1 = 5;
  }
  else {
    uVar1 = 1;
  }
  local_24[0] = (uVar1 | 0x8ac0) * 0x10000 + 0x400;
  local_24[1] = 0x428;
  local_1c = &DAT_00410010;
  SendMessageA(*(HWND *)(in_EAX + 0x470),0x4a,0,(LPARAM)local_24);
  iVar2 = 0;
  iVar3 = 0;
  do {
    *(short *)((int)&DAT_00410038 + iVar3) = (short)iVar2;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 2;
  } while (iVar2 < 0x100);
  return;
}


/*
 * FUN_00402aa0 at 00402aa0
 * undefined8 __fastcall FUN_00402aa0(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00402aa0-00402afb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00402aa0(undefined4 param_1,undefined4 param_2)

{
  UINT UVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  tagWNDCLASSA tStack_38;
  
  UVar1 = SetErrorMode(0x8000);
  DVar2 = LoadModule(s_DISPDIB_DLL_0040e0d4,&DAT_0040e814);
  UVar1 = SetErrorMode(UVar1);
  if (DVar2 < 0x20) {
    uVar4 = UVar1 & 0xffffff00;
  }
  else {
    BVar3 = GetClassInfoA((HINSTANCE)0x0,s_DisplayDibWindow_0040e0e0,&tStack_38);
    uVar4 = (uint)(BVar3 != 0);
  }
  return CONCAT44(param_2,uVar4);
}


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


/*
 * FUN_00402be0 at 00402be0
 * undefined __fastcall FUN_00402be0(undefined4 param_1, WPARAM param_2)
 * Address ranges: 00402be0-00402c05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00402be0(undefined4 param_1,WPARAM param_2)

{
  HWND in_EAX;
  
  SendMessageA(in_EAX,0x4a,param_2,(LPARAM)&stack0xfffffff4);
  return;
}


/*
 * FUN_00402c10 at 00402c10
 * undefined __stdcall FUN_00402c10(void)
 * Address ranges: 00402c10-00402c24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00402c10(void)

{
  FUN_0040650f();
  return;
}


/*
 * FUN_00402c30 at 00402c30
 * undefined __fastcall FUN_00402c30(undefined4 param_1, undefined4 param_2, int param_3)
 * Address ranges: 00402c30-00402c61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00402c30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
    return;
  }
  if (param_3 == -1) {
    iVar1 = 0;
  }
  else {
    uVar3 = FUN_00406420(param_1,param_2);
    iVar1 = (int)uVar3;
  }
  bVar2 = 0x10 - ((byte)iVar1 & 0xf);
  *(byte *)((uint)bVar2 + iVar1 + -1) = bVar2;
  return;
}


/*
 * FUN_00402c70 at 00402c70
 * undefined4 * __stdcall FUN_00402c70(uint param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5)
 * Address ranges: 00402c70-00402ce4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 *
FUN_00402c70(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar3 = param_2 - (int)param_4;
  puVar2 = param_4;
  if ((uVar3 <= param_1) && (puVar2 = param_3, uVar3 != 0)) {
    puVar4 = param_5;
    for (uVar1 = uVar3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = *param_4;
      param_4 = param_4 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar1 = uVar3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_4;
      param_4 = (undefined4 *)((int)param_4 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    param_5 = (undefined4 *)((int)param_5 + uVar3);
    param_1 = param_1 - uVar3;
  }
  if (param_1 != 0) {
    puVar4 = puVar2;
    for (uVar3 = param_1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_5 = *puVar4;
      puVar4 = puVar4 + 1;
      param_5 = param_5 + 1;
    }
    for (uVar3 = param_1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      param_5 = (undefined4 *)((int)param_5 + 1);
    }
    puVar2 = (undefined4 *)((int)puVar2 + param_1);
  }
  return puVar2;
}


/*
 * _SmackWait@4 at 00402cf0
 * longlong __fastcall _SmackWait@4(undefined4 param_1, uint param_2, int param_3)
 * Address ranges: 00402cf0-00402e09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall _SmackWait_4(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  DWORD DVar5;
  undefined8 uVar6;
  
                    /* 0x2cf0  32  _SmackWait@4 */
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
      param_2 = extraout_EDX;
    }
    if (*(int *)(param_3 + 0x420) == -1) {
      if (*(int *)(param_3 + 0x3f8) != 0) {
        return (ulonglong)param_2 << 0x20;
      }
      DVar5 = timeGetTime();
      uVar3 = *(uint *)(param_3 + 0x3fc);
      uVar4 = DVar5 * 100;
      uVar2 = extraout_ECX_00;
      if (uVar3 == 0xffffffff) {
        DVar5 = *(DWORD *)(param_3 + 0x400);
        *(uint *)(param_3 + 0x3fc) = uVar4 + DVar5;
      }
      else if (uVar3 <= uVar4) {
        iVar1 = uVar3 + *(int *)(param_3 + 0x400);
        uVar3 = uVar4 - iVar1;
        *(int *)(param_3 + 0x3fc) = iVar1;
        if (*(uint *)(param_3 + 0x400) < uVar3) {
          *(uint *)(param_3 + 0x3fc) = uVar4 + *(uint *)(param_3 + 0x400);
        }
        if (*(int *)(param_3 + 0x400) != 0) {
          *(undefined4 *)(param_3 + 0x3f8) = 1;
        }
        return (ulonglong)uVar3 << 0x20;
      }
    }
    else {
      if ((*(int *)(param_3 + 0x424) == 0) || (*(int *)(param_3 + 0x428) != 0)) {
        return (ulonglong)param_2 << 0x20;
      }
      uVar3 = (*DAT_00410478)(*(undefined4 *)(param_3 + 0x404 + *(int *)(param_3 + 0x420) * 4));
      DVar5 = *(uint *)(*(int *)(param_3 + 0x404 + *(int *)(param_3 + 0x420) * 4) + 0x20) >> 7;
      uVar2 = extraout_ECX;
      if (DVar5 <= uVar3) {
        *(undefined4 *)(param_3 + 0x424) = 0;
        return (ulonglong)DVar5 << 0x20;
      }
    }
    uVar6 = FUN_00405c60(uVar2,DVar5);
    param_2 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}


/*
 * _SmackSoundCheck@0 at 00402e10
 * undefined __stdcall _SmackSoundCheck@0(void)
 * Address ranges: 00402e10-00402e21
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackSoundCheck_0(void)

{
                    /* 0x2e10  31  _SmackSoundCheck@0 */
  if (DAT_0040e83c != 0) {
    (*DAT_00410474)();
  }
  return;
}


/*
 * _SmackVolumePan@16 at 00402e30
 * undefined __stdcall _SmackVolumePan@16(int param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00402e30-00402ecf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackVolumePan_16(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
                    /* 0x2e30  30  _SmackVolumePan@16 */
  if ((param_1 != 0) && (*(int *)(param_1 + 0x420) != -1)) {
    if (0x10000 < param_3) {
      param_3 = 0x10000;
    }
    if (0x10000 < param_4) {
      param_4 = 0x10000;
    }
    while ((param_2 & 0xfe000) != 0) {
      uVar2 = 0x2000;
      bVar3 = 0;
      do {
        if ((uVar2 & param_2) != 0) {
          param_2 = param_2 & ~uVar2;
          goto LAB_00402e9d;
        }
        bVar3 = bVar3 + 1;
        uVar2 = uVar2 * 2;
      } while (bVar3 < 7);
      bVar3 = 0xff;
LAB_00402e9d:
      if (((bVar3 < 7) && (iVar1 = *(int *)((uint)bVar3 * 4 + param_1 + 0x404), iVar1 != 0)) &&
         (DAT_0040e858 != (code *)0x0)) {
        (*DAT_0040e858)(param_4,param_3,iVar1);
      }
    }
  }
  return;
}


/*
 * _SmackSoundInTrack@8 at 00402ed0
 * undefined4 __stdcall _SmackSoundInTrack@8(int param_1, uint param_2)
 * Address ranges: 00402ed0-00402f36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 _SmackSoundInTrack_8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
                    /* 0x2ed0  29  _SmackSoundInTrack@8 */
  if (param_1 == 0) {
LAB_00402f2f:
    uVar3 = 0;
  }
  else {
    do {
      if ((param_2 & 0xfe000) == 0) goto LAB_00402f2f;
      uVar1 = 0x2000;
      bVar4 = 0;
      do {
        if ((uVar1 & param_2) != 0) {
          param_2 = param_2 & ~uVar1;
          goto LAB_00402f0b;
        }
        bVar4 = bVar4 + 1;
        uVar1 = uVar1 * 2;
      } while (bVar4 < 7);
      bVar4 = 0xff;
LAB_00402f0b:
      iVar2 = (uint)bVar4 * 4 + param_1;
    } while (((*(uint *)(iVar2 + 0x48) >> 0x18 & 0x40) == 0) ||
            ((*(uint *)(iVar2 + 0x48) & 0xffffff) == 0));
    uVar3 = 1;
  }
  return uVar3;
}


/*
 * _SmackToBufferRect@8 at 00402f40
 * undefined4 __fastcall _SmackToBufferRect@8(undefined4 param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00402f40-004031c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall
_SmackToBufferRect_8(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  DWORD DVar3;
  uint uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  int iStack_18;
  int iStack_14;
  
                    /* 0x2f40  28  _SmackToBufferRect@8 */
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
      param_1 = extraout_ECX;
      param_2 = extraout_EDX;
    }
    if ((*(int *)(param_3 + 0x3e4) == 0) || (param_4 == 2)) {
      return 0;
    }
    if (*(int *)(param_3 + 0x468) == 0) {
      DVar3 = timeGetTime();
      iVar6 = *(int *)(param_3 + 0x464);
      *(DWORD *)(param_3 + 0x468) = DVar3;
      param_1 = extraout_ECX_00;
      param_2 = extraout_EDX_00;
      if (iVar6 != 0) {
        *(undefined4 *)(param_3 + 0x464) = 0;
        *(DWORD *)(param_3 + 0x484) = *(int *)(param_3 + 0x484) + (DVar3 - iVar6);
      }
    }
    if (*(int *)(param_3 + 0x3e4) == 1) {
      uVar10 = FUN_0040d540(param_1,param_2,*(int *)(param_3 + 0x3a0),(uint *)(param_3 + 1000));
      if ((char)uVar10 == '\0') {
        *(undefined4 *)(param_3 + 0x3e4) = 0;
        if (*(int *)(param_3 + 0x68) == 0) {
          return 0;
        }
        *(undefined4 *)(param_3 + 0x374) = 0;
        *(undefined4 *)(param_3 + 0x378) = 0;
        *(undefined4 *)(param_3 + 0x37c) = 0;
        *(undefined4 *)(param_3 + 0x380) = 0;
        return 1;
      }
      *(undefined4 *)(param_3 + 0x3e4) = 2;
    }
    puVar1 = (uint *)(param_3 + 1000);
    uVar7 = *(uint *)(param_3 + 1000);
    iStack_18 = *(int *)(param_3 + 0x3ec);
    iVar6 = *(int *)(param_3 + 0x3f4);
    iStack_14 = iStack_18 + iVar6;
    uVar9 = *(int *)(param_3 + 0x3f0) + uVar7;
    if (param_4 == 1) {
      while( true ) {
        uVar10 = FUN_0040d540(*(undefined4 *)(param_3 + 0x3a0),iVar6,
                              *(undefined4 *)(param_3 + 0x3a0),puVar1);
        iVar6 = (int)((ulonglong)uVar10 >> 0x20);
        if ((char)uVar10 == '\0') break;
        if (*(uint *)(param_3 + 1000) < uVar7) {
          uVar7 = *(uint *)(param_3 + 1000);
        }
        uVar4 = *(int *)(param_3 + 1000) + *(int *)(param_3 + 0x3f0);
        if (uVar9 < uVar4) {
          uVar9 = uVar4;
        }
        iStack_14 = *(int *)(param_3 + 0x3ec) + *(int *)(param_3 + 0x3f4);
      }
LAB_00403155:
      *(undefined4 *)(param_3 + 0x3e4) = 0;
    }
    else {
      uVar8 = (uint)(*(int *)(param_3 + 0x3f0) * *(int *)(param_3 + 0x3f4) * 5) >> 2;
      uVar5 = uVar7;
      uVar4 = uVar9;
      iVar6 = iStack_14;
      do {
        iStack_14 = iVar6;
        uVar9 = uVar4;
        uVar7 = uVar5;
        uVar10 = FUN_0040d540(*(undefined4 *)(param_3 + 0x3a0),puVar1,
                              *(undefined4 *)(param_3 + 0x3a0),puVar1);
        if ((char)uVar10 == '\0') goto LAB_00403155;
        uVar8 = uVar8 + ((uint)(*(int *)(param_3 + 0x3f0) * *(int *)(param_3 + 0x3f4) * 5) >> 2);
        uVar5 = *(uint *)(param_3 + 1000);
        if (uVar7 <= *(uint *)(param_3 + 1000)) {
          uVar5 = uVar7;
        }
        uVar4 = *(int *)(param_3 + 1000) + *(int *)(param_3 + 0x3f0);
        if (uVar4 < uVar9) {
          uVar4 = uVar9;
        }
        iVar6 = *(int *)(param_3 + 0x3ec) + *(int *)(param_3 + 0x3f4);
      } while ((iVar6 - iStack_18) * (uVar4 - uVar5) <= uVar8);
    }
    if ((*(byte *)(param_3 + 0x386) & 0x30) != 0) {
      iStack_18 = iStack_18 * 2;
      iStack_14 = iStack_14 * 2;
    }
    *(uint *)(param_3 + 0x374) = uVar7 + *(int *)(param_3 + 0x388);
    *(int *)(param_3 + 0x378) = iStack_18 + *(int *)(param_3 + 0x38c);
    *(uint *)(param_3 + 0x37c) = uVar9 - uVar7;
    *(int *)(param_3 + 0x380) = iStack_14 - iStack_18;
    uVar2 = 1;
  }
  return uVar2;
}


/*
 * _SmackGoto@8 at 004031d0
 * undefined __thiscall _SmackGoto@8(void * this, uint param_1, int param_2)
 * Address ranges: 004031d0-004031ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall _SmackGoto_8(void *this,uint param_1,int param_2)

{
  undefined4 extraout_ECX;
  
                    /* 0x31d0  27  _SmackGoto@8 */
  if (param_1 != 0) {
    if (param_2 != 0) {
      param_2 = param_2 + -1;
    }
    if (param_2 != *(int *)(param_1 + 0x370)) {
      *(int *)(param_1 + 0x370) = param_2;
      FUN_00405740(this,param_1);
      FUN_004053e0(extraout_ECX);
    }
  }
  return;
}


/*
 * _SmackGetTrackData@12 at 00403200
 * uint __stdcall _SmackGetTrackData@12(int param_1, uint * param_2, uint param_3)
 * Address ranges: 00403200-00403317
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint _SmackGetTrackData_12(int param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  
                    /* 0x3200  26  _SmackGetTrackData@12 */
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x2000;
    bVar4 = 0;
    do {
      if ((uVar2 & param_3) != 0) goto LAB_0040323d;
      bVar4 = bVar4 + 1;
      uVar2 = uVar2 * 2;
    } while (bVar4 < 7);
    bVar4 = 0xff;
LAB_0040323d:
    if (6 < bVar4) {
      return 0;
    }
    iVar3 = (uint)bVar4 * 4 + param_1;
    puVar1 = *(uint **)(iVar3 + 0x3c4);
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    if ((*(uint *)(iVar3 + 0x48) >> 0x18 & 0x80) != 0) {
      if ((puVar1[1] != 0) && (puVar1[1] != 0xffffffff)) {
        if (DAT_0040e840 == (uint *)0x0) {
          uVar5 = *(int *)(param_1 + 0x45c) + 0x2000;
          uVar2 = *(uint *)(param_1 + 0x49c);
          *(uint *)(param_1 + 0x45c) = uVar5;
          if (uVar2 < uVar5) {
            *(uint *)(param_1 + 0x49c) = uVar5;
          }
          DAT_0040e840 = (uint *)FUN_00402c30(param_1,uVar2,0x2000);
          if (DAT_0040e840 == (uint *)0x0) {
            return 0;
          }
        }
        FUN_0040ccf0(puVar1 + 2,puVar1[1],DAT_0040e840,param_2,param_2 + 0x400000,param_2);
      }
      return puVar1[1];
    }
    uVar2 = *puVar1 - 4;
    if ((uVar2 != 0) && (uVar2 != 0xffffffff)) {
      puVar6 = puVar1;
      for (uVar5 = uVar2 >> 2; puVar6 = puVar6 + 1, uVar5 != 0; uVar5 = uVar5 - 1) {
        *param_2 = *puVar6;
        param_2 = param_2 + 1;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(char *)param_2 = (char)*puVar6;
        puVar6 = (uint *)((int)puVar6 + 1);
        param_2 = (uint *)((int)param_2 + 1);
      }
    }
    uVar2 = *puVar1 - 4;
  }
  return uVar2;
}


/*
 * _SmackColorRemap@16 at 0040333c
 * undefined __stdcall _SmackColorRemap@16(int param_1, int param_2, uint param_3, uint param_4)
 * Address ranges: 0040333c-00403449
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackColorRemap_16(int param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_134 [256];
  int local_34;
  uint local_30;
  byte *local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined1 local_18;
  byte local_14;
  
                    /* 0x333c  25  _SmackColorRemap@16 */
  if (param_1 != 0) {
    if (0x100 < param_3) {
      param_3 = 0x100;
    }
    if ((param_4 & 8) == 0) {
      iVar8 = ((param_4 & 1) != 0) + 3;
    }
    else {
      iVar8 = 8;
    }
    local_24 = param_4 & 0xe;
    local_2c = (byte *)(param_1 + 0x6c);
    local_28 = local_24 * 4;
    local_30 = 0;
    do {
      pbVar6 = local_2c + 1;
      local_20 = 0xffffffff;
      bVar1 = *local_2c;
      local_14 = local_2c[2];
      local_2c = local_2c + 3;
      local_1c = 0;
      uVar5 = local_30;
      if (param_3 != 0) {
        do {
          if (local_24 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)((int)&PTR_FUN_00403320 + local_28))();
            return;
          }
          iVar7 = uVar5 * iVar8;
          iVar2 = (uint)bVar1 - ((int)(uint)*(byte *)(param_2 + 2 + iVar7) >> 2);
          iVar4 = (uint)*pbVar6 - ((int)(uint)*(byte *)(param_2 + 4 + iVar7) >> 2);
          local_34 = iVar2 * iVar2 + iVar4 * iVar4;
          iVar2 = (uint)local_14 - ((int)(uint)*(byte *)(param_2 + 6 + iVar7) >> 2);
          uVar3 = iVar2 * iVar2 + local_34;
          if (uVar3 < local_20) {
            local_18 = (undefined1)uVar5;
            local_20 = uVar3;
            if (uVar3 == 0) break;
          }
          uVar5 = uVar5 + 1;
          if (uVar5 == 0x100) {
            uVar5 = 0;
          }
          local_1c = local_1c + 1;
        } while (local_1c < param_3);
      }
      auStack_134[local_30] = local_18;
      local_30 = local_30 + 1;
    } while (local_30 < 0x100);
    FUN_0040d660(*(int **)(param_1 + 0x39c),auStack_134);
  }
  return;
}


/*
 * FUN_0040344a at 0040344a
 * undefined FUN_0040344a(void)
 * Address ranges: 0040344a-00403490
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_0040344a(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int iStack00000100;
  uint in_stack_00000104;
  ushort *in_stack_00000108;
  int in_stack_0000010c;
  uint in_stack_00000110;
  uint in_stack_00000114;
  uint in_stack_00000118;
  undefined1 in_stack_0000011c;
  byte in_stack_00000120;
  int in_stack_00000138;
  uint in_stack_00000140;
  
  iVar4 = unaff_EBX * unaff_EDI;
  iVar2 = (param_1 & 0xff) - (uint)*(byte *)(unaff_ESI + iVar4);
  iVar3 = (param_1 >> 8 & 0xff) - (uint)*(byte *)(unaff_ESI + 1 + iVar4);
  iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
  uVar1 = (uint)*(byte *)(unaff_ESI + 2 + iVar4);
  do {
    uVar1 = (in_stack_00000120 - uVar1) * (in_stack_00000120 - uVar1) + iStack00000100;
    if (uVar1 < in_stack_00000114) {
      in_stack_0000011c = (undefined1)unaff_EBX;
      in_stack_00000114 = uVar1;
      if (uVar1 != 0) goto LAB_0040362d;
LAB_00403656:
      do {
        (&stack0x00000000)[in_stack_00000104] = in_stack_0000011c;
        unaff_EBX = in_stack_00000104 + 1;
        if (0xff < unaff_EBX) {
          FUN_0040d660(*(int **)(in_stack_00000138 + 0x39c),&stack0x00000000);
          return;
        }
        in_stack_00000114 = 0xffffffff;
        in_stack_00000120 = (byte)in_stack_00000108[1];
        param_1 = (uint)*in_stack_00000108;
        in_stack_00000108 = (ushort *)((int)in_stack_00000108 + 3);
        in_stack_00000118 = 0;
        in_stack_00000104 = unaff_EBX;
      } while (in_stack_00000140 == 0);
    }
    else {
LAB_0040362d:
      unaff_EBX = unaff_EBX + 1;
      if (unaff_EBX == 0x100) {
        unaff_EBX = 0;
      }
      in_stack_00000118 = in_stack_00000118 + 1;
      if (in_stack_00000140 <= in_stack_00000118) goto LAB_00403656;
    }
    if (in_stack_00000110 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)&PTR_FUN_00403320 + in_stack_0000010c))();
      return;
    }
    iVar4 = unaff_EBX * unaff_EDI;
    iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
    iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 4 + iVar4) >> 2);
    iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
    uVar1 = (int)(uint)*(byte *)(unaff_ESI + 6 + iVar4) >> 2;
  } while( true );
}


/*
 * FUN_00403491 at 00403491
 * undefined FUN_00403491(void)
 * Address ranges: 00403491-004034f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_00403491(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int iStack00000100;
  uint in_stack_00000104;
  ushort *in_stack_00000108;
  int in_stack_0000010c;
  uint in_stack_00000110;
  uint in_stack_00000114;
  uint in_stack_00000118;
  undefined1 in_stack_0000011c;
  byte in_stack_00000120;
  int in_stack_00000138;
  uint in_stack_00000140;
  
  iVar4 = unaff_EBX * unaff_EDI;
  iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + iVar4) >> 2);
  iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 1 + iVar4) >> 2);
  iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
  iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
  uVar1 = iVar2 * iVar2 + iStack00000100;
  do {
    if (uVar1 < in_stack_00000114) {
      in_stack_0000011c = (undefined1)unaff_EBX;
      in_stack_00000114 = uVar1;
      if (uVar1 != 0) goto LAB_0040362d;
LAB_00403656:
      do {
        (&stack0x00000000)[in_stack_00000104] = in_stack_0000011c;
        unaff_EBX = in_stack_00000104 + 1;
        if (0xff < unaff_EBX) {
          FUN_0040d660(*(int **)(in_stack_00000138 + 0x39c),&stack0x00000000);
          return;
        }
        in_stack_00000114 = 0xffffffff;
        in_stack_00000120 = (byte)in_stack_00000108[1];
        param_1 = (uint)*in_stack_00000108;
        in_stack_00000108 = (ushort *)((int)in_stack_00000108 + 3);
        in_stack_00000118 = 0;
        in_stack_00000104 = unaff_EBX;
      } while (in_stack_00000140 == 0);
    }
    else {
LAB_0040362d:
      unaff_EBX = unaff_EBX + 1;
      if (unaff_EBX == 0x100) {
        unaff_EBX = 0;
      }
      in_stack_00000118 = in_stack_00000118 + 1;
      if (in_stack_00000140 <= in_stack_00000118) goto LAB_00403656;
    }
    if (in_stack_00000110 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)&PTR_FUN_00403320 + in_stack_0000010c))();
      return;
    }
    iVar4 = unaff_EBX * unaff_EDI;
    iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
    iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 4 + iVar4) >> 2);
    iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
    iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + 6 + iVar4) >> 2);
    uVar1 = iVar2 * iVar2 + iStack00000100;
  } while( true );
}


/*
 * FUN_004034f3 at 004034f3
 * undefined FUN_004034f3(void)
 * Address ranges: 004034f3-00403542
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_004034f3(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int iStack00000100;
  uint in_stack_00000104;
  ushort *in_stack_00000108;
  int in_stack_0000010c;
  uint in_stack_00000110;
  uint in_stack_00000114;
  uint in_stack_00000118;
  undefined1 in_stack_0000011c;
  byte in_stack_00000120;
  int in_stack_00000138;
  uint in_stack_00000140;
  
  iVar4 = unaff_EBX * unaff_EDI;
  iVar2 = (param_1 & 0xff) - (uint)*(byte *)(unaff_ESI + 2 + iVar4);
  iVar3 = (param_1 >> 8 & 0xff) - (uint)*(byte *)(unaff_ESI + 1 + iVar4);
  iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
  iVar2 = (uint)in_stack_00000120 - (uint)*(byte *)(unaff_ESI + iVar4);
  do {
    uVar1 = iVar2 * iVar2 + iStack00000100;
    if (uVar1 < in_stack_00000114) {
      in_stack_0000011c = (undefined1)unaff_EBX;
      in_stack_00000114 = uVar1;
      if (uVar1 != 0) goto LAB_0040362d;
LAB_00403656:
      do {
        (&stack0x00000000)[in_stack_00000104] = in_stack_0000011c;
        unaff_EBX = in_stack_00000104 + 1;
        if (0xff < unaff_EBX) {
          FUN_0040d660(*(int **)(in_stack_00000138 + 0x39c),&stack0x00000000);
          return;
        }
        in_stack_00000114 = 0xffffffff;
        in_stack_00000120 = (byte)in_stack_00000108[1];
        param_1 = (uint)*in_stack_00000108;
        in_stack_00000108 = (ushort *)((int)in_stack_00000108 + 3);
        in_stack_00000118 = 0;
        in_stack_00000104 = unaff_EBX;
      } while (in_stack_00000140 == 0);
    }
    else {
LAB_0040362d:
      unaff_EBX = unaff_EBX + 1;
      if (unaff_EBX == 0x100) {
        unaff_EBX = 0;
      }
      in_stack_00000118 = in_stack_00000118 + 1;
      if (in_stack_00000140 <= in_stack_00000118) goto LAB_00403656;
    }
    if (in_stack_00000110 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)&PTR_FUN_00403320 + in_stack_0000010c))();
      return;
    }
    iVar4 = unaff_EBX * unaff_EDI;
    iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
    iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 4 + iVar4) >> 2);
    iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
    iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + 6 + iVar4) >> 2);
  } while( true );
}


/*
 * FUN_00403543 at 00403543
 * undefined FUN_00403543(void)
 * Address ranges: 00403543-004036a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_00403543(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int iStack00000100;
  uint in_stack_00000104;
  ushort *in_stack_00000108;
  int in_stack_0000010c;
  uint in_stack_00000110;
  uint in_stack_00000114;
  uint in_stack_00000118;
  undefined1 in_stack_0000011c;
  byte in_stack_00000120;
  int in_stack_00000138;
  uint in_stack_00000140;
  
  iVar4 = unaff_EBX * unaff_EDI;
  iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
  iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 1 + iVar4) >> 2);
  iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
  iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + iVar4) >> 2);
  uVar1 = iVar2 * iVar2 + iStack00000100;
  do {
    if (uVar1 < in_stack_00000114) {
      in_stack_0000011c = (undefined1)unaff_EBX;
      in_stack_00000114 = uVar1;
      if (uVar1 != 0) goto LAB_0040362d;
LAB_00403656:
      do {
        (&stack0x00000000)[in_stack_00000104] = in_stack_0000011c;
        unaff_EBX = in_stack_00000104 + 1;
        if (0xff < unaff_EBX) {
          FUN_0040d660(*(int **)(in_stack_00000138 + 0x39c),&stack0x00000000);
          return;
        }
        in_stack_00000114 = 0xffffffff;
        in_stack_00000120 = (byte)in_stack_00000108[1];
        param_1 = (uint)*in_stack_00000108;
        in_stack_00000108 = (ushort *)((int)in_stack_00000108 + 3);
        in_stack_00000118 = 0;
        in_stack_00000104 = unaff_EBX;
      } while (in_stack_00000140 == 0);
    }
    else {
LAB_0040362d:
      unaff_EBX = unaff_EBX + 1;
      if (unaff_EBX == 0x100) {
        unaff_EBX = 0;
      }
      in_stack_00000118 = in_stack_00000118 + 1;
      if (in_stack_00000140 <= in_stack_00000118) goto LAB_00403656;
    }
    if (in_stack_00000110 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)&PTR_FUN_00403320 + in_stack_0000010c))();
      return;
    }
    iVar4 = unaff_EBX * unaff_EDI;
    iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
    iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 4 + iVar4) >> 2);
    iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
    iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + 6 + iVar4) >> 2);
    uVar1 = iVar2 * iVar2 + iStack00000100;
  } while( true );
}


/*
 * _SmackColorTrans@8 at 004036b0
 * undefined __stdcall _SmackColorTrans@8(int param_1, undefined1 * param_2)
 * Address ranges: 004036b0-004036d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackColorTrans_8(int param_1,undefined1 *param_2)

{
                    /* 0x36b0  24  _SmackColorTrans@8 */
  if (param_1 != 0) {
    FUN_0040d660(*(int **)(param_1 + 0x39c),param_2);
  }
  return;
}


/*
 * _SmackToBuffer@28 at 004036e0
 * undefined __fastcall _SmackToBuffer@28(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9)
 * Address ranges: 004036e0-004038fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall
_SmackToBuffer_28(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,int param_9)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 extraout_ECX;
  undefined4 uVar6;
  undefined4 extraout_EDX;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  int local_18;
  uint local_14;
  
                    /* 0x36e0  23  _SmackToBuffer@28 */
  if (param_3 == 0) {
    return;
  }
  if (param_8 == 0) {
    if (*(int *)(param_3 + 0x3a0) == 0) {
      return;
    }
    FUN_00402c10();
    *(undefined4 *)(param_3 + 0x3a0) = 0;
    *(int *)(param_3 + 0x45c) = *(int *)(param_3 + 0x45c) - *(int *)(param_3 + 0x3a4);
    return;
  }
  bVar1 = *(byte *)(param_3 + 0x386);
  uVar6 = CONCAT31((int3)((uint)param_2 >> 8),bVar1);
  local_18 = 3;
  uVar3 = *(uint *)(param_3 + 8) >> 1;
  if ((bVar1 & 0x10) == 0) {
    iVar8 = param_6;
    local_14 = *(uint *)(param_3 + 8);
    if ((bVar1 & 0x20) != 0) {
      local_18 = 7;
      local_14 = uVar3;
    }
  }
  else {
    iVar8 = param_6 * 2;
    local_14 = uVar3;
  }
  if (*(char **)(param_3 + 0x3a0) != (char *)0x0) {
    if (**(char **)(param_3 + 0x3a0) == '\x01') goto LAB_00403805;
    FUN_00402c10();
    *(int *)(param_3 + 0x45c) = *(int *)(param_3 + 0x45c) - *(int *)(param_3 + 0x3a4);
    uVar6 = extraout_EDX;
  }
  uVar9 = FUN_0040d520(*(undefined4 *)(param_3 + 4),uVar6,*(undefined4 *)(param_3 + 4),local_14);
  uVar3 = (int)uVar9 + 0x20;
  *(uint *)(param_3 + 0x3a4) = uVar3;
  uVar4 = *(int *)(param_3 + 0x45c) + uVar3;
  *(uint *)(param_3 + 0x45c) = uVar4;
  if (*(uint *)(param_3 + 0x49c) < uVar4) {
    *(uint *)(param_3 + 0x49c) = uVar4;
  }
  puVar5 = (undefined4 *)FUN_00402c30(extraout_ECX,uVar3,uVar3);
  *(undefined4 **)(param_3 + 0x3a0) = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    return;
  }
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
LAB_00403805:
  *(int *)(param_3 + 0x38c) = param_5;
  *(int *)(param_3 + 0x388) = param_4;
  puVar2 = *(undefined1 **)(param_3 + 0x3a0);
  *puVar2 = 1;
  puVar2[1] = (*(byte *)(param_3 + 0x386) & 0x20) != 0;
  if (param_9 != 0) {
    param_5 = (param_7 - param_5) + -1;
  }
  iVar7 = local_18 * iVar8;
  *(int *)(puVar2 + 4) = param_5 * param_6 + param_8 + param_4;
  *(uint *)(puVar2 + 8) = *(uint *)(param_3 + 4) >> 2;
  *(uint *)(puVar2 + 0xc) = local_14 >> 2;
  if (param_9 == 0) {
    *(int *)(puVar2 + 0x10) = iVar7 + -4;
    *(int *)(puVar2 + 0x14) = iVar7;
    *(int *)(puVar2 + 0x18) = iVar8;
    *(int *)(puVar2 + 0x1c) = iVar7 + (iVar8 - *(int *)(param_3 + 4));
  }
  else {
    *(int *)(puVar2 + 0x10) = -(iVar7 + 4);
    *(int *)(puVar2 + 0x14) = -iVar7;
    *(int *)(puVar2 + 0x18) = -iVar8;
    *(int *)(puVar2 + 0x1c) = -(iVar8 * (local_18 + 2) - (iVar8 - *(int *)(param_3 + 4)));
  }
  *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(param_3 + 4);
  *(uint *)(puVar2 + 0x28) = local_14;
  return;
}


/*
 * _SmackToScreen@24 at 00403900
 * undefined __stdcall _SmackToScreen@24(int param_1, uint param_2, int param_3, int param_4, int param_5, int param_6)
 * Address ranges: 00403900-00403e59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackToScreen_24(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  short sVar17;
  undefined4 *local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  int local_2c;
  int local_28;
  short local_24;
  int local_20;
  short local_1c;
  uint local_18;
  undefined4 *local_14;
  
                    /* 0x3900  22  _SmackToScreen@24 */
  local_44 = (undefined4 *)0x0;
  if (param_1 != 0) {
    if (param_4 == 0x140) {
      param_6 = 0;
      param_5 = 0xa0000;
    }
    pcVar2 = *(char **)(param_1 + 0x3a0);
    if (pcVar2 != (char *)0x0) {
      if (*pcVar2 == '\x01') {
        local_2c = *(int *)(pcVar2 + 0x18);
        local_44 = *(undefined4 **)(pcVar2 + 4);
      }
      FUN_00402c10();
      *(int *)(param_1 + 0x45c) = *(int *)(param_1 + 0x45c) - *(int *)(param_1 + 0x3a4);
    }
    local_20 = param_4;
    local_18 = 4;
    local_38 = 0;
    local_24 = 3;
    iVar1 = param_4 * 2;
    uVar12 = *(uint *)(param_1 + 8) >> 1;
    uVar13 = uVar12;
    iVar14 = iVar1;
    iVar6 = iVar1;
    if (((*(byte *)(param_1 + 0x386) & 0x10) == 0) &&
       (uVar13 = *(uint *)(param_1 + 8), iVar14 = param_4, iVar6 = local_20,
       (*(byte *)(param_1 + 0x386) & 0x20) != 0)) {
      local_38 = param_4;
      local_18 = 8;
      local_24 = 7;
      uVar13 = uVar12;
      iVar14 = iVar1;
    }
    local_20 = iVar6;
    iVar1 = *(int *)(param_1 + 4);
    iVar6 = *(int *)(param_1 + 4) * local_18 * (param_3 * param_4 + iVar14 * uVar13 >> 0x10) + 0x400
    ;
    *(int *)(param_1 + 0x3a4) = iVar6;
    uVar12 = *(int *)(param_1 + 0x45c) + iVar6;
    *(uint *)(param_1 + 0x45c) = uVar12;
    if (*(uint *)(param_1 + 0x49c) < uVar12) {
      *(uint *)(param_1 + 0x49c) = uVar12;
    }
    iVar6 = FUN_00402c30(uVar12,iVar6,iVar6);
    *(int *)(param_1 + 0x3a0) = iVar6;
    if (iVar6 != 0) {
      param_2 = param_2 & 0xfffffffc;
      *(int *)(param_1 + 0x38c) = param_3;
      *(uint *)(param_1 + 0x388) = param_2;
      local_14 = (undefined4 *)(*(int *)(param_1 + 0x3a0) + 0x400);
      puVar3 = *(undefined1 **)(param_1 + 0x3a0);
      *puVar3 = 0;
      puVar3[1] = (*(byte *)(param_1 + 0x386) & 0x20) != 0;
      local_3c = param_2 + param_4 * param_3;
      local_40 = local_3c >> 0x10;
      *(int *)(puVar3 + 4) = param_6;
      sVar4 = (short)local_20;
      *(short *)(puVar3 + 8) = sVar4 - *(short *)(param_1 + 4);
      if (param_6 == 0) {
        uVar11 = 0xfffe;
      }
      else {
        iVar6 = local_40 * 2;
        local_40 = local_40 + 1;
        uVar11 = *(undefined2 *)(iVar6 + param_5);
      }
      *(undefined2 *)(puVar3 + 10) = uVar11;
      sVar17 = (short)local_18;
      piVar7 = (int *)FUN_00403e60(local_24,sVar4,sVar17);
      piVar9 = piVar7 + 1;
      if (param_6 == 0) {
        *piVar7 = param_5 + local_3c;
        *(short *)piVar9 = (short)(uVar13 >> 2);
        *(undefined2 *)((int)piVar7 + 6) = 0xffff;
      }
      else {
        local_3c = local_3c & 0xffff;
        *piVar7 = local_3c + 0xa0000;
        local_1c = 0;
        local_28 = *(int *)(param_1 + 4) * uVar13;
        if (local_28 != 0) {
          local_1c = 0;
          do {
            if (local_3c < 0x10001) {
              if (local_3c + local_38 + iVar14 * 3 + iVar1 < 0x10001) {
                if (local_44 != (undefined4 *)0x0) {
                  local_44 = local_44 + local_2c;
                }
                local_1c = local_1c + 1;
                local_3c = local_3c + iVar14 * 4;
              }
              else {
                *(short *)piVar9 = local_1c;
                *(short *)((int)piVar9 + 2) = -2;
                local_1c = 0;
                puVar8 = (undefined4 *)
                         FUN_00403e60(local_24,(short)*(undefined4 *)(param_1 + 4),sVar17);
                *puVar8 = local_14;
                *(undefined2 *)(puVar8 + 1) = 1;
                *(undefined2 *)((int)puVar8 + 6) = 0xfffd;
                puVar8[2] = local_14;
                if (local_44 == (undefined4 *)0x0) {
                  local_14 = (undefined4 *)((int)local_14 + *(int *)(param_1 + 4) * local_18);
                }
                else {
                  uVar13 = 0;
                  if (local_18 != 0) {
                    do {
                      uVar12 = *(uint *)(param_1 + 4);
                      puVar15 = local_44;
                      puVar16 = local_14;
                      for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                        *puVar16 = *puVar15;
                        puVar15 = puVar15 + 1;
                        puVar16 = puVar16 + 1;
                      }
                      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
                        *(undefined1 *)puVar16 = *(undefined1 *)puVar15;
                        puVar15 = (undefined4 *)((int)puVar15 + 1);
                        puVar16 = (undefined4 *)((int)puVar16 + 1);
                      }
                      uVar13 = uVar13 + 1;
                      local_14 = (undefined4 *)((int)local_14 + *(int *)(param_1 + 4));
                      local_44 = (undefined4 *)((int)local_44 + local_2c);
                    } while (uVar13 < local_18);
                  }
                }
                uVar13 = 0;
                puVar8[3] = local_3c + 0xa0000;
                while (local_3c + local_20 < 0x10001) {
                  uVar13 = uVar13 + 1;
                  local_3c = local_3c + local_20;
                }
                sVar5 = (short)uVar13;
                *(short *)(puVar8 + 4) = sVar5;
                if (local_3c < 0x10001) {
                  uVar12 = 0x10000 - local_3c;
                  if (*(uint *)(param_1 + 4) < 0x10000 - local_3c) {
                    uVar12 = *(uint *)(param_1 + 4);
                  }
                  *(undefined2 *)((int)puVar8 + 0x12) = (short)(uVar12 >> 2);
                  *(undefined2 *)(puVar8 + 5) = *(undefined2 *)(local_40 * 2 + param_5);
                  *(short *)((int)puVar8 + 0x16) = (short)(*(int *)(param_1 + 4) - uVar12 >> 2);
                  sVar5 = (sVar17 - sVar5) + -1;
                }
                else {
                  *(undefined2 *)((int)puVar8 + 0x12) = 0;
                  *(undefined2 *)(puVar8 + 5) = *(undefined2 *)(local_40 * 2 + param_5);
                  *(undefined2 *)((int)puVar8 + 0x16) = 0;
                  sVar5 = sVar17 - sVar5;
                }
                local_40 = local_40 + 1;
                *(short *)(puVar8 + 6) = sVar5;
                local_3c = (local_18 - (uVar13 & 0xffff)) * local_20 + local_3c & 0xffff;
                piVar9 = (int *)FUN_00403e60(local_24,sVar4,sVar17);
              }
              local_28 = local_28 + *(int *)(param_1 + 4) * -4;
            }
            else {
              *(short *)piVar9 = local_1c;
              local_1c = 0;
              *(short *)((int)piVar9 + 2) = *(short *)(local_40 * 2 + param_5);
              piVar7 = (int *)FUN_00403e60(local_24,sVar4,sVar17);
              local_3c = local_3c & 0xffff;
              piVar9 = piVar7 + 1;
              *piVar7 = local_3c + 0xa0000;
              local_40 = local_40 + 1;
            }
          } while (local_28 != 0);
        }
        *(short *)piVar9 = local_1c;
        *(short *)((int)piVar9 + 2) = -1;
      }
    }
  }
  return;
}


/*
 * FUN_00403e60 at 00403e60
 * undefined __fastcall FUN_00403e60(short param_1, short param_2, short param_3)
 * Address ranges: 00403e60-00403e9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00403e60(short param_1,short param_2,short param_3)

{
  short *in_EAX;
  uint unaff_EBX;
  
  *in_EAX = param_2;
  in_EAX[1] = (short)(unaff_EBX >> 2);
  in_EAX[2] = param_1 * param_2 + -4;
  in_EAX[3] = param_1 * param_2;
  in_EAX[4] = param_2 * param_3 - (short)unaff_EBX;
  return;
}


/*
 * _SmackNextFrame@4 at 00403ea0
 * undefined __stdcall _SmackNextFrame@4(int param_1)
 * Address ranges: 00403ea0-00403f42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackNextFrame_4(int param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_ECX;
  
                    /* 0x3ea0  21  _SmackNextFrame@4 */
  if (param_1 != 0) {
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
    }
    FUN_00404060();
    uVar2 = *(int *)(param_1 + 0x370) + 1;
    iVar1 = *(int *)(*(int *)(param_1 + 0x3b8) + *(int *)(param_1 + 0x370) * 4);
    *(uint *)(param_1 + 0x370) = uVar2;
    *(int *)(param_1 + 0x3b0) = *(int *)(param_1 + 0x3b0) + iVar1;
    if ((uVar2 < *(uint *)(param_1 + 0xc)) && ((*(byte *)(param_1 + 0x385) & 2) == 0)) {
      *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(param_1 + 0x3ac);
      FUN_004059b0(uVar2,*(undefined4 **)(param_1 + 0x3ac));
      uVar2 = extraout_ECX;
    }
    FUN_004053e0(uVar2);
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
    }
  }
  return;
}


/*
 * _SmackSummary@8 at 00403f50
 * undefined __stdcall _SmackSummary@8(int param_1, int * param_2)
 * Address ranges: 00403f50-00404051
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackSummary_8(int param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x3f50  20  _SmackSummary@8 */
  FUN_00404060();
  DVar1 = timeGetTime();
  *param_2 = DVar1 - *(int *)(param_1 + 0x46c);
  param_2[1] = *(int *)(param_1 + 0x400);
  param_2[2] = *(int *)(param_1 + 0x470);
  param_2[3] = *(int *)(param_1 + 0x478);
  param_2[4] = *(int *)(param_1 + 0x47c);
  param_2[5] = *(int *)(param_1 + 0x480);
  param_2[6] = *(int *)(param_1 + 0x44c) - *(int *)(param_1 + 0x474);
  param_2[8] = *(int *)(param_1 + 0x454);
  param_2[7] = *(int *)(param_1 + 0x484);
  uVar3 = *(int *)(param_1 + 0x454) + *(int *)(param_1 + 0x44c);
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)(((ulonglong)(uint)(*(int *)(param_1 + 0x448) + *(int *)(param_1 + 0x450)) * 1000)
                 / (ulonglong)uVar3);
  }
  param_2[9] = iVar2;
  param_2[10] = *(int *)(param_1 + 0x488);
  param_2[0xc] = *(int *)(param_1 + 0x490) + 1;
  param_2[0xb] = *(int *)(param_1 + 0x48c);
  param_2[0xd] = *(int *)(param_1 + 0x494) + 1;
  param_2[0xe] = *(int *)(param_1 + 0x498);
  param_2[0x11] = *(int *)(param_1 + 0x49c);
  param_2[0x12] = *(int *)(param_1 + 0x440);
  param_2[0x13] = *(int *)(param_1 + 0x458);
  param_2[0xf] = *(int *)(param_1 + 0x4a4);
  param_2[0x10] = *(int *)(param_1 + 0x4a8) + 1;
  return;
}


/*
 * FUN_00404060 at 00404060
 * undefined __stdcall FUN_00404060(void)
 * Address ranges: 00404060-00404174
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00404060(void)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  uint uVar3;
  
  DVar2 = 0xffffffff;
  if (*(int *)(in_EAX + 0x460) != 0) {
    DVar2 = timeGetTime();
    uVar3 = DVar2 - *(int *)(in_EAX + 0x460);
    *(undefined4 *)(in_EAX + 0x460) = 0;
    if (*(uint *)(in_EAX + 0x488) < uVar3) {
      if (*(int *)(in_EAX + 0x490) != *(int *)(in_EAX + 0x370)) {
        *(undefined4 *)(in_EAX + 0x48c) = *(undefined4 *)(in_EAX + 0x488);
        *(undefined4 *)(in_EAX + 0x494) = *(undefined4 *)(in_EAX + 0x490);
        *(undefined4 *)(in_EAX + 0x490) = *(undefined4 *)(in_EAX + 0x370);
      }
      *(uint *)(in_EAX + 0x488) = uVar3;
    }
    else if ((*(uint *)(in_EAX + 0x48c) < uVar3) &&
            (*(int *)(in_EAX + 0x490) != *(int *)(in_EAX + 0x370))) {
      *(uint *)(in_EAX + 0x48c) = uVar3;
      *(undefined4 *)(in_EAX + 0x494) = *(undefined4 *)(in_EAX + 0x370);
    }
  }
  if (*(int *)(in_EAX + 0x468) != 0) {
    if (DVar2 == 0xffffffff) {
      DVar2 = timeGetTime();
    }
    iVar1 = *(int *)(in_EAX + 0x468);
    *(undefined4 *)(in_EAX + 0x468) = 0;
    *(DWORD *)(in_EAX + 0x480) = *(int *)(in_EAX + 0x480) + (DVar2 - iVar1);
  }
  if (*(int *)(in_EAX + 0x464) != 0) {
    if (DVar2 == 0xffffffff) {
      DVar2 = timeGetTime();
    }
    iVar1 = *(int *)(in_EAX + 0x464);
    *(undefined4 *)(in_EAX + 0x464) = 0;
    *(DWORD *)(in_EAX + 0x484) = *(int *)(in_EAX + 0x484) + (DVar2 - iVar1);
  }
  return;
}


/*
 * _SmackDoFrame@4 at 00404180
 * char __stdcall _SmackDoFrame@4(int param_1)
 * Address ranges: 00404180-00404257
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char _SmackDoFrame_4(int param_1)

{
  char cVar1;
  DWORD DVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar3;
  
                    /* 0x4180  19  _SmackDoFrame@4 */
  if (param_1 == 0) {
    cVar1 = '\0';
  }
  else {
    DVar2 = timeGetTime();
    *(DWORD *)(param_1 + 0x464) = DVar2;
    *(DWORD *)(param_1 + 0x460) = DVar2;
    if (*(int *)(param_1 + 0x46c) == 0) {
      *(DWORD *)(param_1 + 0x46c) = DVar2;
    }
    if (*(int *)(param_1 + 0x68) != 0) {
      *(undefined4 *)(param_1 + 0x3b4) = *(undefined4 *)(param_1 + 0x370);
    }
    *(int *)(param_1 + 0x478) = *(int *)(param_1 + 0x478) + 1;
    FUN_004042d0();
    if (((*(byte *)(param_1 + 0x385) & 4) == 0) && (*(int *)(param_1 + 0x400) != 0)) {
      uVar3 = FUN_00404260(extraout_ECX,extraout_EDX);
      cVar1 = (char)uVar3;
    }
    else {
      cVar1 = '\0';
    }
    if (*(int *)(param_1 + 0x3a0) != 0) {
      if (cVar1 == '\0') {
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        FUN_0040c920(*(undefined4 *)(param_1 + 0x3e0),*(undefined4 *)(param_1 + 0x39c),
                     (uint *)*(undefined4 *)(param_1 + 0x3e0),*(undefined4 *)(param_1 + 0x39c),
                     *(byte **)(param_1 + 0x3a0));
      }
      else {
        *(int *)(param_1 + 0x47c) = *(int *)(param_1 + 0x47c) + 1;
      }
    }
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
    }
  }
  return cVar1;
}


/*
 * FUN_00404260 at 00404260
 * undefined8 __fastcall FUN_00404260(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00404260-004042c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00404260(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX;
  if ((*(int *)(in_EAX + 0x420) != -1) && (*(int *)(in_EAX + 0x428) == 0)) {
    if (*(int *)(in_EAX + 0x424) == 0) {
      uVar1 = CONCAT31((int3)(in_EAX >> 8),1);
      goto LAB_004042c2;
    }
    uVar1 = *(uint *)(in_EAX + 0x404 + *(int *)(in_EAX + 0x420) * 4);
    if (*(int *)(uVar1 + 0x44) == 0) {
      uVar1 = (*DAT_00410478)(uVar1);
      if (*(uint *)(*(int *)(in_EAX + 0x404 + *(int *)(in_EAX + 0x420) * 4) + 0x24) >> 7 <= uVar1) {
        uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
        *(undefined4 *)(in_EAX + 0x424) = 0;
        goto LAB_004042c2;
      }
    }
  }
  uVar1 = uVar1 & 0xffffff00;
LAB_004042c2:
  return CONCAT44(param_2,uVar1);
}


/*
 * FUN_004042d0 at 004042d0
 * undefined __stdcall FUN_004042d0(void)
 * Address ranges: 004042d0-00404553
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004042d0(void)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint local_2c;
  uint local_20;
  byte local_1c;
  
  if ((*(int *)(in_EAX + 0x420) != -1) && (*(int *)(in_EAX + 0x428) == 0)) {
    if (*(int *)(in_EAX + 0x400) != 0) {
      *(undefined4 *)(in_EAX + 0x424) = 1;
    }
    iVar1 = *(int *)(*(int *)(in_EAX + 0x420) * 4 + in_EAX + 0x404);
    *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x1c);
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x1c);
    local_2c = *(uint *)(in_EAX + 900);
    local_1c = 0;
    uVar3 = 0x2000;
    do {
      if ((uVar3 & local_2c) != 0) {
        local_2c = local_2c & ~uVar3;
        goto LAB_0040436e;
      }
      local_1c = local_1c + 1;
      uVar3 = uVar3 * 2;
    } while (local_1c < 7);
    local_1c = 0xff;
LAB_0040436e:
    iVar4 = (uint)local_1c * 4 + in_EAX;
    piVar7 = *(int **)(iVar4 + 0x3c4);
    if (piVar7 == (int *)0x0) {
      local_20 = 0;
    }
    else if ((*(byte *)(iVar4 + 0x4b) & 0x80) == 0) {
      local_20 = *piVar7 - 4;
    }
    else {
      local_20 = piVar7[1];
    }
    *(uint *)(*(int *)((uint)local_1c * 4 + in_EAX + 0x404) + 0x44) = (uint)(local_20 == 0);
    if ((local_20 == 0) == 0) {
      if (DAT_0040e83c != 0) {
        (*DAT_00410474)();
      }
LAB_004043d9:
      piVar2 = *(int **)((uint)local_1c * 4 + in_EAX + 0x404);
      if ((uint)piVar2[6] < piVar2[4] + local_20) {
        local_20 = piVar2[6] - piVar2[4];
        piVar2[0xb] = piVar2[0xb] + 1;
      }
      if ((*(byte *)((uint)local_1c * 4 + in_EAX + 0x4b) & 0x80) == 0) {
        piVar8 = (int *)piVar2[3];
        piVar7 = piVar7 + 1;
        uVar3 = local_20;
        if ((undefined1 *)piVar2[1] < (undefined1 *)(local_20 + (int)piVar8)) {
          uVar5 = piVar2[1] - (int)piVar8;
          piVar6 = piVar7;
          for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *piVar8 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar8 = piVar8 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(char *)piVar8 = (char)*piVar6;
            piVar6 = (int *)((int)piVar6 + 1);
            piVar8 = (int *)((int)piVar8 + 1);
          }
          piVar8 = (int *)*piVar2;
          piVar7 = piVar7 + (piVar2[1] - piVar2[3]);
          uVar3 = local_20 - (piVar2[1] - piVar2[3]);
        }
        for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *piVar8 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar8 = piVar8 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(char *)piVar8 = (char)*piVar7;
          piVar7 = (int *)((int)piVar7 + 1);
          piVar8 = (int *)((int)piVar8 + 1);
        }
      }
      else {
        FUN_0040ccf0((uint *)(piVar7 + 2),local_20,DAT_0040e840,(uint *)*piVar2,(uint *)piVar2[1],
                     (uint *)piVar2[3]);
      }
      piVar2[10] = piVar2[10] + local_20;
      piVar2[4] = piVar2[4] + local_20;
      local_20 = piVar2[3] + local_20;
      piVar2[3] = local_20;
      if ((uint)piVar2[1] <= local_20) {
        piVar2[3] = *piVar2 + (local_20 - piVar2[1]);
      }
      uVar3 = 0x2000;
      local_1c = 0;
      do {
        if ((uVar3 & local_2c) != 0) {
          local_2c = local_2c & ~uVar3;
          goto LAB_004044f0;
        }
        local_1c = local_1c + 1;
        uVar3 = uVar3 * 2;
      } while (local_1c < 7);
      local_1c = 0xff;
LAB_004044f0:
      if (local_1c != 0xff) {
        iVar4 = (uint)local_1c * 4 + in_EAX;
        piVar7 = *(int **)(iVar4 + 0x3c4);
        if (piVar7 == (int *)0x0) {
          local_20 = 0;
        }
        else if ((*(byte *)(iVar4 + 0x4b) & 0x80) == 0) {
          local_20 = *piVar7 - 4;
        }
        else {
          local_20 = piVar7[1];
        }
        goto LAB_004043d9;
      }
    }
    if (*(uint *)(iVar1 + 0x28) < *(uint *)(iVar1 + 0x20) >> 7) {
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x28) << 7;
    }
  }
  return;
}


/*
 * _SmackClose@4 at 00404560
 * undefined __stdcall _SmackClose@4(undefined4 * param_1)
 * Address ranges: 00404560-0040469c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackClose_4(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
                    /* 0x4560  18  _SmackClose@4 */
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[0x108] != -1) {
      puVar3 = param_1;
      do {
        if (puVar3[0x101] != 0) {
          (*DAT_0041047c)(puVar3[0x101]);
          FUN_00402c10();
          FUN_00402c10();
          DAT_0040e83c = DAT_0040e83c + -1;
          puVar3[0x101] = 0;
        }
        puVar3 = puVar3 + 1;
      } while (puVar3 != param_1 + 7);
      param_1[0x108] = 0xffffffff;
    }
    iVar2 = DAT_0040e83c;
    if ((DAT_0040e83c == 0) && (DAT_0040e840 != 0)) {
      FUN_00402c10();
      DAT_0040e840 = iVar2;
    }
    if (((HANDLE)param_1[0xe5] != (HANDLE)0xffffffff) &&
       ((*(byte *)((int)param_1 + 0x385) & 0x10) == 0)) {
      CloseHandle((HANDLE)param_1[0xe5]);
    }
    if (param_1[0xe8] != 0) {
      FUN_00402c10();
    }
    if (param_1[0xe7] != 0) {
      FUN_00402c10();
    }
    if (param_1[0xef] != 0) {
      FUN_00402c10();
    }
    if (param_1[0xeb] != 0) {
      FUN_00402c10();
    }
    if (param_1[0x10b] != 0) {
      FUN_00402c10();
    }
    uVar1 = param_1[0xe1];
    for (iVar2 = 299; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    if ((uVar1 & 0x2000000) == 0) {
      FUN_00402c10();
    }
  }
  return;
}


/*
 * _SmackSoundOnOff@8 at 004046a0
 * undefined4 __stdcall _SmackSoundOnOff@8(uint param_1, int param_2)
 * Address ranges: 004046a0-004048b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 _SmackSoundOnOff_8(uint param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint local_14;
  
                    /* 0x46a0  17  _SmackSoundOnOff@8 */
  if (param_1 == 0) {
    uVar5 = 0;
  }
  else {
    uVar1 = param_1 + 0x1c;
    if (param_2 == 0) {
      if (*(int *)(param_1 + 0x428) == 0) {
        *(undefined4 *)(param_1 + 0x428) = 1;
        do {
          if (*(int *)(param_1 + 0x404) != 0) {
            if (DAT_0040e850 != (code *)0x0) {
              (*DAT_0040e850)(*(int *)(param_1 + 0x404));
            }
            puVar10 = *(undefined4 **)(param_1 + 0x404);
            puVar10[3] = *puVar10;
            puVar10[2] = *puVar10;
            iVar6 = puVar10[4];
            puVar10[4] = 0;
            puVar10[10] = puVar10[10] - iVar6;
          }
          param_1 = param_1 + 4;
        } while (param_1 != uVar1);
      }
    }
    else if (*(int *)(param_1 + 0x428) != 0) {
      local_14 = param_1;
      *(undefined4 *)(param_1 + 0x428) = 0;
      do {
        piVar2 = *(int **)(local_14 + 0x404);
        if (piVar2 != (int *)0x0) {
          if (DAT_0040e854 != (code *)0x0) {
            cVar3 = (*DAT_0040e854)(piVar2);
            if (cVar3 == '\0') {
              return 0;
            }
          }
          iVar6 = (*DAT_00410478)(piVar2);
          piVar2[9] = piVar2[9] - piVar2[8];
          piVar2[8] = iVar6 * 0x80;
          piVar2[9] = piVar2[9] + iVar6 * 0x80;
          if ((*(int *)(param_1 + 0x370) != 0) && ((uint)(piVar2[10] - iVar6) < (uint)piVar2[0xc]))
          {
            uVar7 = piVar2[0xc] - (piVar2[10] - iVar6);
            if ((uint)piVar2[6] < piVar2[4] + uVar7) {
              uVar7 = piVar2[6] - piVar2[4];
            }
            uVar9 = uVar7 & 0xfffffffc;
            if (piVar2[0x12] == 0) {
              uVar4 = 0x80;
            }
            else {
              uVar4 = 0;
            }
            puVar10 = (undefined4 *)piVar2[3];
            if ((undefined1 *)((int)puVar10 + uVar9) < (undefined1 *)piVar2[1]) {
              for (uVar7 = uVar7 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar10 = CONCAT22(CONCAT11(uVar4,uVar4),CONCAT11(uVar4,uVar4));
                puVar10 = puVar10 + 1;
              }
              for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                *(undefined1 *)puVar10 = uVar4;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              piVar2[3] = piVar2[3] + uVar9;
            }
            else {
              uVar8 = piVar2[1] - (int)puVar10;
              for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar10 = CONCAT22(CONCAT11(uVar4,uVar4),CONCAT11(uVar4,uVar4));
                puVar10 = puVar10 + 1;
              }
              for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar10 = uVar4;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              uVar8 = uVar9 - (piVar2[1] - piVar2[3]);
              puVar10 = (undefined4 *)*piVar2;
              for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar10 = CONCAT22(CONCAT11(uVar4,uVar4),CONCAT11(uVar4,uVar4));
                puVar10 = puVar10 + 1;
              }
              for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined1 *)puVar10 = uVar4;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
              piVar2[3] = (*piVar2 + uVar9) - (piVar2[3] - piVar2[1]);
            }
            piVar2[4] = piVar2[4] + uVar9;
            piVar2[10] = piVar2[10] + uVar9;
          }
        }
        local_14 = local_14 + 4;
      } while (local_14 < uVar1);
      return 1;
    }
    uVar5 = 1;
  }
  return uVar5;
}


/*
 * _SmackFrameRate@4 at 004048c0
 * undefined __stdcall _SmackFrameRate@4(int param_1)
 * Address ranges: 004048c0-004048e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackFrameRate_4(int param_1)

{
                    /* 0x48c0  16  _SmackFrameRate@4 */
  if (0 < param_1) {
    param_1 = (int)(100000 / (longlong)-param_1);
  }
  DAT_0040e848 = param_1;
  return;
}


/*
 * _SmackSimulate@4 at 004048f0
 * undefined __stdcall _SmackSimulate@4(undefined4 param_1)
 * Address ranges: 004048f0-004048fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _SmackSimulate_4(undefined4 param_1)

{
                    /* 0x48f0  15  _SmackSimulate@4 */
  DAT_0040e844 = param_1;
  return;
}


/*
 * _SmackOpen@12 at 00404900
 * int * __stdcall _SmackOpen@12(int * param_1, uint param_2, uint param_3)
 * Address ranges: 00404900-00405151
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int * _SmackOpen_12(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int *piVar2;
  uint *puVar3;
  DWORD DVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar5;
  uint extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 uVar6;
  uint extraout_ECX_10;
  uint extraout_ECX_11;
  uint extraout_ECX_12;
  uint extraout_ECX_13;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar7;
  uint uVar8;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint extraout_EDX_03;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint *local_2c;
  DWORD local_28;
  DWORD local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
                    /* 0x4900  14  _SmackOpen@12 */
  uVar10 = 0;
  local_14 = 0;
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  local_24 = timeGetTime();
  if ((param_2 & 0x1000) == 0) {
    local_20 = CreateFileA((LPCSTR)param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,
                           (HANDLE)0x0);
    local_28 = 0;
    uVar6 = extraout_ECX_00;
    uVar7 = extraout_EDX_00;
  }
  else {
    local_20 = param_1;
    if ((param_2 & 0x2000000) != 0) {
      local_20 = (int *)*param_1;
    }
    local_28 = SetFilePointer(local_20,0,(PLONG)0x0,1);
    uVar6 = extraout_ECX;
    uVar7 = extraout_EDX;
  }
  if (local_20 == (int *)0xffffffff) {
    return (int *)0x0;
  }
  if (((param_2 & 0x2000000) == 0) &&
     (param_1 = (int *)FUN_00402c30(uVar6,uVar7,0x4ac), param_1 == (int *)0x0)) {
    return (int *)0x0;
  }
  piVar2 = param_1;
  for (iVar5 = 299; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)piVar2 = 0;
    piVar2 = (int *)((int)piVar2 + 1);
  }
  param_1[0x117] = 0x4ac;
  param_1[0xe5] = (int)local_20;
  param_1[0xea] = local_28;
  if ((param_2 & 0x800) != 0) {
    param_1[0x128] = DAT_0040e844;
  }
  local_28 = 0;
  *param_1 = 0;
  FUN_004059b0(0,param_1);
  if (*param_1 != 0x324b4d53) goto LAB_00404a15;
  if ((param_2 & 0x80) != 0) {
    param_1[4] = DAT_0040e848;
  }
  iVar5 = param_1[4];
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  else {
    iVar5 = iVar5 * 100;
  }
  param_1[0x100] = iVar5;
  if (iVar5 == 0) {
    local_18 = 100000;
    uVar8 = extraout_ECX_01;
  }
  else {
    uVar8 = param_1[0x100];
    local_18 = (uint)(100000 / (ulonglong)uVar8);
  }
  if (local_18 == 0) {
    local_18 = 1;
  }
  local_28 = param_1[3] + (param_1[5] & 1U);
  iVar5 = local_28 * 5 + 4;
  uVar11 = param_1[0x117] + iVar5;
  param_1[0x117] = uVar11;
  if ((uint)param_1[0x127] < uVar11) {
    param_1[0x127] = uVar11;
  }
  iVar5 = FUN_00402c30(uVar8,iVar5,iVar5);
  param_1[0xef] = iVar5;
  if (iVar5 == 0) goto LAB_00404a15;
  param_1[0xee] = (int)(local_28 + iVar5);
  FUN_004059b0(extraout_ECX_02,(undefined4 *)(local_28 + iVar5));
  FUN_004059b0(extraout_ECX_03,(undefined4 *)param_1[0xef]);
  param_1[0xea] = param_1[0xea] + local_28 * 5;
  iVar5 = FUN_00409c90();
  iVar5 = iVar5 + param_1[0xe] + param_1[0xf] + param_1[0x10] + param_1[0x11];
  uVar8 = param_1[0x127];
  uVar11 = param_1[0x117] + iVar5;
  param_1[0x117] = uVar11;
  if (uVar8 < uVar11) {
    param_1[0x127] = uVar11;
  }
  iVar5 = FUN_00402c30(uVar8,iVar5,iVar5);
  param_1[0xe7] = iVar5;
  if (iVar5 == 0) {
    FUN_00402c10();
    goto LAB_00404a15;
  }
  uVar8 = param_1[0xd] + 0x1003U & 0xfffffffc;
  if (uVar8 < 0x2000) {
    uVar8 = 0x2000;
  }
  uVar11 = param_1[0x117] + uVar8;
  param_1[0x117] = uVar11;
  if ((uint)param_1[0x127] < uVar11) {
    param_1[0x127] = uVar11;
  }
  piVar2 = (int *)FUN_00402c30(uVar11,uVar8,uVar8);
  if (piVar2 != (int *)0x0) {
    FUN_004059b0(extraout_ECX_04,piVar2 + 0x400);
    FUN_00409ca0((void *)param_1[0xe],piVar2,(undefined4 *)param_1[0xe7],(void *)param_1[0xe],
                 param_1[0xf],param_1[0x10],param_1[0x11]);
    FUN_00402c10();
    param_1[0x117] = param_1[0x117] - (param_1[0xd] + 0x1000);
    param_1[0xea] = param_1[0xea] + param_1[0xd] + 0x68;
    local_28 = param_1[3] + -1 + (param_1[5] & 1U);
    uVar8 = 0;
    puVar3 = (uint *)param_1[0xee];
    if (local_28 < local_18) {
      local_1c = 0;
      uVar9 = 0;
      do {
        uVar11 = *puVar3;
        uVar8 = uVar8 + uVar11;
        if (local_14 < uVar11) {
          local_14 = uVar11;
        }
        uVar11 = *puVar3;
        puVar3 = puVar3 + 1;
        uVar9 = uVar9 + 1;
        uVar10 = uVar10 + uVar11;
      } while (uVar9 <= local_28);
    }
    else {
      uVar11 = 0;
      uVar9 = 0;
      if (local_18 != 0) {
        do {
          uVar9 = uVar9 + 1;
          uVar11 = uVar11 + *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar9 < local_18);
      }
      puVar3 = (uint *)param_1[0xee];
      uVar9 = 0;
      local_2c = puVar3 + local_18;
      do {
        if ((uVar8 < uVar11) && (uVar9 != 0)) {
          uVar8 = uVar11;
          local_1c = uVar9;
        }
        uVar11 = (uVar11 - *puVar3) + *local_2c;
        if (local_14 < *puVar3) {
          local_14 = *puVar3;
        }
        uVar10 = uVar10 + *puVar3;
        local_2c = local_2c + 1;
        uVar9 = uVar9 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar9 <= local_28 - local_18);
      for (; uVar9 <= local_28; uVar9 = uVar9 + 1) {
        if (local_14 < *puVar3) {
          local_14 = *puVar3;
        }
        uVar11 = *puVar3;
        puVar3 = puVar3 + 1;
        uVar10 = uVar10 + uVar11;
      }
    }
    param_1[0x12a] = local_1c;
    param_1[0x129] = uVar8;
    param_1[0x126] = uVar10 / uVar9;
    if ((param_2 & 0x200) == 0) {
      if (param_3 == 0xffffffff) {
        if (param_1[0x100] == 0) {
          param_3 = 0x3000;
        }
        else {
          param_3 = param_1[0x129];
        }
        if (uVar10 >> 2 < param_3) {
          param_3 = uVar10 >> 2;
        }
        if (param_3 < 0x3000) {
          param_3 = 0x3000;
        }
      }
      param_3 = param_3 + 0xfff & 0xfffff000;
      if (param_3 < 0x2000) {
        param_3 = 0x2000;
      }
      if (param_3 < (uVar10 * 4) / 5) {
        param_1[0x110] = param_3;
        param_1[0xe6] = local_14;
        if (param_3 != 0) {
          iVar5 = param_3 + 0x1000;
          uVar10 = param_1[0x117] + iVar5;
          param_1[0x117] = uVar10;
          if ((uint)param_1[0x127] < uVar10) {
            param_1[0x127] = uVar10;
          }
          iVar5 = FUN_00402c30(uVar10,iVar5,iVar5);
          param_1[0x10b] = iVar5;
          param_1[0x10d] = iVar5;
          param_1[0x10e] = iVar5;
          if (iVar5 == 0) goto LAB_00404bd7;
          param_1[0x10c] = iVar5 + param_1[0x110];
        }
      }
      else {
        param_2 = param_2 | 0x200;
        param_1[0xe6] = uVar10;
      }
    }
    else {
      param_1[0xe6] = uVar10;
    }
    iVar5 = param_1[0xe6] + 8;
    uVar10 = param_1[0x127];
    uVar8 = param_1[0x117] + iVar5;
    param_1[0x117] = uVar8;
    if (uVar10 < uVar8) {
      param_1[0x127] = uVar8;
    }
    iVar5 = FUN_00402c30(uVar10,iVar5,iVar5);
    param_1[0xeb] = iVar5;
    if (iVar5 != 0) {
      param_1[0x111] = param_1[0xea];
      if ((param_2 & 0x200) == 0) {
        local_28 = param_1[0xea] & 0xfff;
        uVar6 = extraout_ECX_05;
        if (local_28 != 0) {
          ReadFile((HANDLE)param_1[0xe5],(LPVOID)param_1[0x10b],0x1000 - local_28,&local_28,
                   (LPOVERLAPPED)0x0);
          param_1[0x10e] = local_28 + param_1[0x10b];
          param_1[0x10f] = local_28;
          uVar6 = extraout_ECX_08;
        }
        if ((*(byte *)((int)param_1 + 0x385) & 2) == 0) {
          param_1[0xec] = param_1[0xeb];
          FUN_004059b0(uVar6,(undefined4 *)param_1[0xeb]);
          uVar6 = extraout_ECX_09;
        }
      }
      else {
        FUN_004059b0(extraout_ECX_05,(undefined4 *)param_1[0xeb]);
        uVar6 = extraout_ECX_06;
        if ((param_2 & 0x1000) == 0) {
          CloseHandle((HANDLE)param_1[0xe5]);
          uVar6 = extraout_ECX_07;
        }
        param_1[0xe5] = -1;
        param_1[0xec] = param_1[0xeb];
      }
      param_1[0xed] = -1;
      FUN_004053e0(uVar6);
      param_1[0x108] = -1;
      param_1[0xe1] = param_2 & 0xffc01fff;
      uVar10 = extraout_ECX_10;
      uVar8 = extraout_EDX_01;
      while ((param_2 & 0xfe000) != 0) {
        uVar8 = 0x2000;
        bVar1 = 0;
        do {
          if ((uVar8 & param_2) != 0) {
            uVar10 = param_2 & ~uVar8;
            param_2 = uVar10;
            goto LAB_00404fe0;
          }
          bVar1 = bVar1 + 1;
          uVar8 = uVar8 * 2;
        } while (bVar1 < 7);
        bVar1 = 0xff;
LAB_00404fe0:
        local_28 = (DWORD)bVar1;
        iVar5 = FUN_00405d70(uVar10,0x74);
        param_1[local_28 + 0x101] = iVar5;
        uVar10 = extraout_ECX_11;
        uVar8 = local_28;
        if (param_1[local_28 + 0x101] != 0) {
          uVar10 = FUN_00405160(extraout_ECX_11,(byte)local_28);
          if ((char)uVar10 == '\0') {
            FUN_00402c10();
            param_1[0x117] = param_1[0x117] + -0x74;
            param_1[local_28 + 0x101] = 0;
            uVar10 = extraout_ECX_12;
            uVar8 = extraout_EDX_03;
          }
          else {
            uVar10 = local_28 + 0xd;
            param_1[0xe1] = param_1[0xe1] | 1 << ((byte)uVar10 & 0x1f);
            uVar8 = extraout_EDX_02;
          }
        }
      }
      param_1[0xff] = -1;
      uVar12 = CONCAT44(uVar8,param_2) & 0xffffffff00000100;
      while ((int)uVar12 != 0) {
        uVar12 = FUN_00405c60(uVar10,(int)(uVar12 >> 0x20));
        uVar10 = extraout_ECX_13;
      }
      uVar10 = param_2 & 0x300000;
      if (uVar10 < 0x200000) {
        if (uVar10 != 0x100000) goto LAB_004050c0;
        uVar10 = param_1[5] & 0xfffffff9U | 2;
      }
      else {
        if (0x200000 < uVar10) {
          if (uVar10 == 0x300000) {
            *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0xf9;
          }
          goto LAB_004050c0;
        }
        uVar10 = param_1[5] & 0xfffffff9U | 4;
      }
      param_1[5] = uVar10;
LAB_004050c0:
      uVar10 = param_1[5] & 6;
      if (1 < uVar10) {
        if (uVar10 < 3) {
          *(byte *)((int)param_1 + 0x386) = *(byte *)((int)param_1 + 0x386) | 0x10;
        }
        else if (uVar10 == 4) {
          *(byte *)((int)param_1 + 0x386) = *(byte *)((int)param_1 + 0x386) | 0x20;
        }
      }
      if ((*(byte *)((int)param_1 + 0x386) & 0x30) != 0) {
        param_1[2] = param_1[2] * 2;
      }
      DVar4 = timeGetTime();
      param_1[0x11c] = DVar4 - local_24;
      iVar5 = param_1[0x115];
      param_1[0x115] = 0;
      param_1[0x113] = param_1[0x113] + iVar5;
      param_1[0x112] = param_1[0x112] + param_1[0x114];
      param_1[0x11d] = param_1[0x113];
      return param_1;
    }
    if (param_1[0x10b] != 0) {
      FUN_00402c10();
    }
  }
LAB_00404bd7:
  FUN_00402c10();
  FUN_00402c10();
LAB_00404a15:
  if ((param_2 & 0x1000) == 0) {
    CloseHandle((HANDLE)param_1[0xe5]);
  }
  if ((param_2 & 0x2000000) != 0) {
    return (int *)0x0;
  }
  FUN_00402c10();
  return (int *)0x0;
}


/*
 * FUN_00405160 at 00405160
 * uint __fastcall FUN_00405160(undefined4 param_1, byte param_2)
 * Address ranges: 00405160-004053d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_00405160(undefined4 param_1,byte param_2)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  if (DAT_0040e84c == (code *)0x0) {
    _SmackSoundUseWin_0();
  }
  iVar3 = (uint)param_2 * 4 + in_EAX;
  if ((*(uint *)(iVar3 + 0x48) >> 0x18 & 0x40) == 0) {
    uVar4 = 0;
    bVar12 = true;
  }
  else {
    uVar4 = *(uint *)(iVar3 + 0x48) & 0xffffff;
    bVar12 = uVar4 == 0;
  }
  if (bVar12) {
    uVar4 = uVar4 & 0xffffff00;
  }
  else {
    iVar3 = in_EAX + (uint)param_2 * 4;
    bVar8 = (byte)((uint)*(undefined4 *)(iVar3 + 0x48) >> 0x1c) & 1;
    bVar9 = (byte)((uint)*(undefined4 *)(iVar3 + 0x48) >> 0x1d) & 1;
    uVar10 = (bVar9 + 1) * uVar4 * (bVar8 + 1);
    if (DAT_0040e840 == 0) {
      uVar6 = *(int *)(in_EAX + 0x45c) + 0x2000;
      *(uint *)(in_EAX + 0x45c) = uVar6;
      if (*(uint *)(in_EAX + 0x49c) < uVar6) {
        *(uint *)(in_EAX + 0x49c) = uVar6;
      }
      DAT_0040e840 = FUN_00402c30(uVar6,0x2000,0x2000);
      if (DAT_0040e840 == 0) {
        return 0;
      }
    }
    uVar6 = (uint)param_2;
    puVar11 = *(undefined4 **)(in_EAX + 0x404 + uVar6 * 4);
    for (iVar3 = 0x1d; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    uVar7 = *(int *)(in_EAX + 0x400) << 7;
    *(int *)(*(int *)(in_EAX + 0x404 + uVar6 * 4) + 0x1c) =
         (int)(((ulonglong)uVar10 * (ulonglong)uVar7) / 100000);
    *(uint *)(*(int *)(in_EAX + 0x404 + uVar6 * 4) + 0x24) = uVar10 * 0x40;
    iVar3 = *(int *)(in_EAX + 0x404 + uVar6 * 4);
    *(uint *)(iVar3 + 0x18) = ((*(uint *)(iVar3 + 0x1c) >> 6) + uVar10 + 0xfff >> 8 & 0xfffff0) << 8
    ;
    iVar3 = *(int *)(in_EAX + 0x404 + uVar6 * 4);
    if (*(uint *)(iVar3 + 0x18) < 0x2000) {
      *(undefined4 *)(iVar3 + 0x18) = 0x2000;
    }
    iVar3 = in_EAX + (uint)param_2 * 4;
    iVar5 = FUN_00405d70(uVar7,*(int *)(*(int *)(iVar3 + 0x404) + 0x18));
    *(int *)(*(int *)(iVar3 + 0x404) + 8) = iVar5;
    *(int *)(*(int *)(iVar3 + 0x404) + 0xc) = iVar5;
    **(int **)(iVar3 + 0x404) = iVar5;
    *(int *)(*(int *)(iVar3 + 0x404) + 4) = iVar5 + *(int *)(*(int *)(iVar3 + 0x404) + 0x18);
    piVar1 = *(int **)(iVar3 + 0x404);
    if (*piVar1 == 0) {
      return (uint)piVar1 & 0xffffff00;
    }
    piVar1[5] = uVar10;
    *(uint *)(*(int *)(iVar3 + 0x404) + 0x40) = uVar4;
    *(uint *)(*(int *)(iVar3 + 0x404) + 0x48) = (uint)bVar9;
    *(uint *)(*(int *)(iVar3 + 0x404) + 0x4c) = (uint)bVar8;
    cVar2 = (*DAT_0040e84c)(*(undefined4 *)(in_EAX + 900),*(undefined4 *)(iVar3 + 0x404));
    if (cVar2 == '\0') {
      FUN_00402c10();
      uVar4 = *(uint *)(iVar3 + 0x404);
      *(int *)(in_EAX + 0x45c) = *(int *)(in_EAX + 0x45c) - *(int *)(uVar4 + 0x18);
      return uVar4 & 0xffffff00;
    }
    uVar4 = *(uint *)(iVar3 + 0x404);
    *(uint *)(uVar4 + 0x30) = *(int *)(iVar3 + 0x18) - (*(uint *)(uVar4 + 0x1c) >> 7);
    if (*(int *)(in_EAX + 0x420) == -1) {
      uVar4 = (uint)bVar9;
      *(uint *)(in_EAX + 0x420) = uVar4;
    }
    DAT_0040e83c = DAT_0040e83c + 1;
    uVar4 = CONCAT31((int3)(uVar4 >> 8),1);
  }
  return uVar4;
}


/*
 * FUN_004053e0 at 004053e0
 * undefined __fastcall FUN_004053e0(undefined4 param_1)
 * Address ranges: 004053e0-0040573a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004053e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  uint in_EAX;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  undefined4 auStack_330 [192];
  uint local_30;
  uint local_24;
  
  *(undefined4 *)(in_EAX + 0x3f8) = 0;
  local_30 = in_EAX;
  if (-1 < *(int *)(in_EAX + 0x370) - *(int *)(in_EAX + 0xc)) {
    if ((*(byte *)(in_EAX + 0x14) & 1) == 0) {
      *(undefined4 *)(in_EAX + 0x370) = 0;
    }
    else {
      if (*(int *)(in_EAX + 0x370) == *(int *)(in_EAX + 0xc)) {
        if ((*(byte *)(in_EAX + 0x385) & 2) == 0) {
          *(undefined4 *)(in_EAX + 0x3b0) = *(undefined4 *)(in_EAX + 0x3ac);
          FUN_004059b0(param_1,*(undefined4 **)(in_EAX + 0x3ac));
        }
        goto LAB_00405495;
      }
      *(undefined4 *)(in_EAX + 0x370) = 1;
    }
    FUN_00405740(param_1,in_EAX);
  }
LAB_00405495:
  pbVar7 = *(byte **)(local_30 + 0x3b0);
  *(byte **)(local_30 + 0x3c0) = pbVar7;
  bVar4 = *(byte *)(*(int *)(local_30 + 0x3bc) + *(int *)(local_30 + 0x370));
  if ((bVar4 & 1) != 0) {
    pbVar7 = pbVar7 + (uint)*pbVar7 * 4;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 2) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3c4) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 4) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3c8) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 8) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3cc) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x10) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3d0) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x20) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3d4) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x40) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3d8) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  pbVar10 = pbVar7;
  if ((bVar4 & 0x80) == 0) {
    pbVar10 = (byte *)0x0;
  }
  *(byte **)(local_30 + 0x3dc) = pbVar10;
  if (pbVar10 != (byte *)0x0) {
    pbVar7 = pbVar7 + *(int *)pbVar7;
  }
  *(byte **)(local_30 + 0x3e0) = pbVar7;
  if ((bVar4 & 1) != 0) {
    iVar1 = *(int *)(local_30 + 0x3b0);
    puVar8 = (undefined4 *)(local_30 + 0x6c);
    local_24 = 0;
    puVar9 = puVar8;
    puVar11 = auStack_330;
    for (iVar5 = 0xc0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    pbVar7 = (byte *)(iVar1 + 1);
    do {
      bVar4 = *pbVar7;
      if ((bVar4 & 0x80) == 0) {
        if ((bVar4 & 0x40) == 0) {
          puVar9 = (undefined4 *)((int)puVar8 + 3);
          uVar2 = *(undefined4 *)pbVar7;
          pbVar7 = pbVar7 + 3;
          local_24 = local_24 + 1;
          *puVar8 = uVar2;
        }
        else {
          bVar4 = (bVar4 & 0x3f) + 1;
          uVar3 = (uint)bVar4 * 3;
          puVar9 = (undefined4 *)((int)auStack_330 + (uint)pbVar7[1] * 3);
          puVar11 = puVar8;
          for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          puVar9 = (undefined4 *)((int)puVar8 + uVar3);
          local_24 = local_24 + bVar4;
          pbVar7 = pbVar7 + 2;
        }
      }
      else {
        bVar4 = (bVar4 & 0x7f) + 1;
        uVar3 = (uint)bVar4 * 3;
        puVar9 = (undefined4 *)((int)auStack_330 + (local_24 & 0xffff) * 3);
        puVar11 = puVar8;
        for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        puVar9 = (undefined4 *)((int)puVar8 + uVar3);
        local_24 = local_24 + bVar4;
        pbVar7 = pbVar7 + 1;
      }
      puVar8 = puVar9;
    } while ((ushort)local_24 < 0x100);
    if (*(int *)(local_30 + 0x3b4) != *(int *)(local_30 + 0x370)) {
      *(undefined4 *)(local_30 + 0x68) = 1;
      return;
    }
  }
  *(undefined4 *)(local_30 + 0x68) = 0;
  return;
}


/*
 * FUN_00405740 at 00405740
 * longlong __fastcall FUN_00405740(undefined4 param_1, uint param_2)
 * Address ranges: 00405740-004059a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall FUN_00405740(undefined4 param_1,uint param_2)

{
  int in_EAX;
  int iVar1;
  uint extraout_ECX;
  uint extraout_ECX_00;
  int iVar2;
  int *piVar3;
  uint lDistanceToMove;
  undefined4 *puVar4;
  uint uVar5;
  
  if (*(int *)(in_EAX + 0x370) == 0) {
    puVar4 = (undefined4 *)(in_EAX + 0x6c);
    for (iVar1 = 0xc1; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    iVar1 = *(int *)(in_EAX + 0x420);
    if ((iVar1 != -1) && (*(int *)(*(int *)(in_EAX + 0x404 + iVar1 * 4) + 0x28) != 0)) {
      iVar2 = 1;
      if (iVar1 + 1U < 7) {
        uVar5 = (iVar1 + 1U) * 4 + in_EAX;
        do {
          if (*(int *)(uVar5 + 0x404) != 0) {
            iVar2 = iVar2 + 1;
          }
          uVar5 = uVar5 + 4;
        } while (uVar5 < in_EAX + 0x1cU);
      }
      if (iVar2 == DAT_0040e83c) {
        iVar1 = in_EAX;
        do {
          puVar4 = *(undefined4 **)(iVar1 + 0x404);
          if (puVar4 != (undefined4 *)0x0) {
            (*DAT_00410470)(puVar4);
            puVar4[4] = 0;
            puVar4[10] = 0;
            puVar4[3] = *puVar4;
            puVar4[2] = *puVar4;
            iVar2 = puVar4[8];
            puVar4[8] = 0;
            puVar4[9] = puVar4[9] - iVar2;
          }
          iVar1 = iVar1 + 4;
        } while (iVar1 != in_EAX + 0x1c);
      }
    }
  }
  iVar1 = 0;
  uVar5 = 0;
  if (*(int *)(in_EAX + 0x370) != 0) {
    piVar3 = *(int **)(in_EAX + 0x3b8);
    do {
      uVar5 = uVar5 + 1;
      iVar2 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar1 = iVar1 + iVar2;
    } while (uVar5 < *(uint *)(in_EAX + 0x370));
  }
  if ((*(byte *)(in_EAX + 0x385) & 2) == 0) {
    uVar5 = *(uint *)(in_EAX + 0x444);
    lDistanceToMove = iVar1 + *(int *)(in_EAX + 0x3a8);
    if ((lDistanceToMove < uVar5) || (uVar5 + *(int *)(in_EAX + 0x43c) < lDistanceToMove)) {
      iVar1 = *(int *)(in_EAX + 0x42c);
      *(undefined4 *)(in_EAX + 0x43c) = 0;
      *(int *)(in_EAX + 0x438) = iVar1;
      *(int *)(in_EAX + 0x434) = iVar1;
      *(int *)(in_EAX + 0x430) = iVar1 + *(int *)(in_EAX + 0x440);
      SetFilePointer(*(HANDLE *)(in_EAX + 0x394),lDistanceToMove,(PLONG)0x0,0);
      uVar5 = extraout_ECX;
      if ((lDistanceToMove & 0xfff) != 0) {
        *(undefined4 *)(in_EAX + 0x42c) = 0;
        uVar5 = FUN_004059b0(extraout_ECX,*(undefined4 **)(in_EAX + 0x434));
        *(uint *)(in_EAX + 0x43c) = uVar5;
        *(uint *)(in_EAX + 0x438) = *(int *)(in_EAX + 0x438) + uVar5;
        *(undefined4 *)(in_EAX + 0x42c) = *(undefined4 *)(in_EAX + 0x434);
        uVar5 = extraout_ECX_00;
      }
    }
    else {
      *(uint *)(in_EAX + 0x43c) = *(int *)(in_EAX + 0x43c) - (lDistanceToMove - uVar5);
      uVar5 = *(int *)(in_EAX + 0x434) + (lDistanceToMove - uVar5);
      *(uint *)(in_EAX + 0x434) = uVar5;
      if (*(uint *)(in_EAX + 0x430) <= uVar5) {
        *(uint *)(in_EAX + 0x434) = *(int *)(in_EAX + 0x42c) + (uVar5 - *(uint *)(in_EAX + 0x430));
        *(int *)(in_EAX + 0x430) = *(int *)(in_EAX + 0x42c) + *(int *)(in_EAX + 0x440);
      }
    }
    *(uint *)(in_EAX + 0x444) = lDistanceToMove;
    if ((*(byte *)(in_EAX + 0x385) & 2) != 0) {
      return (ulonglong)param_2 << 0x20;
    }
    *(undefined4 *)(in_EAX + 0x3b0) = *(undefined4 *)(in_EAX + 0x3ac);
    uVar5 = FUN_004059b0(uVar5,*(undefined4 **)(in_EAX + 0x3ac));
  }
  else {
    *(int *)(in_EAX + 0x3b0) = *(int *)(in_EAX + 0x3ac) + iVar1;
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}


/*
 * FUN_004059b0 at 004059b0
 * uint __fastcall FUN_004059b0(undefined4 param_1, undefined4 * param_2)
 * Address ranges: 004059b0-00405c55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_004059b0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  uint uVar3;
  uint unaff_EBX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  DWORD local_28;
  uint local_24;
  DWORD local_20;
  uint local_1c;
  undefined4 *local_18;
  
  local_1c = 0;
  local_28 = 0;
  local_18 = param_2;
  local_20 = timeGetTime();
  if (*(int *)(in_EAX + 0x42c) == 0) {
    ReadFile(*(HANDLE *)(in_EAX + 0x394),local_18,unaff_EBX,&local_28,(LPOVERLAPPED)0x0);
    local_1c = local_28;
LAB_00405bef:
    *(DWORD *)(in_EAX + 0x448) = *(int *)(in_EAX + 0x448) + local_28;
    if (*(uint *)(in_EAX + 0x4a0) == 0) {
      DVar2 = timeGetTime();
    }
    else {
      local_28 = local_20 +
                 (int)(((ulonglong)local_28 * 1000) / (ulonglong)*(uint *)(in_EAX + 0x4a0));
      do {
        DVar2 = timeGetTime();
      } while (DVar2 < local_28);
    }
    *(DWORD *)(in_EAX + 0x44c) = *(int *)(in_EAX + 0x44c) + (DVar2 - local_20);
    return local_1c;
  }
LAB_00405a05:
  iVar1 = DAT_0040e83c;
  if (*(int *)(in_EAX + 0x43c) != 0) goto code_r0x00405a12;
  goto LAB_00405af9;
code_r0x00405a12:
  local_24 = *(int *)(in_EAX + 0x430) - *(int *)(in_EAX + 0x434);
  if (unaff_EBX < local_24) {
    local_24 = unaff_EBX;
  }
  if (*(uint *)(in_EAX + 0x43c) < local_24) {
    local_24 = *(uint *)(in_EAX + 0x43c);
  }
  puVar4 = *(undefined4 **)(in_EAX + 0x434);
  puVar5 = local_18;
  for (uVar3 = local_24 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar3 = local_24 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  *(int *)(in_EAX + 0x43c) = *(int *)(in_EAX + 0x43c) - local_24;
  *(uint *)(in_EAX + 0x444) = *(int *)(in_EAX + 0x444) + local_24;
  uVar3 = *(int *)(in_EAX + 0x434) + local_24;
  *(uint *)(in_EAX + 0x434) = uVar3;
  if (*(uint *)(in_EAX + 0x430) <= uVar3) {
    *(int *)(in_EAX + 0x434) = *(int *)(in_EAX + 0x42c);
    *(int *)(in_EAX + 0x430) = *(int *)(in_EAX + 0x42c) + *(int *)(in_EAX + 0x440);
    if (*(int *)(in_EAX + 0x43c) == 0) {
      *(undefined4 *)(in_EAX + 0x438) = *(undefined4 *)(in_EAX + 0x434);
    }
  }
  local_1c = local_1c + local_24;
  unaff_EBX = unaff_EBX - local_24;
  local_18 = (undefined4 *)((int)local_18 + local_24);
  iVar1 = DAT_0040e83c;
  if (unaff_EBX == 0) {
LAB_00405af9:
    while( true ) {
      if (iVar1 != 0) {
        (*DAT_00410474)();
      }
      uVar3 = local_1c;
      if (unaff_EBX < 0x1001) break;
      if (unaff_EBX < 0x4001) {
        local_24 = unaff_EBX & 0xfffff000;
      }
      else {
        local_24 = 0x4000;
      }
      ReadFile(*(HANDLE *)(in_EAX + 0x394),local_18,local_24,&local_24,(LPOVERLAPPED)0x0);
      iVar1 = DAT_0040e83c;
      unaff_EBX = unaff_EBX - local_24;
      local_18 = (undefined4 *)((int)local_18 + local_24);
      local_1c = uVar3 + local_24;
      local_28 = local_28 + local_24;
      *(uint *)(in_EAX + 0x444) = *(int *)(in_EAX + 0x444) + local_24;
    }
    if (unaff_EBX != 0) {
      local_24 = unaff_EBX + 0xfff & 0xfffff000;
      ReadFile(*(HANDLE *)(in_EAX + 0x394),*(LPVOID *)(in_EAX + 0x42c),local_24,&local_24,
               (LPOVERLAPPED)0x0);
      local_28 = local_28 + local_24;
      *(int *)(in_EAX + 0x434) = *(int *)(in_EAX + 0x42c);
      *(uint *)(in_EAX + 0x438) = local_24 + *(int *)(in_EAX + 0x42c);
      *(uint *)(in_EAX + 0x43c) = local_24;
      goto LAB_00405a05;
    }
    goto LAB_00405bef;
  }
  goto LAB_00405a05;
}


/*
 * FUN_00405c60 at 00405c60
 * undefined8 __fastcall FUN_00405c60(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00405c60-00405d62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00405c60(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  int in_EAX;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  DWORD local_1c;
  
  local_1c = 0;
  if ((*(uint *)(in_EAX + 0x370) < *(uint *)(in_EAX + 0xc)) &&
     (0xfff < *(int *)(in_EAX + 0x440) - *(int *)(in_EAX + 0x43c))) {
    DVar2 = timeGetTime();
    ReadFile(*(HANDLE *)(in_EAX + 0x394),*(LPVOID *)(in_EAX + 0x438),0x1000,&local_1c,
             (LPOVERLAPPED)0x0);
    *(int *)(in_EAX + 0x43c) = *(int *)(in_EAX + 0x43c) + local_1c;
    uVar4 = *(int *)(in_EAX + 0x438) + local_1c;
    *(uint *)(in_EAX + 0x438) = uVar4;
    if (*(uint *)(in_EAX + 0x430) < uVar4) {
      *(uint *)(in_EAX + 0x430) = uVar4;
      *(undefined4 *)(in_EAX + 0x438) = *(undefined4 *)(in_EAX + 0x42c);
    }
    if (*(uint *)(in_EAX + 0x458) < *(uint *)(in_EAX + 0x43c)) {
      *(uint *)(in_EAX + 0x458) = *(uint *)(in_EAX + 0x43c);
    }
    uVar4 = *(uint *)(in_EAX + 0x4a0);
    *(DWORD *)(in_EAX + 0x450) = *(int *)(in_EAX + 0x450) + local_1c;
    if (uVar4 == 0) {
      DVar3 = timeGetTime();
    }
    else {
      uVar1 = (ulonglong)local_1c;
      do {
        DVar3 = timeGetTime();
      } while (DVar3 < DVar2 + (int)((uVar1 * 1000) / (ulonglong)uVar4));
    }
    *(DWORD *)(in_EAX + 0x454) = *(int *)(in_EAX + 0x454) + (DVar3 - DVar2);
  }
  return CONCAT44(param_2,local_1c);
}


/*
 * FUN_00405d70 at 00405d70
 * undefined __fastcall FUN_00405d70(undefined4 param_1, int param_2)
 * Address ranges: 00405d70-00405d98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00405d70(undefined4 param_1,int param_2)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  
  uVar2 = *(int *)(in_EAX + 0x45c) + param_2;
  uVar1 = *(uint *)(in_EAX + 0x49c);
  *(uint *)(in_EAX + 0x45c) = uVar2;
  if (uVar1 < uVar2) {
    *(uint *)(in_EAX + 0x49c) = uVar2;
  }
  FUN_00402c30(uVar1,param_2,param_2);
  return;
}


/*
 * FUN_00405da0 at 00405da0
 * undefined __stdcall FUN_00405da0(void)
 * Address ranges: 00405da0-00405dbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00405da0(void)

{
  if ((HMODULE)0x1f < DAT_0040e85c) {
    FreeLibrary(DAT_0040e85c);
    DAT_0040e85c = (HMODULE)0x0;
  }
  return;
}


/*
 * _SmackSoundUseMSS@4 at 00405dc0
 * undefined4 __stdcall _SmackSoundUseMSS@4(int param_1)
 * Address ranges: 00405dc0-00406043
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _SmackSoundUseMSS_4(int param_1)

{
  undefined3 uVar1;
  FARPROC pFVar2;
  UINT uMode;
  uint uVar3;
  
                    /* 0x5dc0  33  _SmackSoundUseMSS@4 */
  if (DAT_0040e84c != (code *)0x0) {
LAB_0040603b:
    return param_1 & 0xffffff00;
  }
  DAT_004104ac = param_1;
  uVar1 = 0;
  if (param_1 != 0) {
    if (DAT_0040e85c == (HMODULE)0x0) {
      uMode = SetErrorMode(0x8000);
      DAT_0040e85c = LoadLibraryA(s_WAIL32_DLL_0040e11c);
      param_1 = SetErrorMode(uMode);
    }
    if (DAT_0040e85c < (HMODULE)0x20) {
      DAT_0040e85c = (HMODULE)0x1;
      goto LAB_0040603b;
    }
    DAT_0041048c = GetProcAddress(DAT_0040e85c,s__AIL_minimum_sample_buffer_size__0040e128);
    DAT_004104a8 = GetProcAddress(DAT_0040e85c,s__AIL_allocate_sample_handle_4_0040e14c);
    DAT_004104b0 = GetProcAddress(DAT_0040e85c,s__AIL_init_sample_4_0040e16c);
    DAT_00410494 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_type_12_0040e180);
    DAT_00410484 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_playback_rate_8_0040e198);
    DAT_00410490 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_user_data_12_0040e1b8);
    DAT_00410488 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_volume_8_0040e1d8);
    DAT_004104c4 = GetProcAddress(DAT_0040e85c,s__AIL_set_sample_pan_8_0040e1f4);
    DAT_004104c0 = GetProcAddress(DAT_0040e85c,s__AIL_serve_0_0040e20c);
    DAT_004104b4 = GetProcAddress(DAT_0040e85c,s__AIL_sample_buffer_ready_4_0040e21c);
    DAT_004104b8 = GetProcAddress(DAT_0040e85c,s__AIL_load_sample_buffer_16_0040e238);
    DAT_004104a4 = GetProcAddress(DAT_0040e85c,s__AIL_end_sample_4_0040e254);
    DAT_004104bc = GetProcAddress(DAT_0040e85c,s__AIL_release_sample_handle_4_0040e268);
    _DAT_0041049c = GetProcAddress(DAT_0040e85c,s__AIL_sample_status_4_0040e288);
    DAT_004104a0 = GetProcAddress(DAT_0040e85c,s__AIL_sample_buffer_info_20_0040e2a0);
    DAT_00410498 = GetProcAddress(DAT_0040e85c,s__MEM_alloc_lock_4_0040e2bc);
    DAT_00410480 = GetProcAddress(DAT_0040e85c,s__MEM_free_lock_4_0040e2d0);
    DAT_00410478 = &DAT_004062f0;
    DAT_0040e854 = 0;
    uVar1 = 0x4063;
    DAT_0041047c = FUN_004060c0;
    DAT_00410470 = FUN_00406140;
    DAT_0040e850 = FUN_00406140;
    DAT_0040e858 = FUN_00406050;
    DAT_00410474 = FUN_00406330;
  }
  pFVar2 = DAT_004104a0;
  DAT_0040e84c = FUN_00406170;
  if (DAT_004104a0 == (FARPROC)0x0) {
    uVar3 = FreeLibrary(DAT_0040e85c);
    DAT_0040e85c = (HMODULE)pFVar2;
    return uVar3 & 0xffffff00;
  }
  return CONCAT31(uVar1,1);
}


/*
 * FUN_00406050 at 00406050
 * undefined FUN_00406050(void)
 * Address ranges: 00406050-004060b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406050(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (0x8000 < param_2) {
    param_2 = 0x8000;
  }
  uVar1 = ((int)(((ulonglong)param_2 * 0x4f6) / 0x8000) + 5U) / 10;
  (*DAT_00410488)(*(undefined4 *)(param_3 + 0x38),uVar1);
  (*DAT_004104c4)(*(undefined4 *)(param_1 + 0x38),
                  ((int)(((ulonglong)uVar1 * 0x4f6) / 0x10000) + 5U) / 10);
  return;
}


/*
 * FUN_004060c0 at 004060c0
 * undefined FUN_004060c0(void)
 * Address ranges: 004060c0-0040613a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004060c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0040e860 != 0) {
    (*DAT_004104a4)(*(undefined4 *)(param_1 + 0x38));
    (*DAT_004104c0)();
    (*DAT_004104bc)(*(undefined4 *)(param_1 + 0x38));
    (*DAT_004104c0)();
    (*DAT_00410480)(*(undefined4 *)(param_1 + 0x54));
    (*DAT_00410480)(*(undefined4 *)(param_1 + 0x58));
    if (param_1 == DAT_0040e860) {
      DAT_0040e860 = *(int *)(DAT_0040e860 + 0x34);
    }
    else {
      iVar1 = *(int *)(DAT_0040e860 + 0x34);
      iVar2 = DAT_0040e860;
      while (iVar1 != 0) {
        if (param_1 == *(int *)(iVar2 + 0x34)) {
          *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x34);
          return;
        }
        iVar2 = *(int *)(iVar2 + 0x34);
        iVar1 = *(int *)(iVar2 + 0x34);
      }
    }
  }
  return;
}


/*
 * FUN_00406140 at 00406140
 * undefined FUN_00406140(void)
 * Address ranges: 00406140-0040616c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406140(int param_1)

{
  (*DAT_004104a4)(*(undefined4 *)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  FUN_00406270();
  return;
}


/*
 * FUN_00406170 at 00406170
 * undefined FUN_00406170(void)
 * Address ranges: 00406170-0040626e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00406170(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_004104ac == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_2 + 0x48) == 0) {
      if (*(int *)(param_2 + 0x4c) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 2;
      }
    }
    else if (*(int *)(param_2 + 0x4c) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 3;
    }
    iVar2 = (*DAT_0041048c)(DAT_004104ac,*(undefined4 *)(param_2 + 0x40),uVar1);
    *(uint *)(param_2 + 100) = iVar2 + 3U & 0xfffffffc;
    *(uint *)(param_2 + 0x3c) = ((*(uint *)(param_2 + 0x14) >> 2) + 0xfff >> 8 & 0xfffff0) << 8;
    if (*(uint *)(param_2 + 0x3c) < *(uint *)(param_2 + 100)) {
      *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 100);
    }
    iVar2 = (*DAT_00410498)(*(undefined4 *)(param_2 + 0x3c));
    *(int *)(param_2 + 0x54) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (*DAT_00410498)(*(undefined4 *)(param_2 + 0x3c));
    *(int *)(param_2 + 0x58) = iVar2;
    if (iVar2 == 0) {
      (*DAT_00410480)(*(undefined4 *)(param_2 + 0x54));
      return 0;
    }
    iVar2 = (*DAT_004104a8)(DAT_004104ac);
    *(int *)(param_2 + 0x38) = iVar2;
    if (iVar2 == 0) {
      (*DAT_00410480)(*(undefined4 *)(param_2 + 0x54));
      (*DAT_00410480)(*(undefined4 *)(param_2 + 0x58));
      return 0;
    }
    FUN_00406270();
    iVar2 = DAT_0040e860;
    DAT_0040e860 = param_2;
    *(int *)(param_2 + 0x34) = iVar2;
    uVar1 = 1;
  }
  return uVar1;
}


/*
 * FUN_00406270 at 00406270
 * undefined __stdcall FUN_00406270(void)
 * Address ranges: 00406270-004062ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406270(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  (*DAT_004104b0)(*(undefined4 *)(in_EAX + 0x38));
  if (*(int *)(in_EAX + 0x48) == 0) {
    if (*(int *)(in_EAX + 0x4c) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else if (*(int *)(in_EAX + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 3;
  }
  (*DAT_00410494)(*(undefined4 *)(in_EAX + 0x38),uVar1,*(int *)(in_EAX + 0x48) != 0);
  (*DAT_00410484)(*(undefined4 *)(in_EAX + 0x38),*(undefined4 *)(in_EAX + 0x40));
  (*DAT_00410490)(*(undefined4 *)(in_EAX + 0x38),0);
  (*DAT_00410488)(*(undefined4 *)(in_EAX + 0x38),0x7f);
  return;
}


/*
 * FUN_00406330 at 00406330
 * undefined FUN_00406330(void)
 * Address ranges: 00406330-0040641f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406330(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  for (puVar1 = DAT_0040e860; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[0xd]) {
    if ((((uint)puVar1[0x19] < (uint)puVar1[4]) || ((puVar1[0x11] != 0 && (3 < (uint)puVar1[4]))))
       && (uVar2 = (*DAT_004104b4)(puVar1[0xe]), uVar2 < 2)) {
      uVar6 = puVar1[4] & 0xfffffffc;
      if ((uint)puVar1[0xf] < uVar6) {
        uVar6 = puVar1[0xf] & 0xfffffffc;
      }
      if ((puVar1[0x1b] == 0) || (iVar3 = (*DAT_004104a0)(puVar1[0xe],0,0,0,0), iVar3 != 0)) {
        DVar4 = timeGetTime();
        puVar1[0x1b] = DVar4;
        iVar3 = puVar1[0x1a];
        puVar1[0x1a] = 0;
        puVar1[0x14] = puVar1[0x14] + iVar3;
      }
      puVar5 = FUN_00402c70(uVar6,puVar1[1],(undefined4 *)*puVar1,(undefined4 *)puVar1[2],
                            (undefined4 *)puVar1[uVar2 + 0x15]);
      puVar1[2] = puVar5;
      (*DAT_004104b8)(puVar1[0xe],uVar2,puVar1[uVar2 + 0x15],uVar6);
      puVar1[0x1a] = puVar1[0x1a] + uVar6;
      puVar1[4] = puVar1[4] - uVar6;
    }
  }
  (*DAT_004104c0)();
  return;
}


/*
 * FUN_00406420 at 00406420
 * undefined8 __fastcall FUN_00406420(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00406420-0040650e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00406420(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint in_EAX;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  uint uVar6;
  undefined8 uVar7;
  
  if ((in_EAX != 0) && (in_EAX < 0xffffffd5)) {
    bVar1 = false;
    uVar6 = in_EAX + 3 & 0xfffffffc;
    (*(code *)PTR_FUN_0040ef60)();
    uVar2 = extraout_EDX;
LAB_00406459:
    do {
      uVar3 = uVar6;
      if (uVar6 < 0xc) {
        uVar3 = 0xc;
      }
      if ((uVar3 <= DAT_0040e86c) || (iVar5 = DAT_0040e868, DAT_0040e868 == 0)) {
        DAT_0040e86c = 0;
        iVar5 = DAT_0040e864;
      }
      while (iVar5 != 0) {
        DAT_0040e868 = iVar5;
        puVar4 = FUN_00407a1e();
        if (puVar4 != (uint *)0x0) goto LAB_004064f0;
        if (DAT_0040e86c < *(uint *)(extraout_ECX + 0x14)) {
          DAT_0040e86c = *(uint *)(extraout_ECX + 0x14);
        }
        uVar2 = 0;
        iVar5 = *(int *)(extraout_ECX + 8);
      }
      if (!bVar1) {
        uVar7 = FUN_00407cd5(0,uVar2);
        uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if ((int)uVar7 != 0) {
          bVar1 = true;
          goto LAB_00406459;
        }
      }
      iVar5 = FUN_00407d30();
      if (iVar5 == 0) goto LAB_004064f0;
      bVar1 = false;
      uVar2 = extraout_EDX_00;
    } while( true );
  }
  uVar2 = 0;
LAB_00406500:
  return CONCAT44(param_2,uVar2);
LAB_004064f0:
  DAT_004104e8 = 0;
  (*(code *)PTR_FUN_0040ef68)();
  uVar2 = extraout_EDX_01;
  goto LAB_00406500;
}


/*
 * FUN_0040650f at 0040650f
 * undefined __stdcall FUN_0040650f(void)
 * Address ranges: 0040650f-0040659c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040650f(void)

{
  uint in_EAX;
  uint uVar1;
  uint extraout_ECX;
  
  if (in_EAX != 0) {
    (*(code *)PTR_FUN_0040ef60)();
    uVar1 = DAT_0040e864;
    if (((DAT_004104c8 == 0) || (in_EAX < DAT_004104c8)) || (*(uint *)(DAT_004104c8 + 8) <= in_EAX))
    {
      for (; (*(uint *)(uVar1 + 8) != 0 && ((in_EAX < uVar1 || (*(uint *)(uVar1 + 8) <= in_EAX))));
          uVar1 = *(uint *)(uVar1 + 8)) {
      }
    }
    FUN_00407ac6();
    if ((extraout_ECX < DAT_0040e868) && (DAT_0040e86c < *(uint *)(extraout_ECX + 0x14))) {
      DAT_0040e86c = *(uint *)(extraout_ECX + 0x14);
    }
    DAT_004104e8 = 0;
    DAT_004104c8 = extraout_ECX;
    (*(code *)PTR_FUN_0040ef68)();
  }
  return;
}


/*
 * FUN_004065a0 at 004065a0
 * undefined __cdecl FUN_004065a0(int param_1, int param_2, int param_3, int param_4, uint param_5, int param_6, int param_7, int param_8)
 * Address ranges: 004065a0-004065de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl
FUN_004065a0(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,int param_7,
            int param_8)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + param_7);
  puVar2 = (undefined4 *)(param_3 + param_8);
  do {
    uVar1 = param_5 >> 2;
    if (uVar1 != 0) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    for (uVar1 = param_5 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    puVar3 = (undefined4 *)((int)puVar3 + param_2);
    puVar2 = (undefined4 *)((int)puVar2 + param_4);
    param_6 = param_6 + -1;
  } while (param_6 != 0);
  return;
}


/*
 * FUN_004065df at 004065df
 * undefined8 __fastcall FUN_004065df(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, char param_11)
 * Address ranges: 004065df-0040661c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall
FUN_004065df(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10,char param_11)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(param_3 + param_9);
  pcVar3 = (char *)(param_5 + param_10);
  iVar2 = param_7;
  do {
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      if (cVar1 != param_11) {
        *pcVar4 = cVar1;
      }
      pcVar4 = pcVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    pcVar4 = pcVar4 + param_4;
    pcVar3 = pcVar3 + param_6;
    param_8 = param_8 + -1;
    iVar2 = param_7;
  } while (param_8 != 0);
  return CONCAT44(param_2,in_EAX);
}


/*
 * FUN_0040661d at 0040661d
 * undefined __cdecl FUN_0040661d(byte * param_1, int param_2, int param_3)
 * Address ranges: 0040661d-0040663f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040661d(byte *param_1,int param_2,int param_3)

{
  do {
    *param_1 = *(byte *)(param_3 + (uint)*param_1);
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}


/*
 * _SmackSoundUseDirectSound@4 at 00406640
 * undefined1 * __stdcall _SmackSoundUseDirectSound@4(uint param_1)
 * Address ranges: 00406640-0040670a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 * _SmackSoundUseDirectSound_4(uint param_1)

{
  UINT uMode;
  uint uVar1;
  
                    /* 0x6640  36  _SmackSoundUseDirectSound@4 */
  DAT_0040e87c = param_1;
  uVar1 = param_1 & 0xffff0000;
  DAT_0040e880 = 0;
  if (DAT_0040e84c == (code *)0x0) {
    uMode = SetErrorMode(0x8000);
    DAT_0040e888 = LoadLibraryA(s_DSOUND_DLL_0040e2e4);
    uVar1 = SetErrorMode(uMode);
    if ((HMODULE)0x1f < DAT_0040e888) {
      DAT_004104d0 = GetProcAddress(DAT_0040e888,s_DirectSoundCreate_0040e2f0);
      DAT_0040e84c = FUN_004069b0;
      DAT_0040e850 = FUN_004067a0;
      DAT_0040e854 = FUN_00406790;
      DAT_0040e858 = FUN_00406710;
      DAT_00410470 = FUN_00406810;
      DAT_00410474 = &DAT_00406840;
      DAT_00410478 = FUN_00406960;
      DAT_0041047c = FUN_004067b0;
      return &LAB_00406901;
    }
  }
  return (undefined1 *)(uVar1 & 0xffffff00);
}


/*
 * FUN_00406710 at 00406710
 * undefined FUN_00406710(void)
 * Address ranges: 00406710-0040678f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406710(uint param_1,uint param_2,int param_3)

{
  if (0x8000 < param_2) {
    param_2 = 0x8000;
  }
  (**(code **)(**(int **)(*(int *)(param_3 + 0x38) + 4) + 0x40))
            (*(undefined4 *)(*(int *)(param_3 + 0x38) + 4),
             (int)(((ulonglong)param_1 * 20000) / 0x10000) + -10000);
  (**(code **)(**(int **)(*(int *)(param_3 + 0x38) + 4) + 0x3c))
            (*(undefined4 *)(*(int *)(param_3 + 0x38) + 4),
             ((int)(((ulonglong)param_2 * 100000) / 0x8000) + 5U) / 10 - 10000);
  return;
}


/*
 * FUN_00406790 at 00406790
 * undefined FUN_00406790(void)
 * Address ranges: 00406790-0040679b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


ulonglong __fastcall FUN_00406790(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  
  uVar1 = FUN_00406a20(param_1,param_2);
  return uVar1;
}


/*
 * FUN_004067a0 at 004067a0
 * undefined FUN_004067a0(void)
 * Address ranges: 004067a0-004067ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004067a0(undefined4 param_1)

{
  FUN_00406bc0(param_1);
  return;
}


/*
 * FUN_004067b0 at 004067b0
 * undefined FUN_004067b0(void)
 * Address ranges: 004067b0-0040680e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_004067b0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0040e890 != 0) {
    FUN_00406bc0(param_1);
    FUN_00402c10();
    if (param_2 == DAT_0040e890) {
      DAT_0040e890 = *(undefined4 *)(DAT_0040e890 + 0x34);
      return;
    }
    iVar1 = *(int *)(DAT_0040e890 + 0x34);
    iVar2 = DAT_0040e890;
    while (iVar1 != 0) {
      if (param_2 == *(int *)(iVar2 + 0x34)) {
        *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x34);
        return;
      }
      iVar2 = *(int *)(iVar2 + 0x34);
      iVar1 = *(int *)(iVar2 + 0x34);
    }
  }
  return;
}


/*
 * FUN_00406810 at 00406810
 * undefined FUN_00406810(void)
 * Address ranges: 00406810-00406837
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __thiscall FUN_00406810(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  
  if (*(int *)(param_2 + 0x38) != 0) {
    lVar2 = FUN_00406ce0(param_1,param_2);
    param_2 = (uint)((ulonglong)lVar2 >> 0x20);
  }
  *(undefined4 *)(param_2 + 100) = 0;
  uVar1 = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_2 + 0x60) = uVar1;
  *(undefined4 *)(param_2 + 0x5c) = uVar1;
  *(undefined4 *)(param_2 + 0x50) = uVar1;
  return;
}


/*
 * FUN_00406960 at 00406960
 * undefined FUN_00406960(void)
 * Address ranges: 00406960-004069a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00406960(int param_1)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
  (*DAT_00410474)();
  if (*(int *)(param_1 + 0x5c) == 0) {
    return 0;
  }
  DVar1 = timeGetTime();
  uVar3 = DVar1 - *(int *)(param_1 + 0x5c);
  if (uVar3 < *(uint *)(param_1 + 0x60)) {
    iVar2 = (int)(((ulonglong)*(uint *)(param_1 + 100) * (ulonglong)uVar3) /
                 (ulonglong)*(uint *)(param_1 + 0x60));
  }
  else {
    iVar2 = *(int *)(param_1 + 100);
  }
  return iVar2 + *(int *)(param_1 + 0x50);
}


/*
 * FUN_004069b0 at 004069b0
 * undefined FUN_004069b0(void)
 * Address ranges: 004069b0-00406a1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall
FUN_004069b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  ulonglong uVar4;
  
  uVar1 = (*(uint *)(param_4 + 0x14) >> 2) + 0xfff >> 8 & 0xfffff0;
  *(uint *)(param_4 + 0x3c) = uVar1 * 0x100;
  iVar3 = FUN_00402c30(param_1,param_2,uVar1 * 0x200 + 0x40);
  *(int *)(param_4 + 0x54) = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  *(int *)(param_4 + 0x58) = iVar3 + 0x20 + *(int *)(param_4 + 0x3c);
  *(undefined4 *)(param_4 + 0x68) = param_3;
  uVar4 = FUN_00406a20(extraout_ECX,*(int *)(param_4 + 0x3c));
  uVar2 = DAT_0040e890;
  if ((char)uVar4 == '\0') {
    FUN_00402c10();
    return 0;
  }
  DAT_0040e890 = param_4;
  *(undefined4 *)(param_4 + 0x34) = uVar2;
  return 1;
}


/*
 * FUN_00406a20 at 00406a20
 * ulonglong __fastcall FUN_00406a20(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00406a20-00406bbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


ulonglong __fastcall FUN_00406a20(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined1 uVar2;
  int in_EAX;
  uint uVar3;
  DWORD DVar4;
  DWORD DVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 extraout_ECX;
  undefined4 *puVar9;
  
  uVar3 = FUN_00406e30(0,0xffffffff,(byte)*(undefined4 *)(in_EAX + 0x68));
  if (uVar3 == 0) {
    puVar9 = *(undefined4 **)(in_EAX + 0x54);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar9 = *(undefined4 **)(in_EAX + 0x58);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    **(int **)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 0x20;
    **(int **)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) + 0x20;
    uVar6 = *(undefined4 *)(in_EAX + 0x3c);
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = uVar6;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 4) = uVar6;
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 0x10) = 1;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x10) = 1;
    pbVar1 = (byte *)(*(int *)(in_EAX + 0x58) + 0x10);
    *pbVar1 = *pbVar1 | 1;
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = 4;
    uVar3 = *(uint *)(in_EAX + 0x3c);
    if (*(int *)(in_EAX + 0x48) == 0) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = 0;
    }
    puVar9 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x20);
    for (uVar8 = uVar3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
      puVar9 = puVar9 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar9 = uVar2;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    FUN_00406d50(0,*(int *)(in_EAX + 0x54));
    DVar4 = timeGetTime();
    do {
      DVar5 = timeGetTime();
      if (DVar4 + 1000 <= DVar5) {
        pbVar1 = (byte *)(*(int *)(in_EAX + 0x54) + 0x10);
        *pbVar1 = *pbVar1 | 1;
        uVar6 = FUN_00406bc0(extraout_ECX);
        return CONCAT44(param_2,uVar6) & 0xffffffffffffff00;
      }
    } while ((*(byte *)(*(int *)(in_EAX + 0x54) + 0x10) & 1) == 0);
    uVar3 = CONCAT31((int3)((uint)*(int *)(in_EAX + 0x54) >> 8),1);
  }
  else {
    uVar3 = uVar3 & 0xffffff00;
  }
  return CONCAT44(param_2,uVar3);
}


/*
 * FUN_00406bc0 at 00406bc0
 * undefined __fastcall FUN_00406bc0(undefined4 param_1)
 * Address ranges: 00406bc0-00406c06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00406bc0(undefined4 param_1)

{
  uint in_EAX;
  undefined4 extraout_ECX;
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (*(int *)(in_EAX + 0x38) != 0) {
    lVar2 = FUN_00406ce0(param_1,in_EAX);
    iVar1 = (int)((ulonglong)lVar2 >> 0x20);
    do {
      do {
      } while ((*(byte *)(*(int *)(iVar1 + 0x54) + 0x10) & 1) == 0);
    } while ((*(byte *)(*(int *)(iVar1 + 0x58) + 0x10) & 1) == 0);
    *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10) = 1;
    *(undefined4 *)(*(int *)(iVar1 + 0x58) + 0x10) = 1;
    uVar3 = FUN_00406c30(extraout_ECX,iVar1);
    *(undefined4 *)((int)((ulonglong)uVar3 >> 0x20) + 0x38) = 0;
  }
  return;
}


/*
 * FUN_00406c10 at 00406c10
 * undefined __stdcall FUN_00406c10(void)
 * Address ranges: 00406c10-00406c2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00406c10(void)

{
  if ((HMODULE)0x1f < DAT_0040e888) {
    FreeLibrary(DAT_0040e888);
    DAT_0040e888 = (HMODULE)0x0;
  }
  return;
}


/*
 * FUN_00406c30 at 00406c30
 * undefined8 __fastcall FUN_00406c30(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00406c30-00406cdc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00406c30(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0040e874;
  if (DAT_0040e874 == in_EAX) {
    DAT_0040e874 = *(int *)(DAT_0040e874 + 8);
  }
  else {
    do {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar2 + 8);
      if (iVar1 == 0) {
        uVar3 = 1;
        goto LAB_00406cd7;
      }
    } while (in_EAX != iVar1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
  }
  if ((*(char *)(in_EAX + 0x28) != '\0') && (DAT_0040e878 = DAT_0040e878 + -1, DAT_0040e878 == 0)) {
    timeKillEvent(DAT_004104d8);
    timeEndPeriod(0x1f);
  }
  (**(code **)(**(int **)(in_EAX + 4) + 0x48))(*(int **)(in_EAX + 4));
  (**(code **)(**(int **)(in_EAX + 4) + 8))(*(int **)(in_EAX + 4));
  if ((DAT_0040e874 == 0) && (DAT_0040e880 != '\0')) {
    (**(code **)(*DAT_0040e87c + 8))(DAT_0040e87c);
    DAT_0040e87c = (int *)0x0;
  }
  FUN_00402c10();
  uVar3 = 0;
LAB_00406cd7:
  return CONCAT44(param_2,uVar3);
}


/*
 * FUN_00406ce0 at 00406ce0
 * longlong __fastcall FUN_00406ce0(undefined4 param_1, uint param_2)
 * Address ranges: 00406ce0-00406d42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall FUN_00406ce0(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *in_EAX;
  
  *(undefined1 *)((int)in_EAX + 0x29) = 0;
  if ((char)in_EAX[10] != '\0') {
    *(undefined1 *)(in_EAX + 10) = 0;
    (**(code **)(*(int *)in_EAX[1] + 0x48))((int *)in_EAX[1]);
    for (iVar1 = *in_EAX; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      *(byte *)(iVar1 + 0x10) = *(byte *)(iVar1 + 0x10) | 1;
    }
    *in_EAX = 0;
    DAT_0040e878 = DAT_0040e878 + -1;
    if (DAT_0040e878 == 0) {
      timeKillEvent(DAT_004104d8);
      timeEndPeriod(0x1f);
    }
  }
  return (ulonglong)param_2 << 0x20;
}


/*
 * FUN_00406d50 at 00406d50
 * undefined4 __fastcall FUN_00406d50(undefined4 param_1, int param_2)
 * Address ranges: 00406d50-00406e25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00406d50(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  uint uVar3;
  
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) & 0xfe;
  uVar3 = timeGetTime();
  *(int *)(param_2 + 8) =
       (int)(((ulonglong)*(uint *)(param_2 + 4) * 1000) / (ulonglong)(uint)in_EAX[9]);
  iVar1 = *in_EAX;
  if (iVar1 == 0) {
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + uVar3;
    *in_EAX = param_2;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x18);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar1 + 0x18);
      iVar2 = *(int *)(iVar1 + 0x18);
    }
    *(int *)(iVar1 + 0x18) = param_2;
    if (uVar3 < *(uint *)(iVar1 + 8)) {
      uVar3 = *(uint *)(iVar1 + 8);
    }
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + uVar3;
  }
  if ((char)in_EAX[10] == '\0') {
    (**(code **)(*(int *)in_EAX[1] + 0x30))((int *)in_EAX[1],0,0,1);
    DAT_0040e878 = DAT_0040e878 + 1;
    if (DAT_0040e878 == 1) {
      timeBeginPeriod(0x1f);
      DAT_004104d8 = timeSetEvent(0x1f,0,_TimerFunc_20,0,1);
    }
    *(undefined1 *)(in_EAX + 10) = 1;
  }
  return 0;
}


/*
 * FUN_00406e30 at 00406e30
 * undefined4 __fastcall FUN_00406e30(undefined4 param_1, undefined4 param_2, byte param_3)
 * Address ranges: 00406e30-00407012
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00406e30(undefined4 param_1,undefined4 param_2,byte param_3)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  HWND hWnd;
  DWORD DVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *unaff_EBX;
  uint uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint auStack_28 [2];
  DWORD aDStack_20 [2];
  
  if (DAT_0040e888 < 0x20) {
    return 1;
  }
  if (DAT_0040e87c == (int *)0x0) {
    iVar3 = (*DAT_004104d0)(0,&DAT_0040e87c,0);
    if (iVar3 != 0) {
      return 1;
    }
    hWnd = GetTopWindow((HWND)0x0);
    DVar4 = GetCurrentProcessId();
    while ((hWnd != (HWND)0x0 && (GetWindowThreadProcessId(hWnd,aDStack_20), DVar4 != aDStack_20[0])
           )) {
      hWnd = GetWindow(hWnd,2);
    }
    if (hWnd == (HWND)0x0) {
      hWnd = GetActiveWindow();
    }
    DAT_0040e880 = '\x01';
    (**(code **)(*DAT_0040e87c + 0x18))(DAT_0040e87c,hWnd,1);
    param_1 = extraout_ECX;
    param_2 = extraout_EDX;
  }
  puVar5 = (undefined4 *)FUN_00402c30(param_1,param_2,0x2c);
  if (puVar5 != (undefined4 *)0x0) {
    puVar8 = puVar5;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    puVar9 = auStack_28;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    auStack_28[0] = 0x14;
    if ((param_3 & 0x40) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0x80;
    }
    if ((param_3 & 0x20) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x40;
    }
    auStack_28[1] = uVar6 | uVar7 | 0x4000;
    uVar7 = (uint)unaff_EBX[2] >> 4 & 0xfffffffc;
    puVar5[3] = uVar7;
    aDStack_20[0] = uVar7 << 2;
    puVar5[4] = aDStack_20[0];
    iVar3 = (**(code **)(*DAT_0040e87c + 0xc))(DAT_0040e87c,auStack_28,puVar5 + 1,0);
    if (iVar3 == 0) {
      (**(code **)(*(int *)puVar5[1] + 0x3c))((int *)puVar5[1],0);
      if (*(short *)((int)unaff_EBX + 0xe) == 8) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = 0;
      }
      *(undefined1 *)((int)puVar5 + 0x2a) = uVar2;
      puVar5[9] = unaff_EBX[2];
      puVar5[2] = DAT_0040e874;
      DAT_0040e874 = puVar5;
      *unaff_EBX = puVar5;
      return 0;
    }
    FUN_00402c10();
  }
  piVar1 = DAT_0040e874;
  if ((DAT_0040e874 == (int *)0x0) && (DAT_0040e880 != '\0')) {
    (**(code **)(*DAT_0040e87c + 8))(DAT_0040e87c);
    DAT_0040e87c = piVar1;
  }
  return 1;
}


/*
 * _TimerFunc@20 at 00407020
 * undefined __stdcall _TimerFunc@20(void)
 * Address ranges: 00407020-00407125
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void _TimerFunc_20(void)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint uVar4;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 local_18 [4];
  uint local_14;
  
                    /* 0x7020  35  _TimerFunc@20 */
  DAT_0040e884 = DAT_0040e884 + 1;
  iVar1 = DAT_0040e874;
  if (DAT_0040e884 == 1) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (*(char *)(iVar1 + 0x28) != '\0') {
        (**(code **)(**(int **)(iVar1 + 4) + 0x10))(*(int **)(iVar1 + 4),&local_14,local_18);
        if (((local_14 <= *(uint *)(iVar1 + 0x14)) ||
            (*(uint *)(iVar1 + 0x14) + *(int *)(iVar1 + 0xc) <= local_14)) &&
           (iVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x2c))
                              (*(int **)(iVar1 + 4),*(undefined4 *)(iVar1 + 0x14),
                               *(undefined4 *)(iVar1 + 0xc),&iStack_1c,&uStack_24,&iStack_20,
                               &uStack_28,0), iVar2 == 0)) {
          *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0xc);
          uVar3 = extraout_ECX;
          if (iStack_1c != 0) {
            FUN_00407130(extraout_ECX,uStack_24);
            uVar3 = extraout_ECX_00;
          }
          if (iStack_20 != 0) {
            FUN_00407130(uVar3,uStack_28);
          }
          uVar4 = *(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0xc);
          *(uint *)(iVar1 + 0x14) = uVar4;
          if (*(uint *)(iVar1 + 0x10) <= uVar4) {
            *(uint *)(iVar1 + 0x14) = uVar4 - *(uint *)(iVar1 + 0x10);
          }
          (**(code **)(**(int **)(iVar1 + 4) + 0x4c))
                    (*(int **)(iVar1 + 4),iStack_1c,uStack_24,iStack_20,uStack_28);
        }
      }
    }
  }
  DAT_0040e884 = DAT_0040e884 + -1;
  return;
}


/*
 * FUN_00407130 at 00407130
 * undefined __fastcall FUN_00407130(undefined4 param_1, uint param_2)
 * Address ranges: 00407130-0040721a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00407130(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  int *dwUser;
  int iVar2;
  undefined4 *in_EAX;
  DWORD DVar3;
  uint uVar4;
  uint uVar5;
  DWORD_PTR *unaff_EBX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_18;
  uint local_14;
  
  local_18 = in_EAX;
  local_14 = param_2;
  do {
    dwUser = (int *)*unaff_EBX;
    if (dwUser == (int *)0x0) break;
    uVar5 = dwUser[1] - dwUser[7];
    if (local_14 < (uint)(dwUser[1] - dwUser[7])) {
      uVar5 = local_14;
    }
    puVar6 = (undefined4 *)(*dwUser + dwUser[7]);
    puVar7 = local_18;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    iVar2 = dwUser[7];
    local_18 = (undefined4 *)((int)local_18 + uVar5);
    local_14 = local_14 - uVar5;
    dwUser[7] = iVar2 + uVar5;
    if (iVar2 + uVar5 < (uint)dwUser[1]) break;
    *unaff_EBX = dwUser[6];
    DVar3 = timeGetTime();
    if ((int)(dwUser[2] - DVar3) < 1) {
      *(byte *)(dwUser + 4) = *(byte *)(dwUser + 4) | 1;
    }
    else {
      timeSetEvent(dwUser[2] - DVar3,0,donemarker,(DWORD_PTR)dwUser,0);
    }
  } while (local_14 != 0);
  if (local_14 != 0) {
    uVar1 = *(undefined1 *)((int)unaff_EBX + 0x2a);
    for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *local_18 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
      local_18 = local_18 + 1;
    }
    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)local_18 = uVar1;
      local_18 = (undefined4 *)((int)local_18 + 1);
    }
    unaff_EBX[7] = unaff_EBX[7] + local_14;
  }
  return;
}


/*
 * donemarker at 00407220
 * undefined __stdcall donemarker(UINT param_1, undefined4 param_2, int param_3)
 * Address ranges: 00407220-00407236
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: __stdcall donemarker,20
 */


/* __stdcall donemarker,20 */

void donemarker(UINT param_1,undefined4 param_2,int param_3)

{
                    /* 0x7220  34  _donemarker@20 */
  *(byte *)(param_3 + 0x10) = *(byte *)(param_3 + 0x10) | 1;
  timeKillEvent(param_1);
  return;
}


/*
 * _SmackSoundUseWin@0 at 00407240
 * undefined1 * __stdcall _SmackSoundUseWin@0(void)
 * Address ranges: 00407240-004072b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 * _SmackSoundUseWin_0(void)

{
  uint in_EAX;
  
                    /* 0x7240  37  _SmackSoundUseWin@0 */
  if (DAT_0040e84c == (code *)0x0) {
    DAT_00410474 = FUN_00407400;
    DAT_0040e84c = FUN_00407570;
    DAT_0041047c = FUN_00407370;
    DAT_00410478 = FUN_00407520;
    DAT_00410470 = FUN_004073d0;
    DAT_0040e850 = FUN_00407360;
    DAT_0040e854 = FUN_00407350;
    DAT_0040e858 = &DAT_004072c0;
    return &LAB_00407301;
  }
  return (undefined1 *)(in_EAX & 0xffffff00);
}


/*
 * FUN_00407350 at 00407350
 * undefined FUN_00407350(void)
 * Address ranges: 00407350-0040735b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


ulonglong __fastcall FUN_00407350(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  
  uVar1 = FUN_004075e0(param_1,param_2);
  return uVar1;
}


/*
 * FUN_00407360 at 00407360
 * undefined FUN_00407360(void)
 * Address ranges: 00407360-0040736b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00407360(void)

{
  FUN_004077a0();
  return;
}


/*
 * FUN_00407370 at 00407370
 * undefined FUN_00407370(void)
 * Address ranges: 00407370-004073ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00407370(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0040e894 != 0) {
    FUN_004077a0();
    FUN_00402c10();
    if (param_1 == DAT_0040e894) {
      DAT_0040e894 = *(undefined4 *)(DAT_0040e894 + 0x34);
      return;
    }
    iVar1 = *(int *)(DAT_0040e894 + 0x34);
    iVar2 = DAT_0040e894;
    while (iVar1 != 0) {
      if (param_1 == *(int *)(iVar2 + 0x34)) {
        *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x34);
        return;
      }
      iVar2 = *(int *)(iVar2 + 0x34);
      iVar1 = *(int *)(iVar2 + 0x34);
    }
  }
  return;
}


/*
 * FUN_004073d0 at 004073d0
 * undefined FUN_004073d0(void)
 * Address ranges: 004073d0-004073f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004073d0(int param_1)

{
  undefined4 uVar1;
  
  if (*(HWAVEOUT *)(param_1 + 0x38) != (HWAVEOUT)0x0) {
    waveOutReset(*(HWAVEOUT *)(param_1 + 0x38));
  }
  *(undefined4 *)(param_1 + 100) = 0;
  uVar1 = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  return;
}


/*
 * FUN_00407400 at 00407400
 * undefined FUN_00407400(void)
 * Address ranges: 00407400-00407512
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00407400(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  uint uVar6;
  uint uVar7;
  LPWAVEHDR pwh;
  
  for (puVar2 = DAT_0040e894; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[0xd]) {
    if ((3 < (uint)puVar2[4]) &&
       ((pwh = (LPWAVEHDR)puVar2[0x15], (pwh->dwFlags & 1) != 0 ||
        (pwh = (LPWAVEHDR)puVar2[0x16], (pwh->dwFlags & 1) != 0)))) {
      uVar7 = puVar2[4];
      if ((uint)puVar2[0xf] < (uint)puVar2[4]) {
        uVar7 = puVar2[0xf];
      }
      puVar4 = FUN_00402c70(uVar7,puVar2[1],(undefined4 *)*puVar2,(undefined4 *)puVar2[2],
                            &pwh[1].lpData);
      puVar2[2] = puVar4;
      puVar2[4] = puVar2[4] - uVar7;
      pwh->dwBufferLength = uVar7;
      *(byte *)&pwh->dwFlags = (byte)pwh->dwFlags & 0xfe;
      iVar1 = puVar2[0xf];
      if (puVar2[0x12] == 0) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = 0;
      }
      puVar4 = (undefined4 *)((int)&pwh[1].lpData + uVar7);
      for (uVar6 = iVar1 - uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar4 = CONCAT22(CONCAT11(uVar3,uVar3),CONCAT11(uVar3,uVar3));
        puVar4 = puVar4 + 1;
      }
      for (uVar6 = iVar1 - uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar4 = uVar3;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      waveOutWrite((HWAVEOUT)puVar2[0xe],pwh,0x20);
      if (puVar2[0x17] == 0) {
        DVar5 = timeGetTime();
        puVar2[0x17] = DVar5;
        puVar2[0x19] = uVar7;
      }
      else {
        DVar5 = timeGetTime();
        if ((uint)(puVar2[0x17] + puVar2[0x18]) < DVar5) {
          puVar2[0x17] = DVar5;
          iVar1 = puVar2[0x19];
          puVar2[0x19] = uVar7;
          puVar2[0x14] = puVar2[0x14] + iVar1;
        }
        else {
          puVar2[0x19] = puVar2[0x19] + uVar7;
        }
      }
      puVar2[0x18] = (int)(((ulonglong)(uint)puVar2[0x19] * 1000) / (ulonglong)(uint)puVar2[5]);
    }
  }
  return;
}


/*
 * FUN_00407520 at 00407520
 * undefined FUN_00407520(void)
 * Address ranges: 00407520-00407563
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00407520(int param_1)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
  (*DAT_00410474)();
  if (*(int *)(param_1 + 0x5c) == 0) {
    return 0;
  }
  DVar1 = timeGetTime();
  uVar3 = DVar1 - *(int *)(param_1 + 0x5c);
  if (uVar3 < *(uint *)(param_1 + 0x60)) {
    iVar2 = (int)(((ulonglong)*(uint *)(param_1 + 100) * (ulonglong)uVar3) /
                 (ulonglong)*(uint *)(param_1 + 0x60));
  }
  else {
    iVar2 = *(int *)(param_1 + 100);
  }
  return iVar2 + *(int *)(param_1 + 0x50);
}


/*
 * FUN_00407570 at 00407570
 * undefined FUN_00407570(void)
 * Address ranges: 00407570-004075df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall
FUN_00407570(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  ulonglong uVar4;
  
  uVar1 = (*(uint *)(param_4 + 0x14) >> 2) + 0xfff >> 8 & 0xfffff0;
  *(uint *)(param_4 + 0x3c) = uVar1 * 0x100;
  iVar3 = FUN_00402c30(param_1,param_2,uVar1 * 0x200 + 0x40);
  *(int *)(param_4 + 0x54) = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  *(int *)(param_4 + 0x58) = iVar3 + 0x20 + *(int *)(param_4 + 0x3c);
  *(undefined4 *)(param_4 + 0x68) = param_3;
  uVar4 = FUN_004075e0(extraout_ECX,*(int *)(param_4 + 0x3c));
  uVar2 = DAT_0040e894;
  if ((char)uVar4 == '\0') {
    FUN_00402c10();
    return 0;
  }
  DAT_0040e894 = param_4;
  *(undefined4 *)(param_4 + 0x34) = uVar2;
  return 1;
}


/*
 * FUN_004075e0 at 004075e0
 * ulonglong __fastcall FUN_004075e0(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004075e0-00407791
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


ulonglong __fastcall FUN_004075e0(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined1 uVar2;
  int in_EAX;
  MMRESULT MVar3;
  DWORD DVar4;
  DWORD DVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  WORD local_28;
  ushort local_26;
  DWORD local_24;
  DWORD local_20;
  WORD local_1c;
  ushort local_1a;
  
  local_28 = 1;
  local_26 = (ushort)(byte)(*(char *)(in_EAX + 0x4c) + 1);
  if (*(int *)(in_EAX + 0x48) == 0) {
    local_1a = 8;
  }
  else {
    local_1a = 0x10;
  }
  local_24 = *(DWORD *)(in_EAX + 0x40);
  local_20 = local_24 * ((int)(uint)local_1a >> 3) * (uint)local_26;
  local_1c = local_26 * (short)((int)(uint)local_1a >> 3);
  MVar3 = waveOutOpen((LPHWAVEOUT)(in_EAX + 0x38),0xffffffff,(LPCWAVEFORMATEX)&local_28,0,
                      *(DWORD_PTR *)(in_EAX + 0x68),0);
  if (MVar3 == 0) {
    puVar10 = *(undefined4 **)(in_EAX + 0x54);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar10 = *(undefined4 **)(in_EAX + 0x58);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar10 = 0;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    **(int **)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 0x20;
    **(int **)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) + 0x20;
    uVar6 = *(undefined4 *)(in_EAX + 0x3c);
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = uVar6;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 4) = uVar6;
    waveOutPrepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x54),0x20);
    waveOutPrepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x58),0x20);
    pbVar1 = (byte *)(*(int *)(in_EAX + 0x58) + 0x10);
    *pbVar1 = *pbVar1 | 1;
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = 4;
    uVar9 = *(uint *)(in_EAX + 0x3c);
    if (*(int *)(in_EAX + 0x48) == 0) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = 0;
    }
    puVar10 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x20);
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar10 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
      puVar10 = puVar10 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar10 = uVar2;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    waveOutWrite(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x54),0x20);
    DVar4 = timeGetTime();
    do {
      DVar5 = timeGetTime();
      if (DVar4 + 1000 <= DVar5) {
        pbVar1 = (byte *)(*(int *)(in_EAX + 0x54) + 0x10);
        *pbVar1 = *pbVar1 | 1;
        uVar6 = FUN_004077a0();
        return CONCAT44(param_2,uVar6) & 0xffffffffffffff00;
      }
    } while ((*(byte *)(*(int *)(in_EAX + 0x54) + 0x10) & 1) == 0);
    uVar9 = CONCAT31((int3)((uint)*(int *)(in_EAX + 0x54) >> 8),1);
  }
  else {
    uVar9 = MVar3 & 0xffffff00;
  }
  return CONCAT44(param_2,uVar9);
}


/*
 * FUN_004077a0 at 004077a0
 * undefined __stdcall FUN_004077a0(void)
 * Address ranges: 004077a0-00407800
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004077a0(void)

{
  int in_EAX;
  
  if (*(HWAVEOUT *)(in_EAX + 0x38) != (HWAVEOUT)0x0) {
    waveOutReset(*(HWAVEOUT *)(in_EAX + 0x38));
    do {
      do {
      } while (((*(LPWAVEHDR *)(in_EAX + 0x54))->dwFlags & 1) == 0);
    } while ((*(byte *)(*(int *)(in_EAX + 0x58) + 0x10) & 1) == 0);
    waveOutUnprepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x54),0x20);
    waveOutUnprepareHeader(*(HWAVEOUT *)(in_EAX + 0x38),*(LPWAVEHDR *)(in_EAX + 0x58),0x20);
    waveOutClose(*(HWAVEOUT *)(in_EAX + 0x38));
    *(undefined4 *)(in_EAX + 0x38) = 0;
  }
  return;
}


/*
 * entry at 00407802
 * int __fastcall entry(undefined4 param_1, uint param_2, undefined4 param_3, int param_4, undefined4 param_5)
 * Address ranges: 00407802-00407806
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00407d43
 */


int __fastcall
entry(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  int unaff_EBX;
  longlong lVar3;
  undefined8 uVar4;
  
  switch(param_4) {
  case 0:
    unaff_EBX = FUN_00408d25(param_3,param_4);
    FUN_00408c11(extraout_ECX_04,0xff);
    uVar2 = extraout_ECX_05;
    if (DAT_0040f058 != (code *)0x0) {
      (*DAT_0040f058)(param_3,param_4,param_5);
      uVar2 = extraout_ECX_06;
    }
    FUN_00408c11(uVar2,0xf);
    FUN_00408984();
    DAT_004104ec = DAT_004104ec + -1;
    break;
  case 1:
    DAT_004104ec = DAT_004104ec + 1;
    if ((DAT_004104ec < 2) || (uVar4 = FUN_00408d3e(param_1,DAT_004104ec), (int)uVar4 == 0)) {
      FUN_00408bc6();
      iVar1 = FUN_00407892(extraout_ECX,0);
      if (iVar1 != 0) {
        uVar4 = FUN_004088eb(extraout_ECX_00,extraout_EDX);
        if (((int)uVar4 != 0) &&
           (lVar3 = FUN_00408937(extraout_ECX_01,(uint)((ulonglong)uVar4 >> 0x20)), (int)lVar3 != 0)
           ) {
          FUN_00408bc6();
          FUN_004089fb();
          if ((DAT_0040f058 == (code *)0x0) ||
             (iVar1 = (*DAT_0040f058)(param_3,param_4,param_5), iVar1 != 0)) {
            FUN_00408bc6();
            FUN_00408e0e();
            iVar1 = FUN_00408d25(param_3,param_4);
            if (iVar1 != 0) {
              return iVar1;
            }
            FUN_00408c11(extraout_ECX_03,0xff);
            return 0;
          }
          FUN_00408c11(extraout_ECX_02,0xf);
        }
      }
    }
    unaff_EBX = 0;
    break;
  case 2:
    lVar3 = FUN_00408937(param_1,param_2);
    unaff_EBX = 0;
    if ((int)lVar3 != 0) {
      unaff_EBX = FUN_00408d25(param_3,param_4);
    }
    break;
  case 3:
    unaff_EBX = FUN_00408d25(param_3,param_4);
    FUN_00408984();
  }
  return unaff_EBX;
}


/*
 * FUN_00407882 at 00407882
 * undefined4 __stdcall FUN_00407882(void)
 * Address ranges: 00407882-00407886
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00407882(void)

{
  return DAT_004104e4;
}


/*
 * FUN_00407887 at 00407887
 * undefined __stdcall FUN_00407887(void)
 * Address ranges: 00407887-00407887
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00407887(void)

{
  return;
}


/*
 * thunk_FUN_004085c7 at 00407888
 * undefined8 __fastcall thunk_FUN_004085c7(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407888-0040788c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_004085c7
 */


undefined8 __fastcall thunk_FUN_004085c7(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_004085c7(param_1,param_2);
  return uVar1;
}


/*
 * thunk_FUN_004086dc at 0040788d
 * undefined __fastcall thunk_FUN_004086dc(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0040788d-00407891
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_004086dc
 */


void __fastcall thunk_FUN_004086dc(undefined4 param_1,undefined4 param_2)

{
  FUN_004086dc(param_1,param_2);
  return;
}


/*
 * FUN_00407892 at 00407892
 * undefined4 __fastcall FUN_00407892(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407892-004079b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00407892(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  HMODULE unaff_EBX;
  undefined8 uVar3;
  CHAR local_10c [260];
  
  DAT_004104e0 = in_EAX;
  uVar3 = FUN_004088ac(param_1,param_2);
  DAT_004104e4 = (int)uVar3;
  if (DAT_004104e4 == 0) {
    if (in_EAX == 0) {
                    /* WARNING: Subroutine does not return */
      ExitProcess(1);
    }
    uVar2 = 0;
  }
  else {
    FUN_00408708(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
    _DAT_0040f041 = GetEnvironmentStrings();
    GetModuleFileNameA((HMODULE)0x0,local_10c,0x104);
    uVar3 = FUN_00408b80(extraout_ECX_00,extraout_EDX);
    _DAT_0040f014 = (undefined4)uVar3;
    GetCommandLineA();
    uVar3 = FUN_00408b80(0,extraout_EDX_00);
    _DAT_0040f010 = (char *)uVar3;
    if (CONCAT31((int3)((uint)extraout_ECX_01 >> 8),*_DAT_0040f010) != 0x22) {
      do {
        if (((&DAT_0040e620)[(byte)(*_DAT_0040f010 + 1)] & 2) != 0) goto LAB_0040793e;
        if (*_DAT_0040f010 == '\0') goto LAB_0040793e;
        _DAT_0040f010 = _DAT_0040f010 + 1;
      } while( true );
    }
    do {
      _DAT_0040f010 = _DAT_0040f010 + 1;
      if (*_DAT_0040f010 == '\"') break;
    } while (*_DAT_0040f010 != '\0');
    if (*_DAT_0040f010 == '\0') goto LAB_0040793e;
    do {
      _DAT_0040f010 = _DAT_0040f010 + 1;
LAB_0040793e:
    } while (((&DAT_0040e620)[(byte)(*_DAT_0040f010 + 1)] & 2) != 0);
    if (in_EAX != 0) {
      GetModuleFileNameA(unaff_EBX,local_10c,0x104);
      uVar3 = FUN_00408b80(extraout_ECX_02,extraout_EDX_01);
      _DAT_0040f018 = (undefined4)uVar3;
    }
    DVar1 = GetVersion();
    DAT_0040f047 = (undefined1)(DVar1 >> 0x18);
    DAT_0040f049 = (undefined2)DVar1;
    DAT_0040f048 = (byte)(DVar1 >> 0x10) & 0xf;
    uVar2 = 1;
  }
  return uVar2;
}


/*
 * FUN_004079ff at 004079ff
 * undefined __fastcall FUN_004079ff(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004079ff-00407a1d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004079ff(undefined4 param_1,undefined4 param_2)

{
  UINT in_EAX;
  undefined4 extraout_ECX;
  
  FUN_00408533(param_1,param_2);
  FUN_00408c11(extraout_ECX,0xff);
  (*(code *)PTR_FUN_0040ef80)();
                    /* WARNING: Subroutine does not return */
  ExitProcess(in_EAX);
}


/*
 * FUN_00407a1e at 00407a1e
 * uint * __stdcall FUN_00407a1e(void)
 * Address ranges: 00407a1e-00407ac0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint * FUN_00407a1e(void)

{
  uint uVar1;
  uint in_EAX;
  uint uVar2;
  int unaff_EBX;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  if (((in_EAX != 0) && (in_EAX < 0xfffffff5)) &&
     (uVar2 = in_EAX + 0xb & 0xfffffff8, uVar2 = (uVar2 - 0x10 & -(uint)(0xf < uVar2)) + 0x10,
     uVar2 <= *(uint *)(unaff_EBX + 0x14))) {
    puVar3 = *(uint **)(unaff_EBX + 0xc);
    uVar4 = *(uint *)(unaff_EBX + 0x10);
    if (uVar2 <= uVar4) {
      puVar3 = *(uint **)(unaff_EBX + 0x28);
      uVar4 = 0;
    }
    do {
      uVar1 = *puVar3;
      if (uVar2 <= uVar1) {
        *(uint *)(unaff_EBX + 0x10) = uVar4;
        *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + 1;
        uVar4 = puVar3[2];
        if (uVar1 - uVar2 < 0x10) {
          *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + -1;
          uVar2 = puVar3[1];
          *(uint *)(uVar2 + 8) = uVar4;
          *(uint *)(uVar4 + 4) = uVar2;
          *(uint *)(unaff_EBX + 0xc) = uVar2;
        }
        else {
          puVar5 = (uint *)((int)puVar3 + uVar2);
          *(uint **)(unaff_EBX + 0xc) = puVar5;
          *puVar5 = uVar1 - uVar2;
          *puVar3 = uVar2;
          uVar2 = puVar3[1];
          puVar5[1] = uVar2;
          puVar5[2] = uVar4;
          *(uint **)(uVar2 + 8) = puVar5;
          *(uint **)(uVar4 + 4) = puVar5;
        }
        *puVar3 = *puVar3 | 1;
        return puVar3 + 1;
      }
      uVar4 = (uVar4 - uVar1 & -(uint)(uVar1 <= uVar4)) + uVar1;
      puVar3 = (uint *)puVar3[2];
    } while (puVar3 != (uint *)(unaff_EBX + 0x20U));
    *(uint *)(unaff_EBX + 0x14) = uVar4;
  }
  return (uint *)0x0;
}


/*
 * FUN_00407ac6 at 00407ac6
 * undefined __stdcall FUN_00407ac6(void)
 * Address ranges: 00407ac1-00407bd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00407ac6(void)

{
  undefined4 *in_EAX;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  if (in_EAX == (undefined4 *)0x0) {
    return;
  }
  puVar4 = in_EAX + -1;
  if ((*puVar4 & 1) == 0) {
    return;
  }
  uVar3 = *puVar4 & 0xfffffffe;
  puVar6 = (uint *)((int)puVar4 + uVar3);
  if ((*puVar6 & 1) == 0) {
    if (puVar6 == *(uint **)(unaff_EBX + 0xc)) {
      *(uint **)(unaff_EBX + 0xc) = puVar4;
    }
    *puVar4 = uVar3 + *puVar6;
    uVar3 = puVar6[1];
    puVar6 = (uint *)puVar6[2];
    *(uint **)(uVar3 + 8) = puVar6;
    puVar6[1] = uVar3;
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + -1;
  }
  else {
    *puVar4 = uVar3;
    puVar6 = *(uint **)(unaff_EBX + 0xc);
    if (puVar4 < puVar6) {
      if (((uint *)puVar6[1] < puVar4) || (puVar6 = *(uint **)(unaff_EBX + 0x28), puVar4 < puVar6))
      goto LAB_00407b84;
    }
    else {
      puVar6 = (uint *)puVar6[2];
      if ((puVar4 < puVar6) ||
         (puVar6 = (uint *)(unaff_EBX + 0x20), *(uint **)(unaff_EBX + 0x24) < puVar4))
      goto LAB_00407b84;
    }
    uVar3 = *(uint *)(unaff_EBX + 0x1c);
    uVar1 = *(uint *)(unaff_EBX + 0x18) / (uVar3 + 1);
    if (uVar1 < uVar3) {
      iVar2 = uVar1 * 2;
      if (*(int *)(unaff_EBX + 0x18) - uVar3 <= uVar3) {
        iVar2 = 0;
      }
      puVar6 = (uint *)((int)puVar4 + *puVar4);
      do {
        uVar3 = *puVar6;
        if ((uVar3 & 1) == 0) goto LAB_00407b84;
        if (uVar3 == 0xffffffff) break;
        puVar6 = (uint *)((int)puVar6 + (uVar3 & 0xfffffffe));
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    puVar6 = *(uint **)(unaff_EBX + 0xc);
    if (puVar4 < puVar6) {
      puVar6 = *(uint **)(unaff_EBX + 0x28);
    }
    while (((puVar6 <= puVar4 && (puVar6 = (uint *)puVar6[2], puVar6 <= puVar4)) &&
           (puVar6 = (uint *)puVar6[2], puVar6 <= puVar4))) {
      puVar6 = (uint *)puVar6[2];
    }
  }
LAB_00407b84:
  puVar5 = (uint *)puVar6[1];
  uVar3 = *puVar4;
  if ((uint *)((int)puVar5 + *puVar5) == puVar4) {
    uVar3 = uVar3 + *puVar5;
    *puVar5 = uVar3;
    if (puVar4 == *(uint **)(unaff_EBX + 0xc)) {
      *(uint **)(unaff_EBX + 0xc) = puVar5;
    }
  }
  else {
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + 1;
    in_EAX[1] = puVar6;
    *in_EAX = puVar5;
    puVar5[2] = (uint)puVar4;
    puVar6[1] = (uint)puVar4;
    puVar5 = puVar4;
  }
  *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + -1;
  if ((puVar5 < *(uint **)(unaff_EBX + 0xc)) && (*(uint *)(unaff_EBX + 0x10) < uVar3)) {
    *(uint *)(unaff_EBX + 0x10) = uVar3;
  }
  if (*(uint *)(unaff_EBX + 0x14) < uVar3) {
    *(uint *)(unaff_EBX + 0x14) = uVar3;
  }
  return;
}


/*
 * FUN_00407bd1 at 00407bd1
 * undefined8 __fastcall FUN_00407bd1(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407bd1-00407c44
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00407bd1(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  int *piVar3;
  
  piVar1 = DAT_0040e864;
  piVar3 = (int *)0x0;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 <= in_EAX))) {
    piVar3 = piVar2;
    piVar1 = (int *)piVar2[2];
  }
  in_EAX[1] = (int)piVar3;
  in_EAX[2] = (int)piVar2;
  piVar1 = in_EAX;
  if (piVar3 != (int *)0x0) {
    piVar3[2] = (int)in_EAX;
    piVar1 = DAT_0040e864;
  }
  DAT_0040e864 = piVar1;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = (int)in_EAX;
  }
  piVar1 = in_EAX + 8;
  piVar3 = in_EAX + 0xb;
  in_EAX[8] = 0;
  in_EAX[4] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[9] = (int)piVar1;
  in_EAX[10] = (int)piVar1;
  in_EAX[3] = (int)piVar1;
  *piVar3 = *in_EAX + -0x2c;
  *(undefined4 *)((int)piVar3 + *in_EAX + -0x2c) = 0xffffffff;
  return CONCAT44(param_2,piVar3);
}


/*
 * FUN_00407c45 at 00407c45
 * undefined8 __fastcall FUN_00407c45(undefined4 param_1, uint param_2)
 * Address ranges: 00407c45-00407cd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00407c45(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  if ((DAT_0040f050 != 0) && (DAT_0040f00c != -2)) {
    lVar5 = FUN_00407ce6(param_1,param_2);
    uVar1 = 0;
    if ((int)lVar5 == 0) goto LAB_00407ccc;
    puVar2 = VirtualAlloc((LPVOID)0x0,in_EAX,0x1000,0x40);
    uVar1 = 0;
    if (puVar2 == (uint *)0x0) goto LAB_00407ccc;
    uVar3 = in_EAX - 4;
    if ((uVar3 <= in_EAX) && (0x37 < uVar3)) {
      *puVar2 = uVar3;
      uVar6 = FUN_00407bd1(extraout_ECX,puVar2);
      iVar4 = (int)((ulonglong)uVar6 >> 0x20);
      *(uint *)uVar6 = *(uint *)uVar6 | 1;
      *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
      FUN_0040650f();
      uVar1 = 1;
      goto LAB_00407ccc;
    }
  }
  uVar1 = 0;
LAB_00407ccc:
  return CONCAT44(param_2,uVar1);
}


/*
 * FUN_00407cd5 at 00407cd5
 * undefined8 __fastcall FUN_00407cd5(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407cd5-00407ce5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00407cd5(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  undefined4 extraout_ECX;
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00408c60(param_1,in_EAX);
  uVar2 = FUN_00407c45(extraout_ECX,(uint)((ulonglong)lVar1 >> 0x20));
  return CONCAT44(param_2,(int)uVar2);
}


/*
 * FUN_00407ce6 at 00407ce6
 * longlong __fastcall FUN_00407ce6(undefined4 param_1, uint param_2)
 * Address ranges: 00407ce6-00407d2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall FUN_00407ce6(undefined4 param_1,uint param_2)

{
  uint *in_EAX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = *in_EAX + 0xb & 0xfffffff8;
  uVar2 = 0;
  if (uVar1 == 0) {
LAB_00407d2d:
    return CONCAT44(param_2,uVar2);
  }
  *in_EAX = uVar1;
  uVar1 = uVar1 + 0x3c;
  if (*in_EAX <= uVar1) {
    if (uVar1 < DAT_0040f054) {
      uVar1 = DAT_0040f054 & 0xfffffffe;
    }
    *in_EAX = uVar1;
    if (*in_EAX <= uVar1 + 0xfff) {
      uVar2 = uVar1 + 0xfff >> 8 & 0xfffff0;
      *in_EAX = uVar2 << 8;
      uVar2 = (uint)(uVar2 != 0);
      goto LAB_00407d2d;
    }
  }
  return (ulonglong)param_2 << 0x20;
}


/*
 * FUN_00407d30 at 00407d30
 * undefined4 __stdcall FUN_00407d30(void)
 * Address ranges: 00407d30-00407d32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00407d30(void)

{
  return 0;
}


/*
 * FUN_00407d43 at 00407d43
 * int __fastcall FUN_00407d43(undefined4 param_1, uint param_2, undefined4 param_3, int param_4, undefined4 param_5)
 * Address ranges: 00407d43-00407e91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int __fastcall
FUN_00407d43(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  int unaff_EBX;
  longlong lVar3;
  undefined8 uVar4;
  
  switch(param_4) {
  case 0:
    unaff_EBX = FUN_00408d25(param_3,param_4);
    FUN_00408c11(extraout_ECX_04,0xff);
    uVar2 = extraout_ECX_05;
    if (DAT_0040f058 != (code *)0x0) {
      (*DAT_0040f058)(param_3,param_4,param_5);
      uVar2 = extraout_ECX_06;
    }
    FUN_00408c11(uVar2,0xf);
    FUN_00408984();
    DAT_004104ec = DAT_004104ec + -1;
    break;
  case 1:
    DAT_004104ec = DAT_004104ec + 1;
    if ((DAT_004104ec < 2) || (uVar4 = FUN_00408d3e(param_1,DAT_004104ec), (int)uVar4 == 0)) {
      FUN_00408bc6();
      iVar1 = FUN_00407892(extraout_ECX,0);
      if (iVar1 != 0) {
        uVar4 = FUN_004088eb(extraout_ECX_00,extraout_EDX);
        if (((int)uVar4 != 0) &&
           (lVar3 = FUN_00408937(extraout_ECX_01,(uint)((ulonglong)uVar4 >> 0x20)), (int)lVar3 != 0)
           ) {
          FUN_00408bc6();
          FUN_004089fb();
          if ((DAT_0040f058 == (code *)0x0) ||
             (iVar1 = (*DAT_0040f058)(param_3,param_4,param_5), iVar1 != 0)) {
            FUN_00408bc6();
            FUN_00408e0e();
            iVar1 = FUN_00408d25(param_3,param_4);
            if (iVar1 != 0) {
              return iVar1;
            }
            FUN_00408c11(extraout_ECX_03,0xff);
            return 0;
          }
          FUN_00408c11(extraout_ECX_02,0xf);
        }
      }
    }
    unaff_EBX = 0;
    break;
  case 2:
    lVar3 = FUN_00408937(param_1,param_2);
    unaff_EBX = 0;
    if ((int)lVar3 != 0) {
      unaff_EBX = FUN_00408d25(param_3,param_4);
    }
    break;
  case 3:
    unaff_EBX = FUN_00408d25(param_3,param_4);
    FUN_00408984();
  }
  return unaff_EBX;
}


/*
 * FUN_00407eb6 at 00407eb6
 * undefined4 __fastcall FUN_00407eb6(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407eb1-00407ec1;00407ed9-00407eea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00407eb6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00407f92(param_1,param_2);
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if ((iVar1 != 2) && (iVar1 != 3)) {
    return 1;
  }
  return 0;
}


/*
 * FUN_00407eeb at 00407eeb
 * undefined4 __stdcall FUN_00407eeb(void)
 * Address ranges: 00407eeb-00407f29
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00407eeb(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  if ((*(int *)(iVar1 + 0x78) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_0040ef44)(), *(int *)(iVar1 + 0x78) != 3)) {
    return 1;
  }
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  if ((*(int *)(iVar1 + 0x90) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_0040ef44)(), *(int *)(iVar1 + 0x90) != 3)) {
    return 1;
  }
  return 0;
}


/*
 * FUN_00407f56 at 00407f56
 * undefined8 __fastcall FUN_00407f56(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407f56-00407f8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00407f56(undefined4 param_1,undefined4 param_2)

{
  BOOL BVar1;
  
  if (DAT_0040eff4 != '\0') {
    BVar1 = SetConsoleCtrlHandler((PHANDLER_ROUTINE)&DAT_00407e92,0);
    if (BVar1 != 0) {
      DAT_0040eff4 = '\0';
    }
  }
  return CONCAT44(param_2,(uint)(DAT_0040eff4 == '\0'));
}


/*
 * FUN_00407f92 at 00407f92
 * undefined8 __fastcall FUN_00407f92(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407f92-00407fca;00408099-004080f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00407f92(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  uint uVar3;
  undefined4 extraout_EDX_00;
  ulonglong uVar4;
  code *pcVar5;
  
  uVar4 = (*(code *)PTR_FUN_0040ef44)();
  uVar3 = (uint)(uVar4 >> 0x20);
  pcVar5 = *(code **)((int)uVar4 + 0x58 + in_EAX * 8);
  if (uVar4 < 0x200000000) {
    if (uVar3 == 1) {
      if (pcVar5 == (code *)0x2) {
        FUN_00408e57(extraout_ECX);
        uVar3 = extraout_EDX;
      }
LAB_004080b9:
      if (((pcVar5 != (code *)0x1) && (pcVar5 != (code *)0x2)) && (pcVar5 != (code *)0x3)) {
        iVar2 = (*(code *)PTR_FUN_0040ef44)(pcVar5,param_2,param_1);
        *(undefined4 *)(iVar2 + 0x58 + uVar3 * 8) = 2;
        (*pcVar5)();
      }
      iVar2 = FUN_00407eeb();
      if (iVar2 == 0) {
        FUN_00407f56(extraout_ECX_00,extraout_EDX_00);
      }
      goto LAB_004080ee;
    }
  }
  else {
    if (uVar4 < 0x300000000) {
      FUN_00407fcb(extraout_ECX,uVar3);
LAB_004080ee:
      uVar1 = 0;
      goto LAB_004080f0;
    }
    if (uVar4 < 0xd00000000) goto LAB_004080b9;
  }
  uVar1 = 0xffffffff;
LAB_004080f0:
  return CONCAT44(param_2,uVar1);
}


/*
 * FUN_00407fcb at 00407fcb
 * longlong __fastcall FUN_00407fcb(undefined4 param_1, uint param_2)
 * Address ranges: 00407fcb-00408011
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall FUN_00407fcb(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_FUN_0040ef44)();
  pcVar1 = *(code **)(iVar2 + 0x68);
  if (((pcVar1 != (code *)0x1) && (pcVar1 != (code *)0x2)) && (pcVar1 != (code *)0x3)) {
    iVar2 = (*(code *)PTR_FUN_0040ef44)();
    *(undefined4 *)(iVar2 + 0x68) = 2;
    (*pcVar1)();
    return (ulonglong)param_2 << 0x20;
  }
  return CONCAT44(param_2,0xffffffff);
}


/*
 * FUN_004080f7 at 004080f7
 * undefined8 __fastcall FUN_004080f7(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004080f7-00408123
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_004080f7(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  ushort in_DS;
  undefined8 uVar3;
  
  do {
    uVar3 = (*(code *)PTR_FUN_0040ef44)();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    iVar1 = (int)uVar3 + iVar2;
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(&DAT_0040ef8c + iVar2);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(&DAT_0040ef90 + iVar2);
  } while (iVar2 != 0x60);
  return CONCAT44(param_2,(uint)in_DS);
}


/*
 * FUN_00408124 at 00408124
 * undefined __stdcall FUN_00408124(void)
 * Address ranges: 00408124-00408124
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408124(void)

{
  return;
}


/*
 * FUN_004084f5 at 004084f5
 * undefined __fastcall FUN_004084f5(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004084f5-00408532
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004084f5(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_FS_OFFSET;
  undefined8 uVar2;
  
  uVar2 = (*(code *)PTR_FUN_0040ef44)(param_2);
  *(int *)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  uVar2 = (*(code *)PTR_FUN_0040ef44)();
  **(undefined4 **)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined **)(*(int *)(iVar1 + 0x54) + 4) = &DAT_00408142;
  uVar2 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined4 *)(unaff_FS_OFFSET + (int)((ulonglong)uVar2 >> 0x20)) =
       *(undefined4 *)((int)uVar2 + 0x54);
  return;
}


/*
 * FUN_00408533 at 00408533
 * undefined __fastcall FUN_00408533(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408533-00408581
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00408533(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *unaff_FS_OFFSET;
  
  iVar1 = (*(code *)PTR_FUN_0040ef44)(param_2);
  if (*(undefined4 **)(iVar1 + 0x54) != (undefined4 *)0x0) {
    *unaff_FS_OFFSET = **(undefined4 **)(iVar1 + 0x54);
  }
  iVar1 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined4 *)(iVar1 + 0x54) = 0;
  iVar1 = FUN_00407eeb();
  if (iVar1 != 0) {
    FUN_00407f56(extraout_ECX,extraout_EDX);
    iVar1 = (*(code *)PTR_FUN_0040ef44)();
    *(undefined4 *)(iVar1 + 0x78) = 2;
    iVar1 = (*(code *)PTR_FUN_0040ef44)();
    *(undefined4 *)(iVar1 + 0x90) = 2;
  }
  return;
}


/*
 * FUN_004085c7 at 004085c7
 * undefined8 __fastcall FUN_004085c7(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004085c7-0040863f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_004085c7(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_0040ef78)();
  iVar2 = 0;
  iVar1 = 0;
  while( true ) {
    if (DAT_004104f4 * 4 <= iVar1) {
      DAT_004104f8 = FUN_00408ff5(DAT_004104f4 * 4,(DAT_004104f4 + 1) * 4);
      DAT_004104f8[DAT_004104f4] = in_EAX;
      DAT_004104f4 = DAT_004104f4 + 1;
      (*(code *)PTR_FUN_0040ef7c)();
      return CONCAT44(param_2,DAT_004104f4 + -1);
    }
    if (*(int *)((int)DAT_004104f8 + iVar1) == 0) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
  }
  *(int *)((int)DAT_004104f8 + iVar1) = in_EAX;
  (*(code *)PTR_FUN_0040ef7c)();
  return CONCAT44(param_2,iVar2);
}


/*
 * FUN_004086dc at 004086dc
 * undefined __fastcall FUN_004086dc(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004086dc-00408707
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004086dc(undefined4 param_1,undefined4 param_2)

{
  int extraout_EDX;
  
  (*(code *)PTR_FUN_0040ef78)(param_2);
  if ((0 < extraout_EDX) && (extraout_EDX < DAT_004104f4)) {
    *(undefined4 *)(DAT_004104f8 + extraout_EDX * 4) = 0;
  }
  (*(code *)PTR_FUN_0040ef7c)();
  return;
}


/*
 * FUN_00408708 at 00408708
 * undefined8 __fastcall FUN_00408708(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408708-0040873e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00408708(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar1;
  
  DAT_004104f4 = 0;
  DAT_004104f8 = 0;
  GetStdHandle(0xfffffff6);
  FUN_004085c7(extraout_ECX,extraout_EDX);
  GetStdHandle(0xfffffff5);
  FUN_004085c7(extraout_ECX_00,extraout_EDX_00);
  GetStdHandle(0xfffffff4);
  uVar1 = FUN_004085c7(extraout_ECX_01,extraout_EDX_01);
  return CONCAT44(param_2,(int)uVar1);
}


/*
 * FUN_00408751 at 00408751
 * undefined __stdcall FUN_00408751(void)
 * Address ranges: 00408751-00408751
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408751(void)

{
  return;
}


/*
 * FUN_00408752 at 00408752
 * undefined __stdcall FUN_00408752(void)
 * Address ranges: 00408752-0040877d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408752(void)

{
  undefined4 *in_EAX;
  
  if (in_EAX[1] != 0) {
    CloseHandle((HANDLE)*in_EAX);
  }
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  return;
}


/*
 * FUN_00408805 at 00408805
 * undefined __stdcall FUN_00408805(void)
 * Address ranges: 00408805-00408861
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408805(void)

{
  undefined4 *in_EAX;
  DWORD DVar1;
  HANDLE pvVar2;
  LPSECURITY_ATTRIBUTES lpMutexAttributes;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 != in_EAX[2]) {
    if (in_EAX[1] == 0) {
      FUN_00408805();
      if (in_EAX[1] == 0) {
        pvVar2 = CreateMutexA(lpMutexAttributes,(BOOL)lpMutexAttributes,(LPCSTR)lpMutexAttributes);
        in_EAX[1] = 1;
        *in_EAX = pvVar2;
      }
      FUN_00408867();
    }
    WaitForSingleObject((HANDLE)*in_EAX,0xffffffff);
    in_EAX[2] = DVar1;
  }
  in_EAX[3] = in_EAX[3] + 1;
  return;
}


/*
 * FUN_00408867 at 00408867
 * undefined __stdcall FUN_00408867(void)
 * Address ranges: 00408867-0040888b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408867(void)

{
  int iVar1;
  undefined4 *in_EAX;
  
  if (in_EAX[3] != 0) {
    iVar1 = in_EAX[3] + -1;
    in_EAX[3] = iVar1;
    if (iVar1 == 0) {
      in_EAX[2] = 0;
      ReleaseMutex((HANDLE)*in_EAX);
    }
  }
  return;
}


/*
 * FUN_004088ac at 004088ac
 * undefined8 __fastcall FUN_004088ac(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004088ac-004088ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_004088ac(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  
  if (in_EAX == 0) {
    in_EAX = FUN_0040917a(param_1,DAT_0040f0c0);
    if (in_EAX != 0) {
      *(undefined1 *)(in_EAX + 0x52) = 1;
    }
  }
  if (in_EAX != 0) {
    *(undefined4 *)(in_EAX + 0xc) = 1;
    DVar1 = GetCurrentThreadId();
    *(DWORD *)(in_EAX + 0xda) = DVar1;
  }
  return CONCAT44(param_2,in_EAX);
}


/*
 * FUN_004088eb at 004088eb
 * undefined8 __fastcall FUN_004088eb(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004088eb-00408936
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_004088eb(undefined4 param_1,undefined4 param_2)

{
  DAT_0040ef40 = TlsAlloc();
  if ((DAT_0040f049 >> 8 & 0x80) != 0) {
    while ((DAT_0040ef40 != 0xffffffff && (DAT_0040ef40 < 3))) {
      DAT_0040ef40 = TlsAlloc();
    }
  }
  return CONCAT44(param_2,(uint)(DAT_0040ef40 != 0xffffffff));
}


/*
 * FUN_00408937 at 00408937
 * longlong __fastcall FUN_00408937(undefined4 param_1, uint param_2)
 * Address ranges: 00408937-00408983
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall FUN_00408937(undefined4 param_1,uint param_2)

{
  LPVOID lpTlsValue;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined8 uVar3;
  
  if (DAT_0040ef40 == 0xffffffff) {
LAB_00408943:
    return (ulonglong)param_2 << 0x20;
  }
  uVar3 = FUN_004088ac(param_1,param_2);
  lpTlsValue = (LPVOID)uVar3;
  uVar2 = 0;
  if (lpTlsValue != (LPVOID)0x0) {
    iVar1 = FUN_004090a6(extraout_ECX,(int)lpTlsValue);
    if (iVar1 == 0) {
      FUN_0040650f();
      goto LAB_00408943;
    }
    TlsSetValue(DAT_0040ef40,lpTlsValue);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}


/*
 * FUN_00408984 at 00408984
 * undefined __stdcall FUN_00408984(void)
 * Address ranges: 00408984-004089d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408984(void)

{
  HANDLE hObject;
  int in_EAX;
  LPVOID pvVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (DAT_0040ef40 != 0xffffffff) {
    pvVar1 = TlsGetValue(DAT_0040ef40);
    if (pvVar1 != (LPVOID)0x0) {
      hObject = *(HANDLE *)((int)pvVar1 + 0xde);
      FUN_00409107(extraout_ECX,extraout_EDX);
      TlsSetValue(DAT_0040ef40,(LPVOID)0x0);
      if ((hObject != (HANDLE)0x0) && (in_EAX != 0)) {
        CloseHandle(hObject);
      }
    }
  }
  return;
}


/*
 * FUN_004089db at 004089db
 * undefined __stdcall FUN_004089db(void)
 * Address ranges: 004089db-004089fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004089db(void)

{
  if (DAT_0040ef40 != 0xffffffff) {
    TlsFree(DAT_0040ef40);
    DAT_0040ef40 = 0xffffffff;
  }
  return;
}


/*
 * FUN_004089fb at 004089fb
 * undefined __stdcall FUN_004089fb(void)
 * Address ranges: 004089fb-00408b13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004089fb(void)

{
  PTR_FUN_0040ef48 = &DAT_00408792;
  PTR_FUN_0040ef4c = &DAT_0040879f;
  PTR_thunk_FUN_004085c7_0040ef50 = &LAB_004087af;
  PTR_thunk_FUN_004086dc_0040ef54 = &LAB_004087b4;
  PTR_FUN_0040ef58 = &DAT_0040877e;
  PTR_FUN_0040ef5c = &DAT_00408788;
  PTR_FUN_0040effc = FUN_00408805;
  PTR_FUN_0040f000 = FUN_00408867;
  PTR_FUN_0040f004 = FUN_00408752;
  PTR_FUN_0040ef60 = &DAT_004087d0;
  PTR_FUN_0040ef64 = &DAT_004087e1;
  PTR_FUN_0040ef68 = &DAT_004087d7;
  PTR_FUN_0040ef6c = &DAT_004087e8;
  PTR_FUN_0040ef70 = &DAT_004087f2;
  PTR_FUN_0040ef74 = &DAT_004087f9;
  _DAT_0041062c = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  _DAT_00410630 = 1;
  PTR_FUN_0040ef7c = &DAT_00408862;
  PTR_FUN_0040ef80 = &DAT_004089d1;
  PTR_FUN_0040ef78 = &DAT_00408800;
  FUN_004090a6(&DAT_00408800,(int)DAT_004104e4);
  TlsSetValue(DAT_0040ef40,DAT_004104e4);
  PTR_FUN_0040ef44 = &LAB_0040888c;
  return;
}


/*
 * FUN_00408b14 at 00408b14
 * undefined __fastcall FUN_00408b14(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408b14-00408b7e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00408b14(undefined4 param_1,undefined4 param_2)

{
  int extraout_EDX;
  int extraout_EDX_00;
  
  (*(code *)PTR_FUN_0040f004)(param_2);
  (*(code *)PTR_FUN_0040f004)();
  (*(code *)PTR_FUN_0040f004)();
  do {
    (*(code *)PTR_FUN_0040f004)();
  } while (extraout_EDX_00 != extraout_EDX + 0x100);
  (*(code *)PTR_FUN_0040f004)();
  thunk_FUN_00409151();
  (*(code *)PTR_FUN_0040f004)();
  (*(code *)PTR_FUN_0040f004)();
  FUN_004089db();
  return;
}


/*
 * FUN_00408b80 at 00408b80
 * undefined8 __fastcall FUN_00408b80(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408b80-00408bc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00408b80(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  uint uVar3;
  uint extraout_ECX;
  char *pcVar4;
  undefined8 uVar5;
  
  uVar3 = 0xffffffff;
  pcVar2 = in_EAX;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar5 = FUN_00406420(~uVar3,param_2);
  pcVar2 = (char *)uVar5;
  if (pcVar2 != (char *)0x0) {
    pcVar4 = pcVar2;
    for (uVar3 = extraout_ECX >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)in_EAX;
      in_EAX = in_EAX + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar3 = extraout_ECX & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar4 = *in_EAX;
      in_EAX = in_EAX + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  return CONCAT44(param_2,pcVar2);
}


/*
 * FUN_00408bc6 at 00408bc6
 * undefined __stdcall FUN_00408bc6(void)
 * Address ranges: 00408bc6-00408c10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408bc6(void)

{
  byte in_AL;
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_0040f0ea;
    bVar1 = in_AL;
    for (pcVar3 = &DAT_0040f0e4; pcVar3 < &DAT_0040f0ea; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && ((byte)pcVar3[1] <= bVar1)) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_0040f0ea) break;
    if (*(code **)(pcVar2 + 2) != (code *)0x0) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}


/*
 * FUN_00408c11 at 00408c11
 * undefined __fastcall FUN_00408c11(undefined4 param_1, byte param_2)
 * Address ranges: 00408c11-00408c5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00408c11(undefined4 param_1,byte param_2)

{
  byte in_AL;
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_0040f0f0;
    bVar1 = in_AL;
    for (pcVar3 = &DAT_0040f0ea; pcVar3 < &DAT_0040f0f0; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && (bVar1 <= (byte)pcVar3[1])) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_0040f0f0) break;
    if ((bVar1 <= param_2) && (*(code **)(pcVar2 + 2) != (code *)0x0)) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}


/*
 * FUN_00408c60 at 00408c60
 * longlong __fastcall FUN_00408c60(undefined4 param_1, uint param_2)
 * Address ranges: 00408c60-00408c73;00408cfc-00408d24
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


longlong __fastcall FUN_00408c60(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  (*(code *)PTR_FUN_0040ef60)();
  piVar3 = DAT_0040e864;
  while (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    piVar1 = piVar3 + 9;
    piVar3 = (int *)piVar3[2];
    if (iVar2 + -0x2c == *(int *)*piVar1) {
      FUN_00408cd2(iVar2 + -0x2c);
    }
  }
  (*(code *)PTR_FUN_0040ef68)();
  return (ulonglong)param_2 << 0x20;
}


/*
 * FUN_00408c74 at 00408c74
 * undefined8 __fastcall FUN_00408c74(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408c74-00408cd1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00408c74(undefined4 param_1,undefined4 param_2)

{
  LPVOID pvVar1;
  LPVOID in_EAX;
  BOOL BVar2;
  undefined4 uVar3;
  
  pvVar1 = *(LPVOID *)((int)in_EAX + 8);
  BVar2 = VirtualFree(in_EAX,0,0x8000);
  if (BVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if ((in_EAX == DAT_0040e868) && (DAT_0040e868 = pvVar1, pvVar1 == (LPVOID)0x0)) {
      DAT_0040e868 = DAT_0040e864;
      DAT_0040e86c = 0;
    }
    if (in_EAX == DAT_004104c8) {
      DAT_004104c8 = (LPVOID)0x0;
    }
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}


/*
 * FUN_00408cd2 at 00408cd2
 * undefined __fastcall FUN_00408cd2(undefined4 param_1)
 * Address ranges: 00408cd2-00408cfb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00408cd2(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(in_EAX + 4);
  uVar4 = FUN_00408c74(param_1,*(undefined4 *)(in_EAX + 8));
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 0) {
    iVar2 = iVar3;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 8) = iVar3;
      iVar2 = DAT_0040e864;
    }
    DAT_0040e864 = iVar2;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 4) = iVar1;
    }
  }
  return;
}


/*
 * FUN_00408d25 at 00408d25
 * undefined __stdcall FUN_00408d25(undefined4 param_1, int param_2)
 * Address ranges: 00408d25-00408d3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408d25(undefined4 param_1,int param_2)

{
  FUN_00401010(param_1,param_2);
  return;
}


/*
 * FUN_00408d3e at 00408d3e
 * undefined8 __fastcall FUN_00408d3e(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408d3e-00408e0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_00408d3e(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  HMODULE in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00410844,0x104);
  pcVar3 = s_This_Dynamic_Link_Library_is_alr_0040e4e0;
  GetModuleFileNameA(in_EAX,&DAT_00410948,0x104);
  DAT_0041065c = 0;
  iVar2 = -1;
  pcVar5 = &DAT_0041065c;
  do {
    pcVar4 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  pcVar3 = &DAT_00410844;
  iVar2 = -1;
  pcVar5 = &DAT_0041065c;
  do {
    pcVar4 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  pcVar3 = s_The_Watcom_WIN32_runtime_library_0040e511;
  iVar2 = -1;
  pcVar5 = &DAT_0041065c;
  do {
    pcVar4 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  MessageBoxA((HWND)0x0,&DAT_0041065c,&DAT_00410948,0);
  return CONCAT44(param_2,1);
}


/*
 * FUN_00408e0e at 00408e0e
 * undefined __stdcall FUN_00408e0e(void)
 * Address ranges: 00408e0e-00408e18
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408e0e(void)

{
  DAT_0040f054 = 0x8000;
  return;
}


/*
 * FUN_00408e57 at 00408e57
 * undefined __fastcall FUN_00408e57(undefined4 param_1)
 * Address ranges: 00408e57-00408e68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00408e57(undefined4 param_1)

{
  FUN_004091ce(param_1,0xff);
  return;
}


/*
 * FUN_00408e69 at 00408e69
 * uint __fastcall FUN_00408e69(undefined4 param_1, uint param_2)
 * Address ranges: 00408e69-00408ebb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_00408e69(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  ushort in_FPUControlWord;
  undefined4 local_18;
  
  local_18 = 0;
  if ((DAT_0040f0c4 != '\0') && (local_18 = (uint)in_FPUControlWord, param_2 != 0)) {
    local_18 = ~param_2 & local_18 | param_2 & in_EAX & 0xffff;
  }
  return local_18;
}


/*
 * FUN_00408ec5 at 00408ec5
 * undefined __stdcall FUN_00408ec5(void)
 * Address ranges: 00408ec5-00408ef5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408ec5(void)

{
  if (DAT_0040f0c5 != '\0') {
    PTR_FUN_0040f0c8 = &LAB_00408ebc;
    PTR_FUN_0040f0cc = &LAB_00408ec1;
  }
  FUN_004091ec();
  return;
}


/*
 * FUN_00408f00 at 00408f00
 * undefined __stdcall FUN_00408f00(void)
 * Address ranges: 00408f00-00408f49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00408f00(void)

{
  char cVar1;
  
  if (DAT_0040f0c4 == '\0') {
    DAT_0040f0c5 = DAT_0040f0c4;
    cVar1 = FUN_00408ec5();
    if (DAT_0040f03c == '\0') {
      DAT_0040f0c4 = cVar1;
      DAT_0040f0c5 = cVar1;
    }
  }
  return;
}


/*
 * FUN_00408ff5 at 00408ff5
 * undefined4 * __fastcall FUN_00408ff5(undefined4 param_1, int param_2)
 * Address ranges: 00408ff5-0040906e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 * __fastcall FUN_00408ff5(undefined4 param_1,int param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  uint uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  if (in_EAX == (undefined4 *)0x0) {
    uVar5 = FUN_00406420(param_2,param_2);
    puVar1 = (undefined4 *)uVar5;
  }
  else if (param_2 == 0) {
    FUN_0040650f();
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = FUN_00409213();
    uVar5 = FUN_0040921c();
    puVar1 = (undefined4 *)uVar5;
    if (puVar1 == (undefined4 *)0x0) {
      uVar5 = FUN_00406420(extraout_ECX,(int)((ulonglong)uVar5 >> 0x20));
      puVar1 = (undefined4 *)uVar5;
      if (puVar1 == (undefined4 *)0x0) {
        FUN_0040921c();
      }
      else {
        puVar4 = puVar1;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = *in_EAX;
          in_EAX = in_EAX + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)in_EAX;
          in_EAX = (undefined4 *)((int)in_EAX + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        FUN_0040650f();
      }
    }
  }
  return puVar1;
}


/*
 * FUN_0040906f at 0040906f
 * undefined8 __fastcall FUN_0040906f(undefined4 param_1, uint param_2)
 * Address ranges: 0040906f-004090a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_0040906f(undefined4 param_1,uint param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  LPVOID pvVar2;
  longlong lVar3;
  
  lVar3 = FUN_00408937(param_1,param_2);
  pvVar2 = (LPVOID)0x0;
  uVar1 = extraout_ECX;
  if ((int)lVar3 != 0) {
    pvVar2 = TlsGetValue(DAT_0040ef40);
    uVar1 = extraout_ECX_00;
  }
  if (pvVar2 == (LPVOID)0x0) {
    FUN_004091ce(uVar1,1);
  }
  return CONCAT44(param_2,pvVar2);
}


/*
 * FUN_004090a6 at 004090a6
 * undefined4 __fastcall FUN_004090a6(undefined4 param_1, int param_2)
 * Address ranges: 004090a6-00409106
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_004090a6(undefined4 param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  (*(code *)PTR_FUN_0040ef70)();
  iVar1 = FUN_0040917a(1,0x10);
  if (iVar1 != 0) {
    uVar3 = FUN_00409405();
    puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 == 0) {
      puVar2[2] = param_2;
      puVar2[1] = in_EAX;
      puVar2[3] = (uint)*(byte *)(param_2 + 0x52);
      *puVar2 = DAT_00410a4c;
      DAT_00410a4c = puVar2;
    }
    else {
      FUN_0040650f();
    }
  }
  (*(code *)PTR_FUN_0040ef74)();
  return extraout_ECX;
}


/*
 * FUN_00409107 at 00409107
 * undefined __fastcall FUN_00409107(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00409107-00409150
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00409107(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int extraout_ECX;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  (*(code *)PTR_FUN_0040ef70)(param_2,param_1);
  puVar1 = DAT_00410a4c;
  puVar3 = &DAT_00410a4c;
  do {
    puVar2 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
LAB_00409147:
      (*(code *)PTR_FUN_0040ef74)();
      return;
    }
    if (extraout_ECX == puVar2[1]) {
      if (puVar2[3] != 0) {
        FUN_0040650f();
        puVar2 = extraout_EDX;
      }
      *puVar3 = *puVar2;
      FUN_0040650f();
      goto LAB_00409147;
    }
    puVar1 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  } while( true );
}


/*
 * FUN_00409151 at 00409151
 * undefined __stdcall FUN_00409151(void)
 * Address ranges: 00409151-00409179
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00409151(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00410a4c;
  while (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 3;
    puVar2 = (undefined4 *)*puVar2;
    if (*piVar1 != 0) {
      FUN_0040650f();
    }
    FUN_0040650f();
  }
  return;
}


/*
 * FUN_0040917a at 0040917a
 * undefined __fastcall FUN_0040917a(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0040917a-00409191
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0040917a(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined8 uVar1;
  
  uVar1 = FUN_00406420(param_1,param_2);
  if ((int)uVar1 != 0) {
    FUN_00409450(extraout_ECX,0);
  }
  return;
}


/*
 * thunk_FUN_00409151 at 00409192
 * undefined __stdcall thunk_FUN_00409151(void)
 * Address ranges: 00409192-00409196
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00409151
 */


void thunk_FUN_00409151(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00410a4c;
  while (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 3;
    puVar2 = (undefined4 *)*puVar2;
    if (*piVar1 != 0) {
      FUN_0040650f();
    }
    FUN_0040650f();
  }
  return;
}


/*
 * FUN_00409197 at 00409197
 * undefined __stdcall FUN_00409197(void)
 * Address ranges: 00409197-004091cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00409197(void)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  DWORD nNumberOfBytesToWrite;
  DWORD local_14;
  
  nNumberOfBytesToWrite = 0;
  pcVar2 = in_EAX;
  while (cVar1 = *pcVar2, pcVar2 = pcVar2 + 1, cVar1 != '\0') {
    nNumberOfBytesToWrite = nNumberOfBytesToWrite + 1;
  }
  WriteFile(*(HANDLE *)(DAT_004104f8 + 8),in_EAX,nNumberOfBytesToWrite,&local_14,(LPOVERLAPPED)0x0);
  FUN_004079ff(extraout_ECX,extraout_EDX);
  return;
}


/*
 * FUN_004091ce at 004091ce
 * undefined __fastcall FUN_004091ce(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004091ce-004091ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004091ce(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 in_DS;
  
  iVar1 = FUN_00409468(param_2,in_DS);
  if (iVar1 == 0) {
    FUN_00409197();
  }
  return;
}


/*
 * FUN_004091eb at 004091eb
 * undefined FUN_004091eb(void)
 * Address ranges: 004091eb-004091eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004091eb(void)

{
  return;
}


/*
 * FUN_004091ec at 004091ec
 * ushort __stdcall FUN_004091ec(void)
 * Address ranges: 004091ec-00409212
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


ushort FUN_004091ec(void)

{
  byte bVar2;
  ushort uVar1;
  float10 fVar3;
  float10 fVar4;
  
  fVar4 = (float10)1 / (float10)0;
  fVar3 = -fVar4;
  bVar2 = fVar3 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8);
  uVar1 = CONCAT11(bVar2,2);
  if ((uVar1 & 0x4000) == 0) {
    uVar1 = CONCAT11(bVar2,3);
  }
  LOCK();
  UNLOCK();
  return uVar1;
}


/*
 * FUN_00409213 at 00409213
 * int __stdcall FUN_00409213(void)
 * Address ranges: 00409213-0040921b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00409213(void)

{
  int in_EAX;
  
  return (*(uint *)(in_EAX + -4) & 0xfffffffe) - 4;
}


/*
 * FUN_0040921c at 0040921c
 * undefined __stdcall FUN_0040921c(void)
 * Address ranges: 0040921c-00409255;004093e5-004093f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040921c(void)

{
  uint in_EAX;
  int iVar1;
  uint uStack_10;
  
  (*(code *)PTR_FUN_0040ef60)();
  iVar1 = FUN_00409256(&uStack_10,in_EAX);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_0040ef68)();
  }
  else {
    (*(code *)PTR_FUN_0040ef68)();
  }
  return;
}


/*
 * FUN_00409256 at 00409256
 * undefined4 __fastcall FUN_00409256(uint * param_1, uint param_2)
 * Address ranges: 00409256-004093e4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00409256(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  short in_AX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_EBX;
  uint *puVar6;
  undefined4 uVar7;
  uint unaff_ESI;
  short in_DS;
  
  uVar3 = unaff_EBX + 7 & 0xfffffffc;
  if (uVar3 < unaff_EBX) {
    uVar3 = 0xffffffff;
  }
  if (uVar3 < 0xc) {
    uVar3 = 0xc;
  }
  puVar1 = (uint *)(param_2 - 4);
  uVar5 = *puVar1 & 0xfffffffe;
  if (uVar5 < uVar3) {
    uVar3 = uVar3 - uVar5;
    puVar6 = (uint *)((int)puVar1 + uVar5);
    while( true ) {
      *param_1 = uVar3;
      uVar5 = *puVar6;
      if (uVar5 == 0xffffffff) break;
      if ((uVar5 & 1) != 0) {
        return 1;
      }
      uVar3 = puVar6[2];
      uVar2 = puVar6[1];
      uVar4 = DAT_0040e864;
      if (in_DS == in_AX) {
        for (; (unaff_ESI = uVar4, *(uint *)(uVar4 + 8) != 0 &&
               ((param_2 < uVar4 || (*(uint *)(uVar4 + 8) <= param_2))));
            uVar4 = *(uint *)(uVar4 + 8)) {
        }
      }
      if (puVar6 == *(uint **)(unaff_ESI + 0xc)) {
        *(uint *)(unaff_ESI + 0xc) = (*(uint **)(unaff_ESI + 0xc))[1];
      }
      if (*param_1 <= uVar5) {
        uVar4 = uVar5 - *param_1;
        if (0xb < uVar4) {
          puVar6 = (uint *)((int)puVar6 + *param_1);
          *puVar6 = uVar4;
          puVar6[1] = uVar2;
          puVar6[2] = uVar3;
          *(uint **)(uVar2 + 8) = puVar6;
          *(uint **)(uVar3 + 4) = puVar6;
          *puVar1 = *puVar1 + *param_1;
          DAT_004104e9 = 0;
          return 0;
        }
      }
      *(uint *)(uVar2 + 8) = uVar3;
      *(uint *)(uVar3 + 4) = uVar2;
      *puVar1 = *puVar1 + uVar5;
      *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
      DAT_004104e9 = 0;
      if (*param_1 <= uVar5) goto LAB_004093da;
      uVar3 = *param_1 - uVar5;
      puVar6 = (uint *)((int)puVar6 + uVar5);
    }
    uVar7 = 2;
  }
  else {
    if (0xb < uVar5 - uVar3) {
      *puVar1 = uVar3 | 1;
      *(uint *)((int)puVar1 + uVar3) = uVar5 - uVar3 | 1;
      uVar3 = DAT_0040e864;
      if (in_DS == in_AX) {
        for (; (unaff_ESI = uVar3, *(uint *)(uVar3 + 8) != 0 &&
               ((param_2 < uVar3 || (*(uint *)(uVar3 + 8) <= param_2))));
            uVar3 = *(uint *)(uVar3 + 8)) {
        }
      }
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + 1;
      FUN_0040650f();
    }
LAB_004093da:
    uVar7 = 0;
  }
  return uVar7;
}


/*
 * FUN_004093f4 at 004093f4
 * undefined4 __stdcall FUN_004093f4(void)
 * Address ranges: 004093f4-004093f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_004093f4(void)

{
  return 0;
}


/*
 * FUN_004093fe at 004093fe
 * undefined __stdcall FUN_004093fe(void)
 * Address ranges: 004093fe-00409404
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_004093fe(void)

{
  (*(code *)PTR_FUN_0040f0d8)();
  return;
}


/*
 * FUN_00409405 at 00409405
 * undefined __stdcall FUN_00409405(void)
 * Address ranges: 00409405-0040940b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00409405(void)

{
  (*(code *)PTR_FUN_0040f0dc)();
  return;
}


/*
 * FUN_00409450 at 00409450
 * undefined4 __fastcall FUN_00409450(undefined4 param_1, undefined1 param_2)
 * Address ranges: 00409450-00409467
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00409450(undefined4 param_1,undefined1 param_2)

{
  undefined4 in_EAX;
  uint unaff_EBX;
  
  FUN_00409640(unaff_EBX,CONCAT31(CONCAT21(CONCAT11(param_2,param_2),param_2),param_2));
  return in_EAX;
}


/*
 * FUN_00409468 at 00409468
 * undefined4 __fastcall FUN_00409468(undefined4 param_1, undefined2 param_2)
 * Address ranges: 00409468-00409479;0040948b-0040948d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00409468(undefined4 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (DAT_0040f0e0 != '\0') {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}


/*
 * FUN_0040948e at 0040948e
 * undefined __cdecl FUN_0040948e(undefined4 * param_1)
 * Address ranges: 0040948e-00409539
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_0040948e(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  longlong lVar5;
  undefined4 uStackY_24;
  
  pcVar1 = (code *)*param_1;
  uVar2 = *(undefined4 *)param_1[5];
  if (DAT_004104e0 == 0) {
    iVar3 = -(DAT_0040f0c0 + 3U & 0xfffffffc);
    *(undefined4 *)(&stack0xffffffe0 + iVar3) = 0x4094ce;
    FUN_00409450(param_1,0);
    *(undefined4 *)(&stack0xffffffe0 + iVar3) = 0x4094d5;
    lVar5 = FUN_00408937(extraout_ECX,extraout_EDX);
    if ((int)lVar5 == 0) {
      *(undefined4 *)(&stack0xffffffe0 + iVar3) = uVar2;
      *(undefined4 *)((int)&uStackY_24 + iVar3) = 0x4094e2;
      CloseHandle(*(HANDLE *)(&stack0xffffffe0 + iVar3));
      return;
    }
  }
  iVar3 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined4 *)(iVar3 + 0xde) = uVar2;
  iVar3 = 0;
  if (*(int *)(extraout_ECX_00 + 0xc) != 0) {
    iVar3 = ((uint)(&stack0x00000fe3 + -*(int *)(extraout_ECX_00 + 0xc)) >> 8 & 0xfffff0) << 8;
  }
  piVar4 = (int *)(*(code *)PTR_FUN_0040ef44)();
  *piVar4 = iVar3;
  uStackY_24 = 0x40951c;
  SetEvent(*(HANDLE *)(extraout_ECX_01 + 0x10));
  FUN_004084f5(extraout_ECX_02,extraout_EDX_00);
  (*(code *)PTR_FUN_0040ef84)();
  (*pcVar1)();
  FUN_004093fe();
  return;
}


/*
 * FUN_0040953a at 0040953a
 * undefined FUN_0040953a(void)
 * Address ranges: 0040953a-0040960d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


DWORD __fastcall FUN_0040953a(undefined4 param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBX;
  uint dwStackSize;
  undefined8 uVar1;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  char acStack_48 [24];
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  HANDLE pvStack_28;
  uint uStack_24;
  HANDLE pvStack_20;
  HANDLE *ppvStack_1c;
  HANDLE pvStack_18;
  DWORD DStack_14;
  
  if (DAT_0040ef40 == -1) {
    uVar1 = FUN_004088eb(param_1,0xffffffff);
    if ((int)uVar1 == 0) {
      return (int)((ulonglong)uVar1 >> 0x20);
    }
    FUN_004089fb();
    param_1 = extraout_ECX;
  }
  uStack_2c = param_1;
  pvStack_28 = GetCurrentThread();
  dwStackSize = unaff_EBX + 0xfffU & 0xfffff000;
  uStack_50 = DAT_0040e614;
  uStack_4c = DAT_0040e618;
  acStack_48[0] = DAT_0040e61c;
  uStack_24 = dwStackSize;
  GetCurrentThreadId();
  FUN_00409752(extraout_ECX_00,acStack_48);
  pvStack_20 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)&uStack_50);
  ppvStack_1c = &pvStack_18;
  pvStack_18 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,dwStackSize,FUN_0040948e,auStack_30,0,
                            &DStack_14);
  if (pvStack_18 == (HANDLE)0x0) {
    DStack_14 = 0xffffffff;
  }
  else {
    WaitForSingleObject(pvStack_20,0xffffffff);
  }
  CloseHandle(pvStack_20);
  return DStack_14;
}


/*
 * FUN_0040960e at 0040960e
 * undefined __fastcall FUN_0040960e(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0040960e-00409634
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_0040960e(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  (*(code *)PTR_FUN_0040ef88)(param_2,param_1);
  FUN_00408533(extraout_ECX,extraout_EDX);
  if (DAT_004104e0 == 0) {
    FUN_00408984();
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}


/*
 * FUN_00409640 at 00409640
 * undefined __fastcall FUN_00409640(uint param_1, uint param_2)
 * Address ranges: 00409640-00409670
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00409640(uint param_1,uint param_2)

{
  undefined1 *in_EAX;
  undefined1 *puVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined6 uVar4;
  
  if (param_1 != 0) {
    do {
      if (((uint)in_EAX & 3) == 0) break;
      *in_EAX = (char)param_2;
      in_EAX = in_EAX + 1;
      param_2 = param_2 >> 8 | param_2 << 0x18;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
    uVar4 = FUN_00409677(param_1 >> 2,param_2);
    puVar1 = (undefined1 *)uVar4;
    uVar2 = param_1 & 3;
    if (uVar2 != 0) {
      uVar3 = (undefined1)((uint6)uVar4 >> 0x20);
      *puVar1 = uVar3;
      if ((uVar2 != 1) && (puVar1[1] = (char)((uint6)uVar4 >> 0x28), uVar2 != 2)) {
        puVar1[2] = uVar3;
      }
    }
  }
  return;
}


/*
 * FUN_00409677 at 00409677
 * undefined __fastcall FUN_00409677(uint param_1, undefined4 param_2)
 * Address ranges: 00409677-004096e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00409677(uint param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    do {
      if (((uint)in_EAX & 0x1f) == 0) break;
      *in_EAX = param_2;
      in_EAX = in_EAX + 1;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
    if (param_1 >> 2 != 0) {
      iVar2 = (param_1 >> 2) - 1;
      if (iVar2 != 0) {
        do {
          puVar1 = in_EAX;
          *puVar1 = param_2;
          puVar1[1] = param_2;
          puVar1[2] = param_2;
          puVar1[3] = param_2;
          if (iVar2 == 1) goto LAB_004096b6;
          puVar1[4] = param_2;
          puVar1[5] = param_2;
          iVar2 = iVar2 + -2;
          puVar1[6] = param_2;
          puVar1[7] = param_2;
          in_EAX = puVar1 + 8;
        } while (iVar2 != 0);
        puVar1 = puVar1 + 4;
LAB_004096b6:
        in_EAX = puVar1 + 4;
      }
      *in_EAX = param_2;
      in_EAX[1] = param_2;
      in_EAX[2] = param_2;
      in_EAX[3] = param_2;
      in_EAX = in_EAX + 4;
    }
    uVar3 = param_1 & 3;
    if (uVar3 != 0) {
      *in_EAX = param_2;
      if (uVar3 != 1) {
        in_EAX[1] = param_2;
        if (uVar3 != 2) {
          in_EAX[2] = param_2;
        }
      }
    }
  }
  return;
}


/*
 * FUN_00409708 at 00409708
 * char * __fastcall FUN_00409708(undefined4 param_1, char * param_2)
 * Address ranges: 00409708-00409751
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


char * __fastcall FUN_00409708(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint in_EAX;
  uint uVar2;
  char *pcVar3;
  uint unaff_EBX;
  char *pcVar4;
  char local_37 [35];
  
  pcVar3 = local_37;
  do {
    uVar2 = in_EAX / unaff_EBX;
    *pcVar3 = "0123456789abcdefghijklmnopqrstuvwxyz"[in_EAX % unaff_EBX];
    pcVar3 = pcVar3 + 1;
    in_EAX = uVar2;
    pcVar4 = param_2;
  } while (uVar2 != 0);
  do {
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return param_2;
}


/*
 * FUN_00409752 at 00409752
 * undefined4 __fastcall FUN_00409752(undefined4 param_1, char * param_2)
 * Address ranges: 00409752-0040976c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_00409752(undefined4 param_1,char *param_2)

{
  int in_EAX;
  undefined4 extraout_ECX;
  char *pcVar1;
  int unaff_EBX;
  
  pcVar1 = param_2;
  if ((unaff_EBX == 10) && (in_EAX < 0)) {
    *param_2 = '-';
    pcVar1 = param_2 + 1;
  }
  FUN_00409708(param_2,pcVar1);
  return extraout_ECX;
}


/*
 * FUN_00409800 at 00409800
 * int __stdcall FUN_00409800(void)
 * Address ranges: 00409800-00409893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


int FUN_00409800(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint unaff_EBP;
  uint uVar4;
  uint *unaff_ESI;
  int *unaff_EDI;
  int *piVar5;
  int *piStack_8;
  
  iVar3 = -0x80000000;
  piStack_8 = (int *)0xfffffffe;
  while( true ) {
    while( true ) {
      piVar5 = unaff_EDI;
      DAT_0040e9c0 = DAT_0040e9c0 - 1;
      uVar4 = unaff_EBP;
      if (DAT_0040e9c0 == 0) {
        uVar4 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = 0x20;
      }
      bVar1 = DAT_0040e9c0;
      unaff_EBP = uVar4 >> 1;
      if ((uVar4 & 1) == 0) break;
      if (piStack_8 == (int *)0xfffffffe) {
        unaff_EDI = piVar5 + 1;
        piStack_8 = piVar5;
      }
      else {
        unaff_EDI = piVar5 + 1;
        piStack_8 = piVar5;
      }
    }
    if (piStack_8 == (int *)0xffffffff) break;
    bVar2 = (byte)unaff_EBP;
    if (DAT_0040e9c0 < 9) {
      DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
      uVar4 = *unaff_ESI;
      bVar2 = bVar2 | (byte)(uVar4 << (bVar1 - 1 & 0x1f));
      unaff_ESI = unaff_ESI + 1;
      unaff_EBP = uVar4 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
    }
    else {
      DAT_0040e9c0 = DAT_0040e9c0 - 8;
      unaff_EBP = uVar4 >> 9;
    }
    iVar3 = CONCAT31((int3)((uint)iVar3 >> 8),bVar2);
    *piVar5 = iVar3;
    unaff_EDI = piVar5 + 1;
    if (piStack_8 != (int *)0xfffffffe) {
      *piStack_8 = (int)unaff_EDI - (int)piStack_8;
    }
  }
  return iVar3;
}


/*
 * FUN_004098a0 at 004098a0
 * undefined __fastcall FUN_004098a0(undefined4 param_1, int * param_2)
 * Address ranges: 004098a0-00409b83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_004098a0(undefined4 param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint unaff_EBP;
  uint uVar8;
  uint *unaff_ESI;
  int *unaff_EDI;
  int *piVar9;
  int *piStack_8;
  
  bVar3 = DAT_0040e9c0;
  bVar2 = (byte)unaff_EBP;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar2 = bVar2 | (byte)(uVar8 << (bVar3 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = unaff_EBP >> 8;
  }
  bVar1 = DAT_0040e9c0;
  bVar3 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar3 = bVar3 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  DAT_0040eae0 = CONCAT11(bVar3,bVar2);
  bVar2 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar2 = bVar2 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  bVar3 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar3 = bVar3 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  DAT_0040eae2 = CONCAT11(bVar3,bVar2);
  bVar2 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar2 = bVar2 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  bVar1 = DAT_0040e9c0;
  bVar3 = (byte)uVar8;
  if (DAT_0040e9c0 < 9) {
    DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
    uVar8 = *unaff_ESI;
    bVar3 = bVar3 | (byte)(uVar8 << (bVar1 - 1 & 0x1f));
    unaff_ESI = unaff_ESI + 1;
    uVar8 = uVar8 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 - 8;
    uVar8 = uVar8 >> 8;
  }
  DAT_0040eae4 = CONCAT11(bVar3,bVar2);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  piStack_8 = (int *)0xfffffffe;
  piVar9 = piStack_8;
  while( true ) {
    while( true ) {
      piStack_8 = piVar9;
      piVar9 = unaff_EDI;
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      uVar5 = uVar8;
      if (DAT_0040e9c0 == '\0') {
        uVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = ' ';
      }
      uVar8 = uVar5 >> 1;
      if ((uVar5 & 1) == 0) break;
      if (piStack_8 == (int *)0xfffffffe) {
        unaff_EDI = piVar9 + 1;
      }
      else {
        unaff_EDI = piVar9 + 1;
      }
    }
    if (piStack_8 == (int *)0xffffffff) break;
    uVar5 = *DAT_0040e98c;
    puVar7 = DAT_0040e98c;
    while ((uVar5 & 0x80000000) == 0) {
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar8 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = ' ';
      }
      if ((uVar8 & 1) == 0) {
        uVar5 = 4;
      }
      puVar7 = (uint *)((int)puVar7 + uVar5);
      uVar8 = uVar8 >> 1;
      uVar5 = *puVar7;
    }
    uVar6 = *DAT_0040e990;
    puVar7 = DAT_0040e990;
    while ((uVar6 & 0x80000000) == 0) {
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar8 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        DAT_0040e9c0 = ' ';
      }
      if ((uVar8 & 1) == 0) {
        uVar6 = 4;
      }
      puVar7 = (uint *)((int)puVar7 + uVar6);
      uVar8 = uVar8 >> 1;
      uVar6 = *puVar7;
    }
    uVar4 = (short)uVar6 << 8 | (ushort)((uVar5 << 0x18) >> 0x18);
    if (DAT_0040eae0 == uVar4) {
      uVar4 = 0;
      param_2[1] = (int)piVar9;
    }
    else if (DAT_0040eae2 == uVar4) {
      uVar4 = 0;
      param_2[2] = (int)piVar9;
    }
    else if (DAT_0040eae4 == uVar4) {
      uVar4 = 0;
      param_2[3] = (int)piVar9;
    }
    *piVar9 = CONCAT31((int3)(((uint)uVar4 << 0x10) >> 8),1);
    unaff_EDI = piVar9 + 1;
    piVar9 = param_2;
    if (piStack_8 != (int *)0xfffffffe) {
      *piStack_8 = ((int)unaff_EDI - (int)piStack_8) * 0x2000;
      piVar9 = param_2;
    }
  }
  if (param_2[1] == 0) {
    param_2[1] = (int)piVar9;
  }
  if (param_2[2] == 0) {
    piVar9 = piVar9 + 1;
    param_2[2] = (int)piVar9;
  }
  if (param_2[3] == 0) {
    param_2[3] = (int)(piVar9 + 1);
  }
  return;
}


/*
 * FUN_00409b90 at 00409b90
 * undefined __fastcall FUN_00409b90(undefined4 param_1, uint * param_2)
 * Address ranges: 00409b90-00409bfb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00409b90(undefined4 param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int unaff_EDI;
  
  iVar6 = DAT_0040e9b4;
  DAT_0040e978 = param_2;
  do {
    uVar2 = (short)iVar6 - 1;
    uVar5 = *DAT_0040e978;
    puVar4 = DAT_0040e978;
    cVar3 = DAT_0040e9b0;
    while (((uVar5 & 0xffff) == 0 && (uVar5 = uVar5 >> 0xd & 0xffff8, cVar3 != '\0'))) {
      cVar3 = cVar3 + -1;
      uVar1 = uVar2 & 1;
      uVar2 = uVar2 >> 1;
      if (uVar1 == 0) {
        uVar5 = 4;
      }
      puVar4 = (uint *)((int)puVar4 + uVar5);
      uVar5 = *puVar4;
    }
    *(uint *)(unaff_EDI + -4 + iVar6 * 4) =
         CONCAT31((int3)puVar4 - (int3)_DAT_0040e9a4,-(cVar3 - DAT_0040e9b0));
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


/*
 * FUN_00409c00 at 00409c00
 * undefined __fastcall FUN_00409c00(undefined4 param_1, int * param_2)
 * Address ranges: 00409c00-00409c84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __fastcall FUN_00409c00(undefined4 param_1,int *param_2)

{
  uint *in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint unaff_EBP;
  uint uVar1;
  uint uVar2;
  uint *unaff_ESI;
  
  DAT_0040e9c0 = DAT_0040e9c0 + -1;
  if (DAT_0040e9c0 == '\0') {
    unaff_EBP = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    DAT_0040e9c0 = ' ';
  }
  uVar1 = unaff_EBP >> 1;
  if ((unaff_EBP & 1) == 0) {
    *param_2 = 0;
    param_2[1] = (int)in_EAX;
    param_2[2] = (int)in_EAX;
    param_2[3] = (int)in_EAX;
  }
  else {
    DAT_0040e9c0 = DAT_0040e9c0 + -1;
    if (DAT_0040e9c0 == '\0') {
      uVar1 = *unaff_ESI;
      unaff_ESI = unaff_ESI + 1;
      DAT_0040e9c0 = ' ';
    }
    uVar2 = uVar1 >> 1;
    if ((uVar1 & 1) != 0) {
      FUN_00409800();
      param_1 = extraout_ECX;
    }
    DAT_0040e9c0 = DAT_0040e9c0 + -1;
    if (DAT_0040e9c0 == '\0') {
      uVar2 = *unaff_ESI;
      DAT_0040e9c0 = ' ';
    }
    if ((uVar2 & 1) != 0) {
      FUN_00409800();
      param_1 = extraout_ECX_00;
    }
    FUN_004098a0(param_1,param_2);
    FUN_00409b90(extraout_ECX_01,in_EAX);
  }
  return;
}


/*
 * FUN_00409c90 at 00409c90
 * undefined4 __stdcall FUN_00409c90(void)
 * Address ranges: 00409c90-00409c95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 FUN_00409c90(void)

{
  return 0x7468;
}


/*
 * FUN_00409ca0 at 00409ca0
 * undefined __thiscall FUN_00409ca0(void * this, int * param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 00409ca0-00409f10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00409ca0(void *this,int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  
  DAT_0040ef00 = param_1;
  DAT_0040ef04 = param_2;
  DAT_0040ef08 = param_3;
  DAT_0040ef0c = param_4;
  DAT_0040ef10 = param_5;
  DAT_0040ef14 = param_6;
  DAT_0040e98c = param_1;
  DAT_0040e990 = param_1 + 0x200;
  DAT_0040e9c0 = 1;
  _DAT_0040e9b0 = 0xb;
  DAT_0040e9b4 = 0x800;
  _DAT_0040e9a4 = param_2;
  FUN_00409c00(this,&DAT_0040e910);
  _DAT_0040e9b0 = 10;
  DAT_0040e9b4 = 0x400;
  FUN_00409c00(extraout_ECX,&DAT_0040e920);
  _DAT_0040e9b0 = 0xc;
  DAT_0040e9b4 = 0x1000;
  FUN_00409c00(extraout_ECX_00,(int *)&DAT_0040e930);
  _DAT_0040e9b0 = 8;
  DAT_0040e9b4 = 0x100;
  FUN_00409c00(extraout_ECX_01,(int *)&DAT_0040e940);
  puVar5 = DAT_0040ef04;
  *DAT_0040ef04 = DAT_0040ef08;
  puVar5[1] = DAT_0040ef0c;
  puVar5[2] = DAT_0040ef10;
  puVar5[3] = DAT_0040ef14;
  puVar4 = &DAT_0040e910;
  puVar5 = puVar5 + 0x1d05;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  piVar7 = DAT_0040ef00;
  for (iVar3 = 0x800; piVar6 = DAT_0040ef00, iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  FUN_00409fe0();
  FUN_00409fe0();
  FUN_00409fe0();
  FUN_00409fe0();
  iVar3 = 0x800;
  do {
    piVar7 = piVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    piVar7 = piVar6 + 1;
    iVar1 = *piVar6;
    piVar6 = piVar7;
  } while (iVar1 == -1);
  uVar2 = piVar7[-1] ^ 0xffffffff;
  iVar3 = 0;
  if (uVar2 != 0) {
    for (; (uVar2 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
    }
  }
  DAT_0040e9d0._0_2_ = ((short)(piVar7 + -1) - (short)DAT_0040ef00) * 8 + (short)iVar3;
  *(short *)(DAT_0040ef04 + 0x1d04) = (short)DAT_0040e9d0;
  FUN_0040a010();
  FUN_0040a010();
  FUN_0040a010();
  FUN_0040a010();
  return;
}


/*
 * FUN_00409fe0 at 00409fe0
 * undefined __stdcall FUN_00409fe0(void)
 * Address ranges: 00409fe0-0040a00f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_00409fe0(void)

{
  byte *pbVar1;
  uint in_EAX;
  uint uVar2;
  int unaff_ESI;
  byte *pbVar3;
  int unaff_EDI;
  
  pbVar3 = (byte *)(unaff_ESI + 0x7468);
  uVar2 = in_EAX >> 2;
  do {
    while ((*pbVar3 & 1) == 0) {
      pbVar3 = pbVar3 + 4;
      uVar2 = uVar2 - 1;
      if (uVar2 == 0) {
        return;
      }
    }
    pbVar1 = (byte *)(unaff_EDI + (uint)(*(ushort *)(pbVar3 + 2) >> 3));
    *pbVar1 = *pbVar1 | '\x01' << ((byte)*(ushort *)(pbVar3 + 2) & 7);
    pbVar3 = pbVar3 + 4;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}


/*
 * FUN_0040a010 at 0040a010
 * undefined __stdcall FUN_0040a010(void)
 * Address ranges: 0040a010-0040a03f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void FUN_0040a010(void)

{
  undefined2 uVar1;
  uint in_EAX;
  uint uVar2;
  int unaff_ESI;
  byte *pbVar3;
  
  uVar1 = (undefined2)DAT_0040e9d0;
  pbVar3 = (byte *)(unaff_ESI + 0x7468);
  uVar2 = in_EAX >> 2;
  do {
    while ((*pbVar3 & 1) == 0) {
      *(undefined2 *)pbVar3 = uVar1;
      pbVar3 = pbVar3 + 4;
      uVar2 = uVar2 - 1;
      if (uVar2 == 0) {
        return;
      }
    }
    *(undefined2 *)pbVar3 = *(undefined2 *)(pbVar3 + 2);
    pbVar3 = pbVar3 + 4;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}


/*
 * FUN_0040ad60 at 0040ad60
 * undefined FUN_0040ad60(void)
 * Address ranges: 0040ad60-0040ad6b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ad60(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040ad6c at 0040ad6c
 * undefined FUN_0040ad6c(void)
 * Address ranges: 0040ad6c-0040ad77
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ad6c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040ad78 at 0040ad78
 * undefined FUN_0040ad78(void)
 * Address ranges: 0040ad78-0040ad83
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ad78(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040ad84 at 0040ad84
 * undefined FUN_0040ad84(void)
 * Address ranges: 0040ad84-0040ad8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ad84(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT31((uint3)bVar1 | (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8)
                  ,bVar1);
}


/*
 * FUN_0040ad90 at 0040ad90
 * undefined FUN_0040ad90(void)
 * Address ranges: 0040ad90-0040ad9e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ad90(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040ada0 at 0040ada0
 * undefined FUN_0040ada0(void)
 * Address ranges: 0040ada0-0040adae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ada0(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040adb0 at 0040adb0
 * undefined FUN_0040adb0(void)
 * Address ranges: 0040adb0-0040adbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040adb0(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar2 = (ushort)((uint)param_2 >> 0x10);
  uVar1 = (undefined1)param_2;
  return CONCAT22(uVar2 >> 8 |
                  (ushort)((uint)(CONCAT22(uVar2,CONCAT11(uVar1,uVar1)) << 0x18) >> 0x10),
                  CONCAT11((char)((uint)param_2 >> 0x18),uVar1));
}


/*
 * FUN_0040adc0 at 0040adc0
 * undefined FUN_0040adc0(void)
 * Address ranges: 0040adc0-0040adce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040adc0(undefined4 param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT22((ushort)bVar1 | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(bVar1,(char)((uint)param_2 >> 8)));
}


/*
 * FUN_0040add0 at 0040add0
 * undefined FUN_0040add0(void)
 * Address ranges: 0040add0-0040addb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040add0(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040addc at 0040addc
 * undefined FUN_0040addc(void)
 * Address ranges: 0040addc-0040ade7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040addc(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((int3)(CONCAT22((short)((uint)param_2 >> 0x10),
                                  CONCAT11((char)param_2,(char)param_2)) >> 8),
                  (char)((uint)param_2 >> 0x18));
}


/*
 * FUN_0040ade8 at 0040ade8
 * undefined FUN_0040ade8(void)
 * Address ranges: 0040ade8-0040adf3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ade8(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040adf4 at 0040adf4
 * undefined FUN_0040adf4(void)
 * Address ranges: 0040adf4-0040adff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040adf4(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040ae00 at 0040ae00
 * undefined FUN_0040ae00(void)
 * Address ranges: 0040ae00-0040ae0e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae00(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2)) >>
                 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 0x18)) << 0x18;
}


/*
 * FUN_0040ae10 at 0040ae10
 * undefined FUN_0040ae10(void)
 * Address ranges: 0040ae10-0040ae1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae10(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040ae20 at 0040ae20
 * undefined FUN_0040ae20(void)
 * Address ranges: 0040ae20-0040ae2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae20(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040ae30 at 0040ae30
 * undefined FUN_0040ae30(void)
 * Address ranges: 0040ae30-0040ae3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ae30(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (byte)((uint)param_2 >> 8);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT22((ushort)bVar1 | (ushort)(((uint)bVar2 << 0x18) >> 0x10),CONCAT11(bVar1,bVar2));
}


/*
 * FUN_0040ae40 at 0040ae40
 * undefined FUN_0040ae40(void)
 * Address ranges: 0040ae40-0040ae4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ae40(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT31((int3)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(uVar1,uVar1)),uVar1);
}


/*
 * FUN_0040ae4c at 0040ae4c
 * undefined FUN_0040ae4c(void)
 * Address ranges: 0040ae4c-0040ae55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae4c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040ae58 at 0040ae58
 * undefined FUN_0040ae58(void)
 * Address ranges: 0040ae58-0040ae64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae58(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040ae68 at 0040ae68
 * undefined FUN_0040ae68(void)
 * Address ranges: 0040ae68-0040ae73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ae68(undefined4 param_1,undefined4 param_2)

{
  return CONCAT22((short)(CONCAT22((short)((uint)param_2 >> 0x10),
                                   CONCAT11((char)param_2,(char)param_2)) >> 8),
                  CONCAT11((char)((uint)param_2 >> 8),(char)((uint)param_2 >> 0x18)));
}


/*
 * FUN_0040ae74 at 0040ae74
 * undefined FUN_0040ae74(void)
 * Address ranges: 0040ae74-0040ae80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae74(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040ae84 at 0040ae84
 * undefined FUN_0040ae84(void)
 * Address ranges: 0040ae84-0040ae90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ae84(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040ae94 at 0040ae94
 * undefined FUN_0040ae94(void)
 * Address ranges: 0040ae94-0040aea2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ae94(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return CONCAT22(uVar1 >> 8 |
                  (ushort)((uint)(CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x18) >>
                          0x10),(short)param_2);
}


/*
 * FUN_0040aea4 at 0040aea4
 * undefined FUN_0040aea4(void)
 * Address ranges: 0040aea4-0040aeb0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040aea4(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040aeb4 at 0040aeb4
 * undefined FUN_0040aeb4(void)
 * Address ranges: 0040aeb4-0040aebd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040aeb4(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040aec0 at 0040aec0
 * undefined FUN_0040aec0(void)
 * Address ranges: 0040aec0-0040aecb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040aec0(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),(char)((uint)param_2 >> 8))
  ;
}


/*
 * FUN_0040aecc at 0040aecc
 * undefined FUN_0040aecc(void)
 * Address ranges: 0040aecc-0040aed5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040aecc(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040aed8 at 0040aed8
 * undefined FUN_0040aed8(void)
 * Address ranges: 0040aed8-0040aee1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040aed8(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040aee4 at 0040aee4
 * undefined FUN_0040aee4(void)
 * Address ranges: 0040aee4-0040aef2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040aee4(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040aef4 at 0040aef4
 * undefined FUN_0040aef4(void)
 * Address ranges: 0040aef4-0040af00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040aef4(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040af04 at 0040af04
 * undefined FUN_0040af04(void)
 * Address ranges: 0040af04-0040af10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040af04(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040af14 at 0040af14
 * undefined FUN_0040af14(void)
 * Address ranges: 0040af14-0040af22
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040af14(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040af24 at 0040af24
 * undefined FUN_0040af24(void)
 * Address ranges: 0040af24-0040af2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040af24(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040af30 at 0040af30
 * undefined FUN_0040af30(void)
 * Address ranges: 0040af30-0040af3c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040af30(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040af40 at 0040af40
 * undefined FUN_0040af40(void)
 * Address ranges: 0040af40-0040af49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040af40(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040af4c at 0040af4c
 * undefined FUN_0040af4c(void)
 * Address ranges: 0040af4c-0040af57
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040af4c(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((uint3)(byte)((uint)param_2 >> 0x18) |
                  (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8),
                  (char)((uint)param_2 >> 8));
}


/*
 * FUN_0040af58 at 0040af58
 * undefined FUN_0040af58(void)
 * Address ranges: 0040af58-0040af64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040af58(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040af68 at 0040af68
 * undefined FUN_0040af68(void)
 * Address ranges: 0040af68-0040af74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040af68(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040af78 at 0040af78
 * undefined FUN_0040af78(void)
 * Address ranges: 0040af78-0040af86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040af78(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return CONCAT22(uVar1 >> 8 |
                  (ushort)((uint)(CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x18) >>
                          0x10),(short)param_2);
}


/*
 * FUN_0040af88 at 0040af88
 * undefined FUN_0040af88(void)
 * Address ranges: 0040af88-0040af94
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040af88(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040af98 at 0040af98
 * undefined FUN_0040af98(void)
 * Address ranges: 0040af98-0040afa1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040af98(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040afa4 at 0040afa4
 * undefined FUN_0040afa4(void)
 * Address ranges: 0040afa4-0040afaf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040afa4(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),(char)((uint)param_2 >> 8))
  ;
}


/*
 * FUN_0040afb0 at 0040afb0
 * undefined FUN_0040afb0(void)
 * Address ranges: 0040afb0-0040afb9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040afb0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040afbc at 0040afbc
 * undefined FUN_0040afbc(void)
 * Address ranges: 0040afbc-0040afc5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040afbc(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040afc8 at 0040afc8
 * undefined FUN_0040afc8(void)
 * Address ranges: 0040afc8-0040afd6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040afc8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040afd8 at 0040afd8
 * undefined FUN_0040afd8(void)
 * Address ranges: 0040afd8-0040afe4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040afd8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040afe8 at 0040afe8
 * undefined FUN_0040afe8(void)
 * Address ranges: 0040afe8-0040aff4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040afe8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040aff8 at 0040aff8
 * undefined FUN_0040aff8(void)
 * Address ranges: 0040aff8-0040b006
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040aff8(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b008 at 0040b008
 * undefined FUN_0040b008(void)
 * Address ranges: 0040b008-0040b013
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b008(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 0x10);
  return CONCAT22(CONCAT11((char)param_2,(char)param_2),CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b014 at 0040b014
 * undefined FUN_0040b014(void)
 * Address ranges: 0040b014-0040b01f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b014(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b020 at 0040b020
 * undefined FUN_0040b020(void)
 * Address ranges: 0040b020-0040b02b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b020(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b02c at 0040b02c
 * undefined FUN_0040b02c(void)
 * Address ranges: 0040b02c-0040b037
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b02c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}


/*
 * FUN_0040b038 at 0040b038
 * undefined FUN_0040b038(void)
 * Address ranges: 0040b038-0040b047
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b038(undefined4 param_1,undefined3 param_2)

{
  return CONCAT31(param_2,(char)param_2);
}


/*
 * FUN_0040b048 at 0040b048
 * undefined FUN_0040b048(void)
 * Address ranges: 0040b048-0040b055
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b048(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b058 at 0040b058
 * undefined FUN_0040b058(void)
 * Address ranges: 0040b058-0040b065
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b058(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b068 at 0040b068
 * undefined FUN_0040b068(void)
 * Address ranges: 0040b068-0040b077
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __fastcall FUN_0040b068(undefined4 param_1,undefined4 param_2)

{
  return (char)((uint)param_2 >> 0x18);
}


/*
 * FUN_0040b078 at 0040b078
 * undefined FUN_0040b078(void)
 * Address ranges: 0040b078-0040b083
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b078(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b084 at 0040b084
 * undefined FUN_0040b084(void)
 * Address ranges: 0040b084-0040b08f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b084(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),(char)((uint)param_2 >> 8))
  ;
}


/*
 * FUN_0040b090 at 0040b090
 * undefined FUN_0040b090(void)
 * Address ranges: 0040b090-0040b09b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b090(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b09c at 0040b09c
 * undefined FUN_0040b09c(void)
 * Address ranges: 0040b09c-0040b0a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b09c(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b0a8 at 0040b0a8
 * undefined FUN_0040b0a8(void)
 * Address ranges: 0040b0a8-0040b0b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b0a8(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = (ushort)((uint)param_2 >> 0x10);
  uVar1 = CONCAT22(uVar2,CONCAT11((char)param_2,(char)((uint)param_2 >> 8)));
  return (uVar1 & 0xffffff) >> 8 | ((uint)(uVar2 >> 8) | uVar1 << 8) << 0x10;
}


/*
 * FUN_0040b0b8 at 0040b0b8
 * undefined FUN_0040b0b8(void)
 * Address ranges: 0040b0b8-0040b0c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b0b8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b0c8 at 0040b0c8
 * undefined FUN_0040b0c8(void)
 * Address ranges: 0040b0c8-0040b0d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b0c8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b0d8 at 0040b0d8
 * undefined FUN_0040b0d8(void)
 * Address ranges: 0040b0d8-0040b0e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b0d8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8));
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(iVar1 << 0x18) >> 0x10),
                  (short)iVar1);
}


/*
 * FUN_0040b0e8 at 0040b0e8
 * undefined FUN_0040b0e8(void)
 * Address ranges: 0040b0e8-0040b0f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b0e8(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b0f8 at 0040b0f8
 * undefined FUN_0040b0f8(void)
 * Address ranges: 0040b0f8-0040b104
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b0f8(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b108 at 0040b108
 * undefined FUN_0040b108(void)
 * Address ranges: 0040b108-0040b114
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b108(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b118 at 0040b118
 * undefined FUN_0040b118(void)
 * Address ranges: 0040b118-0040b126
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b118(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((uint3)(byte)((uint)param_2 >> 0x18) |
                  (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8),
                  (char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b128 at 0040b128
 * undefined FUN_0040b128(void)
 * Address ranges: 0040b128-0040b131
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b128(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b134 at 0040b134
 * undefined FUN_0040b134(void)
 * Address ranges: 0040b134-0040b13d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b134(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b140 at 0040b140
 * undefined FUN_0040b140(void)
 * Address ranges: 0040b140-0040b14c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b140(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b150 at 0040b150
 * undefined FUN_0040b150(void)
 * Address ranges: 0040b150-0040b159
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b150(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b15c at 0040b15c
 * undefined FUN_0040b15c(void)
 * Address ranges: 0040b15c-0040b165
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b15c(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b168 at 0040b168
 * undefined FUN_0040b168(void)
 * Address ranges: 0040b168-0040b173
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b168(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),
                  (char)((uint)param_2 >> 0x18));
}


/*
 * FUN_0040b174 at 0040b174
 * undefined FUN_0040b174(void)
 * Address ranges: 0040b174-0040b17d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b174(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b180 at 0040b180
 * undefined FUN_0040b180(void)
 * Address ranges: 0040b180-0040b189
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b180(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b18c at 0040b18c
 * undefined FUN_0040b18c(void)
 * Address ranges: 0040b18c-0040b19a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b18c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b19c at 0040b19c
 * undefined FUN_0040b19c(void)
 * Address ranges: 0040b19c-0040b1a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b19c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b1ac at 0040b1ac
 * undefined FUN_0040b1ac(void)
 * Address ranges: 0040b1ac-0040b1b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b1ac(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b1bc at 0040b1bc
 * undefined FUN_0040b1bc(void)
 * Address ranges: 0040b1bc-0040b1ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b1bc(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b1cc at 0040b1cc
 * undefined FUN_0040b1cc(void)
 * Address ranges: 0040b1cc-0040b1da
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b1cc(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b1dc at 0040b1dc
 * undefined FUN_0040b1dc(void)
 * Address ranges: 0040b1dc-0040b1e8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b1dc(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b1ec at 0040b1ec
 * undefined FUN_0040b1ec(void)
 * Address ranges: 0040b1ec-0040b1f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b1ec(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b1fc at 0040b1fc
 * undefined FUN_0040b1fc(void)
 * Address ranges: 0040b1fc-0040b209
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b1fc(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10)
                   ,(short)param_2);
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b20c at 0040b20c
 * undefined FUN_0040b20c(void)
 * Address ranges: 0040b20c-0040b215
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b20c(undefined4 param_1,undefined3 param_2)

{
  return CONCAT31(param_2,(char)param_2);
}


/*
 * FUN_0040b218 at 0040b218
 * undefined FUN_0040b218(void)
 * Address ranges: 0040b218-0040b21f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b218(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b220 at 0040b220
 * undefined FUN_0040b220(void)
 * Address ranges: 0040b220-0040b22a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b220(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b22c at 0040b22c
 * undefined FUN_0040b22c(void)
 * Address ranges: 0040b22c-0040b235
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b22c(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b238 at 0040b238
 * undefined FUN_0040b238(void)
 * Address ranges: 0040b238-0040b241
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b238(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b244 at 0040b244
 * undefined FUN_0040b244(void)
 * Address ranges: 0040b244-0040b24f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b244(undefined4 param_1,undefined4 param_2)

{
  return CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b250 at 0040b250
 * undefined FUN_0040b250(void)
 * Address ranges: 0040b250-0040b257
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b250(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b258 at 0040b258
 * undefined FUN_0040b258(void)
 * Address ranges: 0040b258-0040b261
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b258(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b264 at 0040b264
 * undefined FUN_0040b264(void)
 * Address ranges: 0040b264-0040b271
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b264(undefined4 param_1,uint param_2)

{
  return param_2 & 0xff | (uint)CONCAT12((char)(param_2 >> 0x18),(short)param_2) << 8;
}


/*
 * FUN_0040b274 at 0040b274
 * undefined FUN_0040b274(void)
 * Address ranges: 0040b274-0040b280
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b274(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b284 at 0040b284
 * undefined FUN_0040b284(void)
 * Address ranges: 0040b284-0040b290
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b284(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b294 at 0040b294
 * undefined FUN_0040b294(void)
 * Address ranges: 0040b294-0040b2a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b294(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b2a4 at 0040b2a4
 * undefined FUN_0040b2a4(void)
 * Address ranges: 0040b2a4-0040b2b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b2a4(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 0x10);
  return CONCAT22(CONCAT11((char)param_2,(char)param_2),CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b2b4 at 0040b2b4
 * undefined FUN_0040b2b4(void)
 * Address ranges: 0040b2b4-0040b2c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b2b4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b2c4 at 0040b2c4
 * undefined FUN_0040b2c4(void)
 * Address ranges: 0040b2c4-0040b2d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b2c4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b2d4 at 0040b2d4
 * undefined FUN_0040b2d4(void)
 * Address ranges: 0040b2d4-0040b2e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b2d4(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10)
                   ,(short)param_2);
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b2e4 at 0040b2e4
 * undefined FUN_0040b2e4(void)
 * Address ranges: 0040b2e4-0040b2f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b2e4(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b2f4 at 0040b2f4
 * undefined FUN_0040b2f4(void)
 * Address ranges: 0040b2f4-0040b2fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b2f4(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b300 at 0040b300
 * undefined FUN_0040b300(void)
 * Address ranges: 0040b300-0040b30a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b300(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b30c at 0040b30c
 * undefined FUN_0040b30c(void)
 * Address ranges: 0040b30c-0040b318
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b30c(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b31c at 0040b31c
 * undefined FUN_0040b31c(void)
 * Address ranges: 0040b31c-0040b328
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b31c(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b32c at 0040b32c
 * undefined FUN_0040b32c(void)
 * Address ranges: 0040b32c-0040b335
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b32c(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xffff;
}


/*
 * FUN_0040b338 at 0040b338
 * undefined FUN_0040b338(void)
 * Address ranges: 0040b338-0040b342
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b338(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b344 at 0040b344
 * undefined FUN_0040b344(void)
 * Address ranges: 0040b344-0040b350
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b344(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b354 at 0040b354
 * undefined FUN_0040b354(void)
 * Address ranges: 0040b354-0040b361
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b354(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,(short)param_2) << 8;
}


/*
 * FUN_0040b364 at 0040b364
 * undefined FUN_0040b364(void)
 * Address ranges: 0040b364-0040b373
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b364(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b374 at 0040b374
 * undefined FUN_0040b374(void)
 * Address ranges: 0040b374-0040b383
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b374(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b384 at 0040b384
 * undefined FUN_0040b384(void)
 * Address ranges: 0040b384-0040b392
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b384(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (byte)((uint)param_2 >> 8);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  return CONCAT22((ushort)bVar1 | (ushort)(((uint)bVar2 << 0x18) >> 0x10),CONCAT11(bVar1,bVar2));
}


/*
 * FUN_0040b394 at 0040b394
 * undefined FUN_0040b394(void)
 * Address ranges: 0040b394-0040b3a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b394(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 0x10);
  return CONCAT22(CONCAT11((char)param_2,(char)param_2),CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b3a4 at 0040b3a4
 * undefined FUN_0040b3a4(void)
 * Address ranges: 0040b3a4-0040b3b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b3a4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b3b4 at 0040b3b4
 * undefined FUN_0040b3b4(void)
 * Address ranges: 0040b3b4-0040b3c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b3b4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b3c4 at 0040b3c4
 * undefined FUN_0040b3c4(void)
 * Address ranges: 0040b3c4-0040b3d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b3c4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}


/*
 * FUN_0040b3d4 at 0040b3d4
 * undefined FUN_0040b3d4(void)
 * Address ranges: 0040b3d4-0040b3dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b3d4(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)((uint)param_2 >> 0x10));
}


/*
 * FUN_0040b3e0 at 0040b3e0
 * undefined FUN_0040b3e0(void)
 * Address ranges: 0040b3e0-0040b3e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b3e0(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b3ec at 0040b3ec
 * undefined FUN_0040b3ec(void)
 * Address ranges: 0040b3ec-0040b3f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b3ec(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b3fc at 0040b3fc
 * undefined FUN_0040b3fc(void)
 * Address ranges: 0040b3fc-0040b405
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b3fc(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040b408 at 0040b408
 * undefined FUN_0040b408(void)
 * Address ranges: 0040b408-0040b411
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __fastcall FUN_0040b408(undefined4 param_1,undefined1 param_2)

{
  return param_2;
}


/*
 * FUN_0040b414 at 0040b414
 * undefined FUN_0040b414(void)
 * Address ranges: 0040b414-0040b41f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b414(undefined4 param_1,undefined4 param_2)

{
  return CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b420 at 0040b420
 * undefined FUN_0040b420(void)
 * Address ranges: 0040b420-0040b429
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b420(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b42c at 0040b42c
 * undefined FUN_0040b42c(void)
 * Address ranges: 0040b42c-0040b435
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b42c(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b438 at 0040b438
 * undefined FUN_0040b438(void)
 * Address ranges: 0040b438-0040b446
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b438(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 8 |
                  (uint3)((uint)(CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b448 at 0040b448
 * undefined FUN_0040b448(void)
 * Address ranges: 0040b448-0040b454
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b448(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b458 at 0040b458
 * undefined FUN_0040b458(void)
 * Address ranges: 0040b458-0040b464
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b458(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b468 at 0040b468
 * undefined FUN_0040b468(void)
 * Address ranges: 0040b468-0040b476
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b468(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b478 at 0040b478
 * undefined FUN_0040b478(void)
 * Address ranges: 0040b478-0040b483
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b478(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b484 at 0040b484
 * undefined FUN_0040b484(void)
 * Address ranges: 0040b484-0040b48d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b484(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b490 at 0040b490
 * undefined FUN_0040b490(void)
 * Address ranges: 0040b490-0040b499
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b490(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b49c at 0040b49c
 * undefined FUN_0040b49c(void)
 * Address ranges: 0040b49c-0040b4a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b49c(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((uint3)(byte)((uint)param_2 >> 0x18) |
                  (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8),
                  (char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b4a8 at 0040b4a8
 * undefined FUN_0040b4a8(void)
 * Address ranges: 0040b4a8-0040b4b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b4a8(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b4b4 at 0040b4b4
 * undefined FUN_0040b4b4(void)
 * Address ranges: 0040b4b4-0040b4bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b4b4(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x18 | param_2 << 8;
}


/*
 * FUN_0040b4c0 at 0040b4c0
 * undefined FUN_0040b4c0(void)
 * Address ranges: 0040b4c0-0040b4cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b4c0(undefined4 param_1,undefined2 param_2)

{
  return param_2;
}


/*
 * FUN_0040b4d0 at 0040b4d0
 * undefined FUN_0040b4d0(void)
 * Address ranges: 0040b4d0-0040b4d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b4d0(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b4dc at 0040b4dc
 * undefined FUN_0040b4dc(void)
 * Address ranges: 0040b4dc-0040b4e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b4dc(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b4e4 at 0040b4e4
 * undefined FUN_0040b4e4(void)
 * Address ranges: 0040b4e4-0040b4ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b4e4(undefined4 param_1,undefined4 param_2)

{
  return CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b4f0 at 0040b4f0
 * undefined FUN_0040b4f0(void)
 * Address ranges: 0040b4f0-0040b4f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b4f0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b4f8 at 0040b4f8
 * undefined FUN_0040b4f8(void)
 * Address ranges: 0040b4f8-0040b4fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b4f8(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b500 at 0040b500
 * undefined FUN_0040b500(void)
 * Address ranges: 0040b500-0040b50b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b500(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b50c at 0040b50c
 * undefined FUN_0040b50c(void)
 * Address ranges: 0040b50c-0040b515
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b50c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b518 at 0040b518
 * undefined FUN_0040b518(void)
 * Address ranges: 0040b518-0040b521
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b518(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b524 at 0040b524
 * undefined FUN_0040b524(void)
 * Address ranges: 0040b524-0040b52f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b524(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b530 at 0040b530
 * undefined FUN_0040b530(void)
 * Address ranges: 0040b530-0040b53b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b530(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b53c at 0040b53c
 * undefined FUN_0040b53c(void)
 * Address ranges: 0040b53c-0040b548
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b53c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b54c at 0040b54c
 * undefined FUN_0040b54c(void)
 * Address ranges: 0040b54c-0040b557
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b54c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b558 at 0040b558
 * undefined FUN_0040b558(void)
 * Address ranges: 0040b558-0040b563
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b558(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}


/*
 * FUN_0040b564 at 0040b564
 * undefined FUN_0040b564(void)
 * Address ranges: 0040b564-0040b570
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b564(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b574 at 0040b574
 * undefined FUN_0040b574(void)
 * Address ranges: 0040b574-0040b57e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b574(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x18 | param_2 << 8;
}


/*
 * FUN_0040b580 at 0040b580
 * undefined FUN_0040b580(void)
 * Address ranges: 0040b580-0040b589
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b580(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b58c at 0040b58c
 * undefined FUN_0040b58c(void)
 * Address ranges: 0040b58c-0040b598
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined1 __fastcall FUN_0040b58c(undefined4 param_1,undefined4 param_2)

{
  return (char)((uint)param_2 >> 0x18);
}


/*
 * FUN_0040b59c at 0040b59c
 * undefined FUN_0040b59c(void)
 * Address ranges: 0040b59c-0040b5a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b59c(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b5a8 at 0040b5a8
 * undefined FUN_0040b5a8(void)
 * Address ranges: 0040b5a8-0040b5b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b5a8(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),(char)((uint)param_2 >> 8))
  ;
}


/*
 * FUN_0040b5b4 at 0040b5b4
 * undefined FUN_0040b5b4(void)
 * Address ranges: 0040b5b4-0040b5bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b5b4(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b5c0 at 0040b5c0
 * undefined FUN_0040b5c0(void)
 * Address ranges: 0040b5c0-0040b5c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b5c0(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b5cc at 0040b5cc
 * undefined FUN_0040b5cc(void)
 * Address ranges: 0040b5cc-0040b5d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b5cc(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)((uint)param_2 >> 8))
                  );
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b5d8 at 0040b5d8
 * undefined FUN_0040b5d8(void)
 * Address ranges: 0040b5d8-0040b5e4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b5d8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b5e8 at 0040b5e8
 * undefined FUN_0040b5e8(void)
 * Address ranges: 0040b5e8-0040b5f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b5e8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b5f4 at 0040b5f4
 * undefined FUN_0040b5f4(void)
 * Address ranges: 0040b5f4-0040b5ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b5f4(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b600 at 0040b600
 * undefined FUN_0040b600(void)
 * Address ranges: 0040b600-0040b60b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b600(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT31((int3)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(uVar1,uVar1)),uVar1);
}


/*
 * FUN_0040b60c at 0040b60c
 * undefined FUN_0040b60c(void)
 * Address ranges: 0040b60c-0040b615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b60c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b618 at 0040b618
 * undefined FUN_0040b618(void)
 * Address ranges: 0040b618-0040b621
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b618(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b624 at 0040b624
 * undefined FUN_0040b624(void)
 * Address ranges: 0040b624-0040b62f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b624(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((uint3)(byte)((uint)param_2 >> 0x18) |
                  (uint3)(((uint)CONCAT11((char)param_2,(char)param_2) << 0x10) >> 8),
                  (char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b630 at 0040b630
 * undefined FUN_0040b630(void)
 * Address ranges: 0040b630-0040b639
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b630(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b63c at 0040b63c
 * undefined FUN_0040b63c(void)
 * Address ranges: 0040b63c-0040b643
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b63c(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x18 | param_2 << 8;
}


/*
 * FUN_0040b644 at 0040b644
 * undefined FUN_0040b644(void)
 * Address ranges: 0040b644-0040b64e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b644(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b650 at 0040b650
 * undefined FUN_0040b650(void)
 * Address ranges: 0040b650-0040b659
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b650(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b65c at 0040b65c
 * undefined FUN_0040b65c(void)
 * Address ranges: 0040b65c-0040b662
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b65c(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b664 at 0040b664
 * undefined FUN_0040b664(void)
 * Address ranges: 0040b664-0040b66c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b664(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),(char)((uint)param_2 >> 8))
  ;
}


/*
 * FUN_0040b670 at 0040b670
 * undefined FUN_0040b670(void)
 * Address ranges: 0040b670-0040b674
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b670(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b678 at 0040b678
 * undefined FUN_0040b678(void)
 * Address ranges: 0040b678-0040b67e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b678(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b680 at 0040b680
 * undefined FUN_0040b680(void)
 * Address ranges: 0040b680-0040b68b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b680(undefined4 param_1,undefined4 param_2)

{
  return CONCAT22((short)CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8)),
                  CONCAT11((char)param_2,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b68c at 0040b68c
 * undefined FUN_0040b68c(void)
 * Address ranges: 0040b68c-0040b695
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b68c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b698 at 0040b698
 * undefined FUN_0040b698(void)
 * Address ranges: 0040b698-0040b6a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b698(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b6a4 at 0040b6a4
 * undefined FUN_0040b6a4(void)
 * Address ranges: 0040b6a4-0040b6af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b6a4(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b6b0 at 0040b6b0
 * undefined FUN_0040b6b0(void)
 * Address ranges: 0040b6b0-0040b6bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b6b0(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b6bc at 0040b6bc
 * undefined FUN_0040b6bc(void)
 * Address ranges: 0040b6bc-0040b6c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b6bc(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b6c8 at 0040b6c8
 * undefined FUN_0040b6c8(void)
 * Address ranges: 0040b6c8-0040b6d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b6c8(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b6d4 at 0040b6d4
 * undefined FUN_0040b6d4(void)
 * Address ranges: 0040b6d4-0040b6df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b6d4(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}


/*
 * FUN_0040b6e0 at 0040b6e0
 * undefined FUN_0040b6e0(void)
 * Address ranges: 0040b6e0-0040b6e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b6e0(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b6ec at 0040b6ec
 * undefined FUN_0040b6ec(void)
 * Address ranges: 0040b6ec-0040b6f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b6ec(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x18 | param_2 << 8;
}


/*
 * FUN_0040b6f8 at 0040b6f8
 * undefined FUN_0040b6f8(void)
 * Address ranges: 0040b6f8-0040b704
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b6f8(undefined4 param_1,undefined2 param_2)

{
  return param_2;
}


/*
 * FUN_0040b708 at 0040b708
 * undefined FUN_0040b708(void)
 * Address ranges: 0040b708-0040b711
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b708(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040b714 at 0040b714
 * undefined FUN_0040b714(void)
 * Address ranges: 0040b714-0040b71a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b714(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b71c at 0040b71c
 * undefined FUN_0040b71c(void)
 * Address ranges: 0040b71c-0040b724
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b71c(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31(CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2),(char)((uint)param_2 >> 8))
  ;
}


/*
 * FUN_0040b728 at 0040b728
 * undefined FUN_0040b728(void)
 * Address ranges: 0040b728-0040b72e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b728(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b730 at 0040b730
 * undefined FUN_0040b730(void)
 * Address ranges: 0040b730-0040b736
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b730(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b738 at 0040b738
 * undefined FUN_0040b738(void)
 * Address ranges: 0040b738-0040b743
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b738(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 8 |
                  (uint3)((uint)(CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b744 at 0040b744
 * undefined FUN_0040b744(void)
 * Address ranges: 0040b744-0040b74d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b744(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b750 at 0040b750
 * undefined FUN_0040b750(void)
 * Address ranges: 0040b750-0040b759
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b750(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b75c at 0040b75c
 * undefined FUN_0040b75c(void)
 * Address ranges: 0040b75c-0040b767
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b75c(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b768 at 0040b768
 * undefined FUN_0040b768(void)
 * Address ranges: 0040b768-0040b776
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b768(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  uVar1 = CONCAT11((char)param_2,(char)param_2);
  return CONCAT22((short)(CONCAT22((short)((uint)param_2 >> 0x10),uVar1) >> 8),uVar1);
}


/*
 * FUN_0040b778 at 0040b778
 * undefined FUN_0040b778(void)
 * Address ranges: 0040b778-0040b787
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b778(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b788 at 0040b788
 * undefined FUN_0040b788(void)
 * Address ranges: 0040b788-0040b796
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b788(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b798 at 0040b798
 * undefined FUN_0040b798(void)
 * Address ranges: 0040b798-0040b7a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b798(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = CONCAT21((short)((uint)param_2 >> 0x10),(char)param_2);
  return ((uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 0x10 |
         (uint)uVar1 << 0x10;
}


/*
 * FUN_0040b7a8 at 0040b7a8
 * undefined FUN_0040b7a8(void)
 * Address ranges: 0040b7a8-0040b7b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b7a8(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b7b8 at 0040b7b8
 * undefined FUN_0040b7b8(void)
 * Address ranges: 0040b7b8-0040b7c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b7b8(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x18 | param_2 << 8;
}


/*
 * FUN_0040b7c8 at 0040b7c8
 * undefined FUN_0040b7c8(void)
 * Address ranges: 0040b7c8-0040b7d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b7c8(undefined4 param_1,int param_2)

{
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  (short)param_2);
}


/*
 * FUN_0040b7d8 at 0040b7d8
 * undefined FUN_0040b7d8(void)
 * Address ranges: 0040b7d8-0040b7e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b7d8(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)((uint)(param_2 << 0x18) >> 0x10),
                  CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040b7e8 at 0040b7e8
 * undefined FUN_0040b7e8(void)
 * Address ranges: 0040b7e8-0040b7f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b7e8(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b7f4 at 0040b7f4
 * undefined FUN_0040b7f4(void)
 * Address ranges: 0040b7f4-0040b7ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b7f4(undefined4 param_1,undefined4 param_2)

{
  return CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b800 at 0040b800
 * undefined FUN_0040b800(void)
 * Address ranges: 0040b800-0040b80b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b800(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b80c at 0040b80c
 * undefined FUN_0040b80c(void)
 * Address ranges: 0040b80c-0040b817
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b80c(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b818 at 0040b818
 * undefined FUN_0040b818(void)
 * Address ranges: 0040b818-0040b823
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b818(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)((uint)param_2 >> 8))
                  );
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b824 at 0040b824
 * undefined FUN_0040b824(void)
 * Address ranges: 0040b824-0040b82f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b824(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b830 at 0040b830
 * undefined FUN_0040b830(void)
 * Address ranges: 0040b830-0040b83b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b830(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b83c at 0040b83c
 * undefined FUN_0040b83c(void)
 * Address ranges: 0040b83c-0040b847
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b83c(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b848 at 0040b848
 * undefined FUN_0040b848(void)
 * Address ranges: 0040b848-0040b856
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b848(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b858 at 0040b858
 * undefined FUN_0040b858(void)
 * Address ranges: 0040b858-0040b864
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b858(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b868 at 0040b868
 * undefined FUN_0040b868(void)
 * Address ranges: 0040b868-0040b874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b868(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b878 at 0040b878
 * undefined FUN_0040b878(void)
 * Address ranges: 0040b878-0040b886
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b878(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}


/*
 * FUN_0040b888 at 0040b888
 * undefined FUN_0040b888(void)
 * Address ranges: 0040b888-0040b894
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b888(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b898 at 0040b898
 * undefined FUN_0040b898(void)
 * Address ranges: 0040b898-0040b8a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b898(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b8a8 at 0040b8a8
 * undefined FUN_0040b8a8(void)
 * Address ranges: 0040b8a8-0040b8b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b8a8(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((int3)CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8)),
                  (char)param_2);
}


/*
 * FUN_0040b8b8 at 0040b8b8
 * undefined FUN_0040b8b8(void)
 * Address ranges: 0040b8b8-0040b8c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b8b8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040b8c8 at 0040b8c8
 * undefined FUN_0040b8c8(void)
 * Address ranges: 0040b8c8-0040b8d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b8c8(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b8d4 at 0040b8d4
 * undefined FUN_0040b8d4(void)
 * Address ranges: 0040b8d4-0040b8df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b8d4(undefined4 param_1,undefined4 param_2)

{
  return CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b8e0 at 0040b8e0
 * undefined FUN_0040b8e0(void)
 * Address ranges: 0040b8e0-0040b8e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b8e0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b8ec at 0040b8ec
 * undefined FUN_0040b8ec(void)
 * Address ranges: 0040b8ec-0040b8f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b8ec(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b8f8 at 0040b8f8
 * undefined FUN_0040b8f8(void)
 * Address ranges: 0040b8f8-0040b903
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b8f8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 8 |
                  (uint3)((uint)(CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 8),
                  (char)param_2);
}


/*
 * FUN_0040b904 at 0040b904
 * undefined FUN_0040b904(void)
 * Address ranges: 0040b904-0040b90d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b904(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b910 at 0040b910
 * undefined FUN_0040b910(void)
 * Address ranges: 0040b910-0040b91c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b910(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040b920 at 0040b920
 * undefined FUN_0040b920(void)
 * Address ranges: 0040b920-0040b92b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b920(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040b92c at 0040b92c
 * undefined FUN_0040b92c(void)
 * Address ranges: 0040b92c-0040b93a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b92c(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)param_2;
  return CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b93c at 0040b93c
 * undefined FUN_0040b93c(void)
 * Address ranges: 0040b93c-0040b948
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b93c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040b94c at 0040b94c
 * undefined FUN_0040b94c(void)
 * Address ranges: 0040b94c-0040b958
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b94c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040b95c at 0040b95c
 * undefined FUN_0040b95c(void)
 * Address ranges: 0040b95c-0040b96a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b95c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) |
         CONCAT22(uVar1,CONCAT11((char)param_2,(char)((uint)param_2 >> 8))) << 8;
}


/*
 * FUN_0040b96c at 0040b96c
 * undefined FUN_0040b96c(void)
 * Address ranges: 0040b96c-0040b978
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b96c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11((char)param_2,(char)param_2));
  return uVar1 >> 8 | uVar1 << 0x18;
}


/*
 * FUN_0040b97c at 0040b97c
 * undefined FUN_0040b97c(void)
 * Address ranges: 0040b97c-0040b988
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b97c(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040b98c at 0040b98c
 * undefined FUN_0040b98c(void)
 * Address ranges: 0040b98c-0040b99a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b98c(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((int3)CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8)),
                  (char)param_2);
}


/*
 * FUN_0040b99c at 0040b99c
 * undefined FUN_0040b99c(void)
 * Address ranges: 0040b99c-0040b9a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b99c(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040b9ac at 0040b9ac
 * undefined FUN_0040b9ac(void)
 * Address ranges: 0040b9ac-0040b9b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b9ac(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040b9b8 at 0040b9b8
 * undefined FUN_0040b9b8(void)
 * Address ranges: 0040b9b8-0040b9c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040b9b8(undefined4 param_1,undefined4 param_2)

{
  return CONCAT11((char)param_2,(char)((uint)param_2 >> 8));
}


/*
 * FUN_0040b9c4 at 0040b9c4
 * undefined FUN_0040b9c4(void)
 * Address ranges: 0040b9c4-0040b9cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b9c4(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040b9d0 at 0040b9d0
 * undefined FUN_0040b9d0(void)
 * Address ranges: 0040b9d0-0040b9d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b9d0(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040b9dc at 0040b9dc
 * undefined FUN_0040b9dc(void)
 * Address ranges: 0040b9dc-0040b9e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040b9dc(undefined4 param_1,undefined4 param_2)

{
  return CONCAT22((short)CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8)),
                  CONCAT11((char)param_2,(char)((uint)param_2 >> 0x10)));
}


/*
 * FUN_0040b9e8 at 0040b9e8
 * undefined FUN_0040b9e8(void)
 * Address ranges: 0040b9e8-0040b9f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b9e8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040b9f8 at 0040b9f8
 * undefined FUN_0040b9f8(void)
 * Address ranges: 0040b9f8-0040ba01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040b9f8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040ba04 at 0040ba04
 * undefined FUN_0040ba04(void)
 * Address ranges: 0040ba04-0040ba0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ba04(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  undefined1 uVar2;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  uVar2 = (undefined1)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 0x10 | (uint3)((uint)(CONCAT31(uVar1,uVar2) << 0x10) >> 8),uVar2);
}


/*
 * FUN_0040ba10 at 0040ba10
 * undefined FUN_0040ba10(void)
 * Address ranges: 0040ba10-0040ba1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ba10(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (undefined1)((uint)param_2 >> 0x10);
  return CONCAT22(CONCAT11((char)param_2,(char)param_2),CONCAT11(uVar1,uVar1));
}


/*
 * FUN_0040ba20 at 0040ba20
 * undefined FUN_0040ba20(void)
 * Address ranges: 0040ba20-0040ba2e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ba20(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 8;
}


/*
 * FUN_0040ba30 at 0040ba30
 * undefined FUN_0040ba30(void)
 * Address ranges: 0040ba30-0040ba3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ba30(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)uVar1 | CONCAT22(uVar1,CONCAT11((char)param_2,(char)param_2)) << 0x10;
}


/*
 * FUN_0040ba40 at 0040ba40
 * undefined FUN_0040ba40(void)
 * Address ranges: 0040ba40-0040ba4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ba40(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)((uint)param_2 >> 0x10);
  return (uint)(uVar1 >> 8) | CONCAT22(uVar1,(short)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040ba50 at 0040ba50
 * undefined FUN_0040ba50(void)
 * Address ranges: 0040ba50-0040ba5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ba50(undefined4 param_1,int param_2)

{
  return CONCAT31((uint3)(ushort)((uint)param_2 >> 0x10) | (uint3)((uint)(param_2 << 0x18) >> 8),
                  (char)((uint)param_2 >> 0x10));
}


/*
 * FUN_0040ba60 at 0040ba60
 * undefined FUN_0040ba60(void)
 * Address ranges: 0040ba60-0040ba6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ba60(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 | param_2 << 0x18;
}


/*
 * FUN_0040ba70 at 0040ba70
 * undefined FUN_0040ba70(void)
 * Address ranges: 0040ba70-0040ba7e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040ba70(undefined4 param_1,undefined4 param_2)

{
  return CONCAT31((int3)CONCAT31((int3)((uint)param_2 >> 8),(char)((uint)param_2 >> 8)),
                  (char)((uint)param_2 >> 0x10));
}


/*
 * FUN_0040ba80 at 0040ba80
 * undefined FUN_0040ba80(void)
 * Address ranges: 0040ba80-0040ba8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ba80(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 0x10) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 8;
}


/*
 * FUN_0040ba90 at 0040ba90
 * undefined FUN_0040ba90(void)
 * Address ranges: 0040ba90-0040ba9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined2 __fastcall FUN_0040ba90(undefined4 param_1,undefined1 param_2)

{
  return CONCAT11(param_2,param_2);
}


/*
 * FUN_0040ba9c at 0040ba9c
 * undefined FUN_0040ba9c(void)
 * Address ranges: 0040ba9c-0040baa7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040ba9c(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xffff;
}


/*
 * FUN_0040baa8 at 0040baa8
 * undefined FUN_0040baa8(void)
 * Address ranges: 0040baa8-0040bab3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040baa8(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


/*
 * FUN_0040bab4 at 0040bab4
 * undefined FUN_0040bab4(void)
 * Address ranges: 0040bab4-0040babf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040bab4(undefined4 param_1,uint param_2)

{
  return param_2 >> 8 & 0xff;
}


/*
 * FUN_0040bac0 at 0040bac0
 * undefined FUN_0040bac0(void)
 * Address ranges: 0040bac0-0040bacb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040bac0(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return CONCAT31(uVar1 >> 8 |
                  (uint3)((uint)(CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18) >> 8),
                  (char)((uint)param_2 >> 0x10));
}


/*
 * FUN_0040bacc at 0040bacc
 * undefined FUN_0040bacc(void)
 * Address ranges: 0040bacc-0040bad7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040bacc(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)uVar1 | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x18;
}


/*
 * FUN_0040bad8 at 0040bad8
 * undefined FUN_0040bad8(void)
 * Address ranges: 0040bad8-0040bae3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


uint __fastcall FUN_0040bad8(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)param_2 >> 8);
  return (uint)(uVar1 >> 8) | CONCAT31(uVar1,(char)((uint)param_2 >> 8)) << 0x10;
}


/*
 * FUN_0040bae4 at 0040bae4
 * undefined FUN_0040bae4(void)
 * Address ranges: 0040bae4-0040baef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined4 __fastcall FUN_0040bae4(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = (byte)((uint)param_2 >> 8);
  return CONCAT22((ushort)(byte)((uint)param_2 >> 0x18) | (ushort)(((uint)bVar1 << 0x18) >> 0x10),
                  CONCAT11(bVar1,bVar1));
}


/*
 * FUN_0040c920 at 0040c920
 * undefined8 __fastcall FUN_0040c920(undefined4 param_1, undefined4 param_2, uint * param_3, int param_4, byte * param_5)
 * Address ranges: 00409f20-00409fd0;0040c920-0040cae5;0040caf0-0040cbba;0040cbc0-0040cc04;0040cc10-0040ccb3;0040ccc0-0040cce6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_0040c920(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,byte *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  uint *puVar6;
  ushort *puVar7;
  char cVar8;
  undefined4 uVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  undefined4 extraout_ECX;
  undefined4 uVar13;
  uint *puVar14;
  short sVar15;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  uint uVar16;
  undefined4 *puVar17;
  uint *puVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  undefined8 uVar21;
  byte *in_stack_ffffffe4;
  
  _DAT_0040e9a4 = param_4;
  puVar17 = (undefined4 *)(param_4 + 0x7414);
  DAT_0040e9d0 = CONCAT22(DAT_0040e9d0._2_2_,(short)*(undefined4 *)(param_4 + 0x7410));
  puVar20 = &DAT_0040e910;
  iVar12 = 4;
  do {
    uVar9 = *puVar17;
    *puVar20 = uVar9;
    puVar1 = (undefined4 *)puVar17[1];
    puVar20[1] = puVar1;
    *puVar1 = uVar9;
    puVar1 = puVar17 + 3;
    puVar2 = (undefined4 *)puVar17[2];
    puVar3 = puVar20 + 3;
    puVar20[2] = puVar2;
    *puVar2 = uVar9;
    puVar17 = puVar17 + 4;
    puVar1 = (undefined4 *)*puVar1;
    puVar20 = puVar20 + 4;
    *puVar3 = puVar1;
    *puVar1 = uVar9;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  _DAT_0040e900 = param_4 + 0x10;
  _DAT_0040e904 = param_4 + 0x2010;
  _DAT_0040e908 = param_4 + 0x3010;
  DAT_0040e90c = param_4 + 0x7010;
  uVar16 = *param_3;
  puVar18 = param_3 + 1;
  DAT_0040e9c0 = 0x21;
  _DAT_0040e9ac = *param_5 & 1 ^ 1;
  if ((param_5[1] & 1) == 0) {
    if (_DAT_0040e9ac == 0) {
      _DAT_0040e950 = &DAT_0040baf0;
      _DAT_0040e954 = &DAT_0040be30;
      _DAT_0040e958 = &DAT_0040c640;
      _DAT_0040e95c = &DAT_0040c790;
    }
    else {
      _DAT_0040e950 = &DAT_0040bb40;
      _DAT_0040e954 = &DAT_0040be80;
      _DAT_0040e958 = &DAT_0040c684;
      _DAT_0040e95c = &DAT_0040c7e0;
    }
    _DAT_0040e9a8 = 0;
  }
  else {
    if (_DAT_0040e9ac == 0) {
      _DAT_0040e950 = &DAT_0040a040;
      _DAT_0040e954 = &DAT_0040a3a0;
      _DAT_0040e958 = &DAT_0040c640;
      _DAT_0040e95c = &DAT_0040abb0;
    }
    else {
      _DAT_0040e950 = &DAT_0040a090;
      _DAT_0040e954 = &DAT_0040a3f0;
      _DAT_0040e958 = &DAT_0040c684;
      _DAT_0040e95c = &DAT_0040ac00;
    }
    _DAT_0040e9a8 = 1;
  }
  if (_DAT_0040e9ac == 0) {
    _DAT_0040e968 = *(uint *)(param_5 + 8);
    DAT_0040e970 = *(uint *)(param_5 + 0xc);
    _DAT_0040e96c = *(uint *)(param_5 + 0x10);
    _DAT_0040e984 = *(uint *)(param_5 + 0x14);
    _DAT_0040e960 = *(uint *)(param_5 + 0x18);
    _DAT_0040e988 = *(uint *)(param_5 + 0x1c);
    in_stack_ffffffe4 = *(byte **)(param_5 + 4);
    DAT_0040e974 = _DAT_0040e968;
    param_5[0x20] = 0;
    param_5[0x21] = 0;
    param_5[0x22] = 0;
    param_5[0x23] = 0;
    param_5[0x2c] = 0;
    param_5[0x2d] = 0;
    param_5[0x2e] = 0;
    param_5[0x2f] = 0;
    param_5[0x30] = 0;
    param_5[0x31] = 0;
    param_5[0x32] = 0;
    param_5[0x33] = 0;
    _DAT_0040eaf8 = param_5 + 0x38;
    _DAT_0040eaf4 = 0;
    DAT_0040eaf0 = 0;
  }
  else {
    DAT_0040e99c = *(code **)(param_5 + 4);
    _DAT_0040e980 = (byte *)(uint)*(ushort *)(param_5 + 8);
    DAT_0040e9a0 = (ushort *)(param_5 + 10);
    if (_DAT_0040e9ac == 0) {
LAB_0040ccc0:
      pbVar19 = in_stack_ffffffe4;
      if ((_DAT_0040e9ac & 1) == 0) {
        pbVar19 = _DAT_0040eaf8 + (DAT_0040eaf0 >> 4);
        *pbVar19 = 0;
      }
      return CONCAT44(in_stack_ffffffe4,pbVar19);
    }
    uVar13 = 0;
    in_stack_ffffffe4 = _DAT_0040e980;
    do {
      puVar7 = DAT_0040e9a0;
      uVar4 = *DAT_0040e9a0;
      if (uVar4 < 0xfffd) {
        (*DAT_0040e99c)(in_stack_ffffffe4,param_2);
        uVar13 = extraout_ECX;
        uVar9 = extraout_EDX_00;
      }
      else if (uVar4 != 0xfffe) {
        if (uVar4 != 0xffff) {
          puVar17 = *(undefined4 **)(DAT_0040e9a0 + 1);
          pbVar19 = *(byte **)(DAT_0040e9a0 + 3);
          uVar11 = DAT_0040e974;
          for (uVar16 = (uint)DAT_0040e9a0[5]; DAT_0040e974 = uVar11, uVar16 != 0;
              uVar16 = uVar16 - 1) {
            for (; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pbVar19 = *puVar17;
              puVar17 = puVar17 + 1;
              pbVar19 = pbVar19 + 4;
            }
            pbVar19 = pbVar19 + (int)_DAT_0040e980;
            uVar11 = DAT_0040e974;
          }
          for (uVar16 = (uint)puVar7[6]; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)pbVar19 = *puVar17;
            puVar17 = puVar17 + 1;
            pbVar19 = pbVar19 + 4;
          }
          (*DAT_0040e99c)(uVar9,uVar13,puVar18,0x40cb43);
          pbVar19 = pbVar19 + 0xffff0000;
          for (uVar16 = (uint)*(ushort *)(extraout_EDX + 0x10); uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)pbVar19 = *puVar17;
            puVar17 = puVar17 + 1;
            pbVar19 = pbVar19 + 4;
          }
          pbVar19 = pbVar19 + (int)_DAT_0040e980;
          uVar11 = DAT_0040e974;
          for (uVar16 = (uint)*(ushort *)(extraout_EDX + 0x12); DAT_0040e974 = uVar11, uVar16 != 0;
              uVar16 = uVar16 - 1) {
            for (; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pbVar19 = *puVar17;
              puVar17 = puVar17 + 1;
              pbVar19 = pbVar19 + 4;
            }
            pbVar19 = pbVar19 + (int)_DAT_0040e980;
            uVar11 = DAT_0040e974;
          }
          _DAT_0040e960 = (uint)*(ushort *)(extraout_EDX + 0x14);
          DAT_0040e974 = (uint)*(ushort *)(extraout_EDX + 0x16);
          _DAT_0040e968 = (uint)*(ushort *)(extraout_EDX + 0x16);
          _DAT_0040e96c = (uint)*(ushort *)(extraout_EDX + 0x18);
          _DAT_0040e984 = (uint)*(ushort *)(extraout_EDX + 0x1a);
          _DAT_0040e988 = (uint)*(ushort *)(extraout_EDX + 0x1c);
          DAT_0040e970 = (uint)*(ushort *)(extraout_EDX + 0x1e);
          DAT_0040e9a0 = (ushort *)(extraout_EDX + 0x20);
          return CONCAT44(uVar9,(uint)*(ushort *)(extraout_EDX + 0x1e));
        }
        goto LAB_0040ccc0;
      }
      _DAT_0040e960 = (uint)puVar7[1];
      _DAT_0040e968 = (uint)puVar7[2];
      _DAT_0040e96c = (uint)puVar7[3];
      _DAT_0040e984 = (uint)puVar7[4];
      _DAT_0040e988 = (uint)puVar7[5];
      DAT_0040e970 = (uint)puVar7[8];
      DAT_0040e9a0 = puVar7 + 9;
      DAT_0040e974 = _DAT_0040e968;
    } while (DAT_0040e970 == 0);
  }
  puVar6 = DAT_0040e948;
  if (DAT_0040e9c0 < 9) {
    uVar11 = *puVar18;
    puVar18 = (uint *)((int)param_3 + 6);
    uVar16 = uVar11 << (DAT_0040e9c0 - 1 & 0x1f) | uVar16;
    uVar11 = *(uint *)(DAT_0040e90c + (uVar16 & 0xff) * 4);
    bVar10 = (byte)uVar11;
    uVar16 = uVar16 >> (bVar10 & 0x1f);
    cVar8 = (DAT_0040e9c0 + 0x10) - bVar10;
    puVar14 = (uint *)((uVar11 >> 8) + _DAT_0040e9a4);
    uVar11 = *puVar14;
    sVar15 = (short)uVar11;
  }
  else {
    uVar11 = *(uint *)(DAT_0040e90c + (uVar16 & 0xff) * 4);
    bVar10 = (byte)uVar11;
    uVar16 = uVar16 >> (bVar10 & 0x1f);
    cVar8 = DAT_0040e9c0 - bVar10;
    puVar14 = (uint *)((uVar11 >> 8) + _DAT_0040e9a4);
    uVar11 = *puVar14;
    sVar15 = (short)uVar11;
  }
  uVar9 = CONCAT31((int3)((uint)in_stack_ffffffe4 >> 8),cVar8);
  while (DAT_0040e9c0 = (byte)uVar9, (short)DAT_0040e9d0 == sVar15) {
    cVar8 = DAT_0040e9c0 + -1;
    if (cVar8 == '\0') {
      uVar16 = *puVar18;
      puVar18 = puVar18 + 1;
      cVar8 = ' ';
    }
    uVar9 = CONCAT31((int3)((uint)uVar9 >> 8),cVar8);
    uVar11 = uVar11 >> 0xd & 0xffff8;
    if ((uVar16 & 1) == 0) {
      uVar11 = 4;
    }
    puVar14 = (uint *)((int)puVar14 + uVar11);
    uVar11 = *puVar14;
    uVar16 = uVar16 >> 1;
    sVar15 = (short)uVar11;
  }
  uVar16 = CONCAT22((short)((uint)uVar9 >> 0x10),(short)(uVar11 >> 0x10));
  if (*DAT_0040e944 != uVar11) {
    uVar5 = *DAT_0040e944;
    DAT_0040e978 = uVar16;
    *DAT_0040e944 = uVar11;
    puVar18 = DAT_0040e94c;
    uVar11 = *puVar6;
    *puVar6 = uVar5;
    uVar16 = DAT_0040e978;
    *puVar18 = uVar11;
  }
  _DAT_0040e964 = *(undefined4 *)(&DAT_0040e9e0 + (uVar16 & 0xfc));
                    /* WARNING: Jumptable at 0x0040ccad did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
  uVar21 = (**(code **)(&DAT_0040e950 + (uVar16 & 3) * 4))();
  return uVar21;
}


/*
 * FUN_0040ccf0 at 0040ccf0
 * undefined __cdecl FUN_0040ccf0(uint * param_1, int param_2, uint * param_3, uint * param_4, uint * param_5, uint * param_6)
 * Address ranges: 0040ccf0-0040d517
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


/* WARNING: Removing unreachable block (ram,0x0040cd56) */
/* WARNING: Removing unreachable block (ram,0x0040cd73) */
/* WARNING: Removing unreachable block (ram,0x0040d03d) */
/* WARNING: Removing unreachable block (ram,0x0040ce88) */
/* WARNING: Removing unreachable block (ram,0x0040d05a) */
/* WARNING: Removing unreachable block (ram,0x0040cd90) */
/* WARNING: Removing unreachable block (ram,0x0040d209) */

void __cdecl
FUN_0040ccf0(uint *param_1,int param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  undefined2 uVar9;
  ushort uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  
  DAT_0040ef20 = param_2;
  DAT_0040ef24 = param_3;
  DAT_0040ef28 = param_4;
  DAT_0040ef2c = param_5;
  DAT_0040ef30 = param_6;
  uVar12 = *param_1;
  puVar13 = param_1 + 1;
  DAT_0040e9c0 = 0x20;
  if ((uVar12 & 1) != 0) {
    if ((uVar12 >> 1 & 1) == 0) {
      if ((uVar12 >> 2 & 1) == 0) {
        DAT_0040e9c0 = 0x1d;
        DAT_0040e98c = param_3;
        FUN_00409800();
        bVar2 = DAT_0040e9c0;
        if (DAT_0040ef20 != 0) {
          DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
          if (DAT_0040ef2c < DAT_0040eafc) {
            DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
          }
          bVar8 = (byte)(uVar12 >> 4);
          puVar14 = DAT_0040ef30;
          if (DAT_0040e9c0 < 9) {
            DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
            uVar12 = *puVar13;
            bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
            puVar13 = param_1 + 2;
            uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
          }
          else {
            DAT_0040e9c0 = DAT_0040e9c0 - 8;
            uVar12 = uVar12 >> 0xc;
          }
          while( true ) {
            *(byte *)puVar14 = bVar8;
            puVar14 = (uint *)((int)puVar14 + 1);
            if (DAT_0040eafc == puVar14) break;
            if (DAT_0040ef2c == puVar14) {
              puVar14 = DAT_0040ef28;
            }
            uVar5 = *DAT_0040e98c;
            puVar11 = DAT_0040e98c;
            while ((uVar5 & 0x80000000) == 0) {
              DAT_0040e9c0 = DAT_0040e9c0 - 1;
              if (DAT_0040e9c0 == 0) {
                uVar12 = *puVar13;
                puVar13 = puVar13 + 1;
                DAT_0040e9c0 = 0x20;
              }
              if ((uVar12 & 1) == 0) {
                uVar5 = 4;
              }
              puVar11 = (uint *)((int)puVar11 + uVar5);
              uVar12 = uVar12 >> 1;
              uVar5 = *puVar11;
            }
            bVar8 = bVar8 + (char)uVar5;
          }
        }
      }
      else {
        DAT_0040e9c0 = '\x1d';
        uVar12 = uVar12 >> 4;
        DAT_0040e98c = param_3;
        FUN_00409800();
        DAT_0040e9c0 = DAT_0040e9c0 - 1;
        if (DAT_0040e9c0 == 0) {
          uVar12 = *puVar13;
          puVar13 = param_1 + 2;
          DAT_0040e9c0 = 0x20;
        }
        DAT_0040e990 = DAT_0040ef24 + 0x200;
        FUN_00409800();
        bVar2 = DAT_0040e9c0;
        if (DAT_0040ef20 != 0) {
          DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
          if (DAT_0040ef2c < DAT_0040eafc) {
            DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
          }
          bVar8 = (byte)(uVar12 >> 1);
          if (DAT_0040e9c0 < 9) {
            DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
            uVar12 = *puVar13;
            bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
            puVar13 = puVar13 + 1;
            uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
          }
          else {
            DAT_0040e9c0 = DAT_0040e9c0 - 8;
            uVar12 = uVar12 >> 9;
          }
          bVar3 = DAT_0040e9c0;
          bVar2 = (byte)uVar12;
          if (DAT_0040e9c0 < 9) {
            DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
            uVar12 = *puVar13;
            bVar2 = bVar2 | (byte)(uVar12 << (bVar3 - 1 & 0x1f));
            puVar13 = puVar13 + 1;
            uVar12 = uVar12 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
          }
          else {
            DAT_0040e9c0 = DAT_0040e9c0 - 8;
            uVar12 = uVar12 >> 8;
          }
          uVar9 = CONCAT11(bVar8,bVar2);
          puVar14 = DAT_0040ef30;
          while( true ) {
            *(undefined2 *)puVar14 = uVar9;
            puVar14 = (uint *)((int)puVar14 + 2);
            if (DAT_0040eafc == puVar14) break;
            if (DAT_0040ef2c == puVar14) {
              puVar14 = DAT_0040ef28;
            }
            uVar5 = *DAT_0040e98c;
            puVar11 = DAT_0040e98c;
            while ((uVar5 & 0x80000000) == 0) {
              DAT_0040e9c0 = DAT_0040e9c0 - 1;
              if (DAT_0040e9c0 == 0) {
                uVar12 = *puVar13;
                puVar13 = puVar13 + 1;
                DAT_0040e9c0 = 0x20;
              }
              if ((uVar12 & 1) == 0) {
                uVar5 = 4;
              }
              puVar11 = (uint *)((int)puVar11 + uVar5);
              uVar12 = uVar12 >> 1;
              uVar5 = *puVar11;
            }
            uVar6 = *DAT_0040e990;
            puVar11 = DAT_0040e990;
            while ((uVar6 & 0x80000000) == 0) {
              DAT_0040e9c0 = DAT_0040e9c0 - 1;
              if (DAT_0040e9c0 == 0) {
                uVar12 = *puVar13;
                puVar13 = puVar13 + 1;
                DAT_0040e9c0 = 0x20;
              }
              if ((uVar12 & 1) == 0) {
                uVar6 = 4;
              }
              puVar11 = (uint *)((int)puVar11 + uVar6);
              uVar12 = uVar12 >> 1;
              uVar6 = *puVar11;
            }
            uVar9 = CONCAT11((char)((ushort)uVar9 >> 8) + CARRY1((byte)uVar9,(byte)uVar5) +
                             (char)uVar6,(byte)uVar9 + (byte)uVar5);
          }
        }
      }
    }
    else if ((uVar12 >> 2 & 1) == 0) {
      DAT_0040e9c0 = '\x1d';
      uVar12 = uVar12 >> 4;
      DAT_0040e98c = param_3;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 - 1;
      if (DAT_0040e9c0 == 0) {
        uVar12 = *puVar13;
        puVar13 = param_1 + 2;
        DAT_0040e9c0 = 0x20;
      }
      DAT_0040e990 = DAT_0040ef24 + 0x200;
      FUN_00409800();
      bVar2 = DAT_0040e9c0;
      if (DAT_0040ef20 != 0) {
        DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
        if (DAT_0040ef2c < DAT_0040eafc) {
          DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
        }
        bVar8 = (byte)(uVar12 >> 1);
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 9;
        }
        bVar3 = DAT_0040e9c0;
        bVar2 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar2 = bVar2 | (byte)(uVar12 << (bVar3 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        uVar9 = CONCAT11(bVar8,bVar2);
        puVar14 = DAT_0040ef30;
        while( true ) {
          *(undefined2 *)puVar14 = uVar9;
          puVar14 = (uint *)((int)puVar14 + 2);
          if (DAT_0040eafc == puVar14) break;
          if (DAT_0040ef2c == puVar14) {
            puVar14 = DAT_0040ef28;
          }
          uVar5 = *DAT_0040e98c;
          puVar11 = DAT_0040e98c;
          while ((uVar5 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar5 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar5);
            uVar12 = uVar12 >> 1;
            uVar5 = *puVar11;
          }
          uVar6 = *DAT_0040e990;
          puVar11 = DAT_0040e990;
          while ((uVar6 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar6 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar6);
            uVar12 = uVar12 >> 1;
            uVar6 = *puVar11;
          }
          uVar9 = CONCAT11((char)((ushort)uVar9 >> 8) + (char)uVar6,(char)uVar9 + (char)uVar5);
        }
      }
    }
    else {
      DAT_0040e9c0 = '\x1d';
      uVar12 = uVar12 >> 4;
      DAT_0040e98c = param_3;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar12 = *puVar13;
        puVar13 = param_1 + 2;
        DAT_0040e9c0 = ' ';
      }
      uVar12 = uVar12 >> 1;
      DAT_0040e990 = DAT_0040ef24 + 0x200;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 + -1;
      if (DAT_0040e9c0 == '\0') {
        uVar12 = *puVar13;
        puVar13 = puVar13 + 1;
        DAT_0040e9c0 = ' ';
      }
      uVar12 = uVar12 >> 1;
      DAT_0040e994 = DAT_0040ef24 + 0x400;
      FUN_00409800();
      DAT_0040e9c0 = DAT_0040e9c0 - 1;
      if (DAT_0040e9c0 == 0) {
        uVar12 = *puVar13;
        puVar13 = puVar13 + 1;
        DAT_0040e9c0 = 0x20;
      }
      DAT_0040e998 = DAT_0040ef24 + 0x600;
      FUN_00409800();
      bVar2 = DAT_0040e9c0;
      if (DAT_0040ef20 != 0) {
        DAT_0040eafc = (uint *)(DAT_0040ef20 + (int)DAT_0040ef30);
        if (DAT_0040ef2c < DAT_0040eafc) {
          DAT_0040eafc = (uint *)(((int)DAT_0040eafc - (int)DAT_0040ef2c) + (int)DAT_0040ef28);
        }
        bVar8 = (byte)(uVar12 >> 1);
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar8 = bVar8 | (byte)(uVar12 << (bVar2 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar2 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 9;
        }
        bVar3 = DAT_0040e9c0;
        bVar2 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar2 = bVar2 | (byte)(uVar12 << (bVar3 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar3 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        bVar4 = DAT_0040e9c0;
        bVar3 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar3 = bVar3 | (byte)(uVar12 << (bVar4 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar4 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        bVar1 = DAT_0040e9c0;
        bVar4 = (byte)uVar12;
        if (DAT_0040e9c0 < 9) {
          DAT_0040e9c0 = DAT_0040e9c0 + 0x18;
          uVar12 = *puVar13;
          bVar4 = bVar4 | (byte)(uVar12 << (bVar1 - 1 & 0x1f));
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 >> ((bVar1 - 10 ^ 0xff) & 0x1f);
        }
        else {
          DAT_0040e9c0 = DAT_0040e9c0 - 8;
          uVar12 = uVar12 >> 8;
        }
        uVar5 = CONCAT31(CONCAT21(CONCAT11(bVar8,bVar2),bVar3),bVar4);
        puVar14 = DAT_0040ef30;
        while( true ) {
          *puVar14 = uVar5;
          puVar14 = puVar14 + 1;
          if (DAT_0040eafc == puVar14) break;
          if (DAT_0040ef2c == puVar14) {
            puVar14 = DAT_0040ef28;
          }
          uVar6 = *DAT_0040e98c;
          puVar11 = DAT_0040e98c;
          while ((uVar6 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar6 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar6);
            uVar12 = uVar12 >> 1;
            uVar6 = *puVar11;
          }
          uVar7 = *DAT_0040e990;
          puVar11 = DAT_0040e990;
          while ((uVar7 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar7 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar7);
            uVar12 = uVar12 >> 1;
            uVar7 = *puVar11;
          }
          uVar10 = CONCAT11((char)(uVar5 >> 8) + CARRY1((byte)uVar5,(byte)uVar6) + (char)uVar7,
                            (byte)uVar5 + (byte)uVar6);
          uVar6 = *DAT_0040e994;
          puVar11 = DAT_0040e994;
          while ((uVar6 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar6 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar6);
            uVar12 = uVar12 >> 1;
            uVar6 = *puVar11;
          }
          bVar2 = (byte)(uVar5 >> 0x10);
          uVar7 = *DAT_0040e998;
          puVar11 = DAT_0040e998;
          while ((uVar7 & 0x80000000) == 0) {
            DAT_0040e9c0 = DAT_0040e9c0 - 1;
            if (DAT_0040e9c0 == 0) {
              uVar12 = *puVar13;
              puVar13 = puVar13 + 1;
              DAT_0040e9c0 = 0x20;
            }
            if ((uVar12 & 1) == 0) {
              uVar7 = 4;
            }
            puVar11 = (uint *)((int)puVar11 + uVar7);
            uVar12 = uVar12 >> 1;
            uVar7 = *puVar11;
          }
          uVar5 = (uint)uVar10 |
                  CONCAT22(uVar10,CONCAT11((char)(uVar5 >> 0x18) + CARRY1(bVar2,(byte)uVar6) +
                                           (char)uVar7,bVar2 + (byte)uVar6)) << 0x10;
        }
      }
    }
  }
  return;
}


/*
 * FUN_0040d520 at 0040d520
 * undefined8 __fastcall FUN_0040d520(undefined4 param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 0040d520-0040d536
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_0040d520(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  return CONCAT44(param_2,((uint)(param_3 * param_4) >> 8) + 0x20);
}


/*
 * FUN_0040d540 at 0040d540
 * undefined8 __fastcall FUN_0040d540(undefined4 param_1, undefined4 param_2, int param_3, uint * param_4)
 * Address ranges: 0040d540-0040d650
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


undefined8 __fastcall FUN_0040d540(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  
  if (*(char *)(param_3 + 0x20) == '\0') {
    psVar5 = *(short **)(param_3 + 0x34);
    if (*(char *)(param_3 + 0x21) == '\0') {
      if (*(char *)(param_3 + 0x22) == '\0') {
        psVar5 = (short *)(param_3 + 0x38);
        *(undefined1 *)(param_3 + 0x22) = 1;
      }
      uVar4 = *(uint *)(param_3 + 0x2c);
      uVar3 = *(uint *)(param_3 + 0x30);
      if (uVar3 < *(uint *)(param_3 + 0x28)) {
        if ((char)*psVar5 == '\0') {
          while ((char)*psVar5 == '\0') {
            psVar5 = (short *)((int)psVar5 + 1);
            for (uVar4 = uVar4 + 0x40; *(uint *)(param_3 + 0x24) <= uVar4;
                uVar4 = uVar4 - *(int *)(param_3 + 0x24)) {
              uVar3 = uVar3 + 4;
              if (*(uint *)(param_3 + 0x28) <= uVar3) goto LAB_0040d642;
            }
          }
          *(uint *)(param_3 + 0x30) = uVar3;
        }
        *param_4 = uVar4;
        param_4[1] = uVar3;
        param_4[3] = 4;
        param_4[2] = 0;
LAB_0040d5be:
        do {
          psVar6 = psVar5;
          uVar4 = uVar4 + 0x40;
          if (*(uint *)(param_3 + 0x24) <= uVar4) {
            iVar1 = uVar4 - *(int *)(param_3 + 0x24);
            *(int *)(param_3 + 0x2c) = iVar1;
            if (iVar1 != 0) {
              *(undefined1 *)(param_3 + 0x21) = 1;
            }
            param_4[2] = param_4[2] - (iVar1 + -0x40);
            *(int *)(param_3 + 0x30) = *(int *)(param_3 + 0x30) + 4;
            goto LAB_0040d5f3;
          }
          psVar5 = (short *)((int)psVar6 + 1);
          param_4[2] = param_4[2] + 0x40;
        } while (*(char *)psVar5 != '\0');
        *(uint *)(param_3 + 0x2c) = uVar4;
LAB_0040d5f3:
        uVar2 = 1;
        *(char **)(param_3 + 0x34) = (char *)((int)psVar6 + 1);
        goto LAB_0040d64a;
      }
    }
    else if (*(uint *)(param_3 + 0x30) < *(uint *)(param_3 + 0x28)) {
      param_4[1] = *(uint *)(param_3 + 0x30);
      *param_4 = 0;
      uVar4 = *(uint *)(param_3 + 0x2c);
      if (uVar4 < *(uint *)(param_3 + 0x24)) {
        *(undefined1 *)(param_3 + 0x21) = 0;
        param_4[2] = uVar4;
        if (*psVar5 != 0) goto LAB_0040d5be;
      }
      else {
        uVar3 = *(uint *)(param_3 + 0x24);
        param_4[2] = uVar3;
        *(uint *)(param_3 + 0x2c) = uVar4 - uVar3;
        *(int *)(param_3 + 0x30) = *(int *)(param_3 + 0x30) + 4;
      }
      param_4[3] = 4;
      uVar2 = 1;
      goto LAB_0040d64a;
    }
LAB_0040d642:
    *(char *)(param_3 + 0x20) = '\x01';
  }
  uVar2 = 0;
LAB_0040d64a:
  return CONCAT44(param_2,uVar2);
}


/*
 * FUN_0040d660 at 0040d660
 * undefined __cdecl FUN_0040d660(int * param_1, undefined1 * param_2)
 * Address ranges: 0040d660-0040d72e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */


void __cdecl FUN_0040d660(int *param_1,undefined1 *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined2 uVar3;
  uint uVar4;
  
  DAT_0040e9d0._0_2_ = (short)param_1[0x1d04];
  uVar3 = CONCAT11(*param_2,*param_2);
  *(undefined2 *)((int)param_1 + 0x7426) = uVar3;
  *(undefined2 *)((int)param_1 + 0x7436) = uVar3;
  puVar2 = (uint *)((int)param_1 + *param_1 + 0x7468);
  for (uVar4 = (uint)param_1[1] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *puVar2;
    if ((short)DAT_0040e9d0 != (short)uVar1) {
      *(ushort *)((int)puVar2 + 2) = CONCAT11(param_2[uVar1 >> 8 & 0xff],param_2[uVar1 & 0xff]);
    }
    puVar2 = puVar2 + 1;
  }
  puVar2 = (uint *)((int)param_1 + *param_1 + param_1[1] + 0x7468);
  for (uVar4 = (uint)param_1[2] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *puVar2;
    if ((short)DAT_0040e9d0 != (short)uVar1) {
      *(ushort *)((int)puVar2 + 2) = CONCAT11(param_2[uVar1 >> 8 & 0xff],param_2[uVar1 & 0xff]);
    }
    puVar2 = puVar2 + 1;
  }
  puVar2 = (uint *)((int)param_1 + *param_1 + param_1[1] + param_1[2] + 0x7468);
  for (uVar4 = (uint)param_1[3] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *puVar2;
    if (((short)DAT_0040e9d0 != (short)uVar1) && ((uVar1 & 3) == 3)) {
      *(undefined1 *)((int)puVar2 + 3) = param_2[uVar1 >> 8 & 0xff];
    }
    puVar2 = puVar2 + 1;
  }
  return;
}


/*
 * KERNEL32.DLL::ExitThread at 0040d892
 * noreturn void __stdcall ExitThread(DWORD dwExitCode)
 * Address ranges: 0040d892-0040d897
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ExitThread
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 */


void ExitThread(DWORD dwExitCode)

{
                    /* WARNING: Could not recover jumptable at 0x0040d892. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  ExitThread(dwExitCode);
  return;
}


/*
 * KERNEL32.DLL::CreateThread at 0040d898
 * HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
 * Address ranges: 0040d898-0040d89d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CreateThread
 */


HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,
                   LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,
                   LPDWORD lpThreadId)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateThread(lpThreadAttributes,dwStackSize,lpStartAddress,lpParameter,dwCreationFlags,
                        lpThreadId);
  return pvVar1;
}


/*
 * KERNEL32.DLL::CreateEventA at 0040d89e
 * HANDLE __stdcall CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName)
 * Address ranges: 0040d89e-0040d8a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CreateEventA
 */


HANDLE CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,BOOL bManualReset,BOOL bInitialState,
                   LPCSTR lpName)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d89e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateEventA(lpEventAttributes,bManualReset,bInitialState,lpName);
  return pvVar1;
}


/*
 * KERNEL32.DLL::GetCurrentThread at 0040d8a4
 * HANDLE __stdcall GetCurrentThread(void)
 * Address ranges: 0040d8a4-0040d8a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCurrentThread
 */


HANDLE GetCurrentThread(void)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetCurrentThread();
  return pvVar1;
}


/*
 * KERNEL32.DLL::SetEvent at 0040d8aa
 * BOOL __stdcall SetEvent(HANDLE hEvent)
 * Address ranges: 0040d8aa-0040d8af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetEvent
 */


BOOL SetEvent(HANDLE hEvent)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetEvent(hEvent);
  return BVar1;
}


/*
 * USER32.DLL::MessageBoxA at 0040d8bc
 * int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
 * Address ranges: 0040d8bc-0040d8c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::MessageBoxA
 */


int MessageBoxA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MessageBoxA(hWnd,lpText,lpCaption,uType);
  return iVar1;
}


/*
 * KERNEL32.DLL::VirtualFree at 0040d8c2
 * BOOL __stdcall VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType)
 * Address ranges: 0040d8c2-0040d8c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::VirtualFree
 */


BOOL VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = VirtualFree(lpAddress,dwSize,dwFreeType);
  return BVar1;
}


/*
 * KERNEL32.DLL::TlsFree at 0040d8c8
 * BOOL __stdcall TlsFree(DWORD dwTlsIndex)
 * Address ranges: 0040d8c8-0040d8cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsFree
 */


BOOL TlsFree(DWORD dwTlsIndex)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = TlsFree(dwTlsIndex);
  return BVar1;
}


/*
 * KERNEL32.DLL::TlsSetValue at 0040d8ce
 * BOOL __stdcall TlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
 * Address ranges: 0040d8ce-0040d8d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsSetValue
 */


BOOL TlsSetValue(DWORD dwTlsIndex,LPVOID lpTlsValue)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = TlsSetValue(dwTlsIndex,lpTlsValue);
  return BVar1;
}


/*
 * KERNEL32.DLL::TlsAlloc at 0040d8d4
 * DWORD __stdcall TlsAlloc(void)
 * Address ranges: 0040d8d4-0040d8d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsAlloc
 */


DWORD TlsAlloc(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = TlsAlloc();
  return DVar1;
}


/*
 * KERNEL32.DLL::TlsGetValue at 0040d8da
 * LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
 * Address ranges: 0040d8da-0040d8df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::TlsGetValue
 */


LPVOID TlsGetValue(DWORD dwTlsIndex)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = TlsGetValue(dwTlsIndex);
  return pvVar1;
}


/*
 * KERNEL32.DLL::ReleaseMutex at 0040d8e0
 * BOOL __stdcall ReleaseMutex(HANDLE hMutex)
 * Address ranges: 0040d8e0-0040d8e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ReleaseMutex
 */


BOOL ReleaseMutex(HANDLE hMutex)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ReleaseMutex(hMutex);
  return BVar1;
}


/*
 * KERNEL32.DLL::WaitForSingleObject at 0040d8e6
 * DWORD __stdcall WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
 * Address ranges: 0040d8e6-0040d8eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::WaitForSingleObject
 */


DWORD WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = WaitForSingleObject(hHandle,dwMilliseconds);
  return DVar1;
}


/*
 * KERNEL32.DLL::CreateMutexA at 0040d8ec
 * HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
 * Address ranges: 0040d8ec-0040d8f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CreateMutexA
 */


HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCSTR lpName)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateMutexA(lpMutexAttributes,bInitialOwner,lpName);
  return pvVar1;
}


/*
 * KERNEL32.DLL::GetCurrentThreadId at 0040d8f2
 * DWORD __stdcall GetCurrentThreadId(void)
 * Address ranges: 0040d8f2-0040d8f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCurrentThreadId
 */


DWORD GetCurrentThreadId(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetCurrentThreadId();
  return DVar1;
}


/*
 * KERNEL32.DLL::CloseHandle at 0040d8f8
 * BOOL __stdcall CloseHandle(HANDLE hObject)
 * Address ranges: 0040d8f8-0040d8fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::CloseHandle
 */


BOOL CloseHandle(HANDLE hObject)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = CloseHandle(hObject);
  return BVar1;
}


/*
 * KERNEL32.DLL::GetStdHandle at 0040d8fe
 * HANDLE __stdcall GetStdHandle(DWORD nStdHandle)
 * Address ranges: 0040d8fe-0040d903
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetStdHandle
 */


HANDLE GetStdHandle(DWORD nStdHandle)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d8fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetStdHandle(nStdHandle);
  return pvVar1;
}


/*
 * KERNEL32.DLL::WriteFile at 0040d90a
 * BOOL __stdcall WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
 * Address ranges: 0040d90a-0040d90f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::WriteFile
 */


BOOL WriteFile(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,
              LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d90a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = WriteFile(hFile,lpBuffer,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);
  return BVar1;
}


/*
 * KERNEL32.DLL::SetConsoleCtrlHandler at 0040d928
 * BOOL __stdcall SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine, BOOL Add)
 * Address ranges: 0040d928-0040d92d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::SetConsoleCtrlHandler
 */


BOOL SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,BOOL Add)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d928. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetConsoleCtrlHandler(HandlerRoutine,Add);
  return BVar1;
}


/*
 * KERNEL32.DLL::VirtualAlloc at 0040d92e
 * LPVOID __stdcall VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
 * Address ranges: 0040d92e-0040d933
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::VirtualAlloc
 */


LPVOID VirtualAlloc(LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d92e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = VirtualAlloc(lpAddress,dwSize,flAllocationType,flProtect);
  return pvVar1;
}


/*
 * KERNEL32.DLL::GetVersion at 0040d93a
 * DWORD __stdcall GetVersion(void)
 * Address ranges: 0040d93a-0040d93f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetVersion
 */


DWORD GetVersion(void)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d93a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetVersion();
  return DVar1;
}


/*
 * KERNEL32.DLL::GetCommandLineA at 0040d940
 * LPSTR __stdcall GetCommandLineA(void)
 * Address ranges: 0040d940-0040d945
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCommandLineA
 */


LPSTR GetCommandLineA(void)

{
  LPSTR pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetCommandLineA();
  return pCVar1;
}


/*
 * KERNEL32.DLL::GetModuleFileNameA at 0040d946
 * DWORD __stdcall GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
 * Address ranges: 0040d946-0040d94b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetModuleFileNameA
 */


DWORD GetModuleFileNameA(HMODULE hModule,LPSTR lpFilename,DWORD nSize)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d946. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetModuleFileNameA(hModule,lpFilename,nSize);
  return DVar1;
}


/*
 * KERNEL32.DLL::GetEnvironmentStrings at 0040d94c
 * LPCH __stdcall GetEnvironmentStrings(void)
 * Address ranges: 0040d94c-0040d951
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetEnvironmentStrings
 */


LPCH GetEnvironmentStrings(void)

{
  LPCH pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040d94c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetEnvironmentStrings();
  return pCVar1;
}


/*
 * KERNEL32.DLL::ExitProcess at 0040d952
 * noreturn void __stdcall ExitProcess(UINT uExitCode)
 * Address ranges: 0040d952-0040d957
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::ExitProcess
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 */


void ExitProcess(UINT uExitCode)

{
                    /* WARNING: Could not recover jumptable at 0x0040d952. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  ExitProcess(uExitCode);
  return;
}


