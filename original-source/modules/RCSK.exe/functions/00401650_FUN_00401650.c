/*
 * FUN_00401650 at 00401650
 * undefined FUN_00401650(void)
 * Address ranges: 00401650-004016e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LRESULT FUN_00401650(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  tagPAINTSTRUCT tStack_40;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      BeginPaint(param_1,&tStack_40);
      EndPaint(param_1,&tStack_40);
      return 0;
    }
    if (param_2 == 1) {
      return 0;
    }
    if (param_2 == 2) {
      PostQuitMessage(0);
      return 0;
    }
  }
  else {
    if (param_2 == 0x10) {
      DestroyWindow(param_1);
      return 0;
    }
    if (param_2 == 0x200) {
      SetCursor((HCURSOR)0x0);
      return 0;
    }
  }
  LVar1 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar1;
}

