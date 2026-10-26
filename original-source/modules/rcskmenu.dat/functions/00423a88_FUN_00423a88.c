/*
 * FUN_00423a88 at 00423a88
 * undefined1 __register FUN_00423a88(int * param_1)
 * Address ranges: 00423a88-00423abc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00423a88(int *param_1)

{
  bool bVar1;
  HWND hWnd;
  LRESULT LVar2;
  undefined1 uVar3;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  uVar3 = *(undefined1 *)((int)param_1 + 0x1fd);
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    lParam = 0;
    wParam = 0;
    Msg = 0xb8;
    hWnd = (HWND)FUN_00445724(param_1);
    LVar2 = SendMessageA(hWnd,Msg,wParam,lParam);
    uVar3 = LVar2 != 0;
  }
  return uVar3;
}

