/*
 * FUN_00406c80 at 00406c80
 * HWND __register FUN_00406c80(UINT * param_1, UINT * param_2, UINT * param_3, LRESULT * param_4, LRESULT * param_5)
 * Address ranges: 00406c80-00406d19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HWND FUN_00406c80(UINT *param_1,UINT *param_2,UINT *param_3,LRESULT *param_4,LRESULT *param_5)

{
  HWND hWnd;
  UINT UVar1;
  LRESULT LVar2;
  
  hWnd = FindWindowA("MouseZ","Magellan MSWHEEL");
  UVar1 = RegisterWindowMessageA("MSWHEEL_ROLLMSG");
  *param_1 = UVar1;
  UVar1 = RegisterWindowMessageA("MSH_WHEELSUPPORT_MSG");
  *param_2 = UVar1;
  UVar1 = RegisterWindowMessageA("MSH_SCROLL_LINES_MSG");
  *param_3 = UVar1;
  if ((*param_2 == 0) || (hWnd == (HWND)0x0)) {
    *param_5 = 0;
  }
  else {
    LVar2 = SendMessageA(hWnd,*param_2,0,0);
    *param_5 = LVar2;
  }
  if ((*param_3 == 0) || (hWnd == (HWND)0x0)) {
    *param_4 = 3;
  }
  else {
    LVar2 = SendMessageA(hWnd,*param_3,0,0);
    *param_4 = LVar2;
  }
  return hWnd;
}

