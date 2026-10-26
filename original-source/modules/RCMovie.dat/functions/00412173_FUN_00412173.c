/*
 * FUN_00412173 at 00412173
 * undefined __cdecl FUN_00412173(int param_1, LPCSTR param_2, int param_3, int param_4)
 * Address ranges: 00412173-004122f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00412173(int param_1,LPCSTR param_2,int param_3,int param_4)

{
  HDC hdc;
  tagRECT local_14;
  
  if (((*(int *)(DAT_0043d850 + 0x18 + param_1 * 0x1c) == 0) || (param_1 < 0)) ||
     (DAT_0043d84c < param_1)) {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__con_004343b4);
  }
  GetClientRect(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),&local_14);
  hdc = GetDC(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c));
  if (*(int *)(&DAT_00435820 + param_3 * 0x10) != 0) {
    SelectObject(hdc,*(HGDIOBJ *)(&DAT_00435820 + param_3 * 0x10));
    SetTextColor(hdc,*(COLORREF *)(&DAT_0043582c + param_3 * 0x10));
    SetBkColor(hdc,*(COLORREF *)(&DAT_00435828 + param_3 * 0x10));
    SetBkMode(hdc,*(int *)(&DAT_00435824 + param_3 * 0x10));
  }
  if (param_4 == 0) {
    DrawTextA(hdc,param_2,-1,&local_14,0x25);
  }
  else if (param_4 == 1) {
    DrawTextA(hdc,param_2,-1,&local_14,0x24);
  }
  else if (param_4 == 2) {
    DrawTextA(hdc,param_2,-1,&local_14,0x26);
  }
  else {
    DrawTextA(hdc,param_2,-1,&local_14,0x25);
  }
  ReleaseDC(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),hdc);
  return;
}

