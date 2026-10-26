/*
 * FUN_0042dcc0 at 0042dcc0
 * undefined __register FUN_0042dcc0(int * param_1, int param_2)
 * Address ranges: 0042dcc0-0042dd4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042dcc0(int *param_1,int param_2)

{
  byte bVar1;
  HWND pHVar2;
  BOOL BVar3;
  HWND hWndInsertAfter;
  int X;
  int Y;
  int cx;
  int cy;
  WPARAM wParam;
  UINT UVar4;
  LPARAM lParam;
  
  if (((*(int *)(param_2 + 4) == 2) && (*(char *)((int)param_1 + 0x8b) == '\x01')) &&
     ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
    pHVar2 = (HWND)FUN_00445724(param_1);
    BVar3 = IsIconic(pHVar2);
    if (BVar3 == 0) {
      UVar4 = 7;
      cy = 0;
      cx = 0;
      Y = 0;
      X = 0;
      hWndInsertAfter = (HWND)0x0;
      pHVar2 = (HWND)FUN_00445724(param_1);
      SetWindowPos(pHVar2,hWndInsertAfter,X,Y,cx,cy,UVar4);
      lParam = *(LPARAM *)(param_2 + 8);
      wParam = *(WPARAM *)(param_2 + 4);
      UVar4 = 0xa2;
      pHVar2 = (HWND)FUN_00445724(param_1);
      PostMessageA(pHVar2,UVar4,wParam,lParam);
      if (*(char *)((int)param_1 + 0x216) == '\0') {
        return;
      }
      bVar1 = (**(code **)(*param_1 + 0x50))();
      FUN_0043fc90(param_1,bVar1 ^ 1,-1);
      return;
    }
  }
  FUN_00440a50(param_1,param_2);
  return;
}

