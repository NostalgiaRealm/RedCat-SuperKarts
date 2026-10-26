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

