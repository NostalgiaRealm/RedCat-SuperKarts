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

