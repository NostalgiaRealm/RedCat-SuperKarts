/*
 * FUN_00445804 at 00445804
 * undefined __register FUN_00445804(int * param_1)
 * Address ranges: 00445804-00445841
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445804(int *param_1)

{
  bool bVar1;
  HWND hWnd;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  HWND hWndInsertAfter;
  int X;
  int Y;
  int cx;
  int cy;
  UINT uFlags;
  
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    bVar1 = FUN_00445a20((int)param_1);
    if (bVar1) {
      uFlags = 0x16;
      cy = param_1[0xf];
      cx = param_1[0xe];
      Y = 0;
      X = 0;
      hWndInsertAfter = (HWND)0x0;
      hWnd = (HWND)FUN_00445724(param_1);
      SetWindowPos(hWnd,hWndInsertAfter,X,Y,cx,cy,uFlags);
      FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    }
  }
  return;
}

