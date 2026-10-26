/*
 * FUN_00444da0 at 00444da0
 * undefined __register FUN_00444da0(int * param_1)
 * Address ranges: 00444da0-00444dcf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444da0(int *param_1)

{
  bool bVar1;
  HWND hWnd;
  HWND hWndInsertAfter;
  int X;
  int Y;
  int cx;
  int cy;
  UINT uFlags;
  
  (**(code **)(*param_1 + -0x10))();
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    uFlags = 0x37;
    cy = 0;
    cx = 0;
    Y = 0;
    X = 0;
    hWndInsertAfter = (HWND)0x0;
    hWnd = (HWND)FUN_00445724(param_1);
    SetWindowPos(hWnd,hWndInsertAfter,X,Y,cx,cy,uFlags);
  }
  return;
}

