/*
 * FUN_0042f6c4 at 0042f6c4
 * undefined FUN_0042f6c4(void)
 * Address ranges: 0042f6c4-0042f758
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f6c4(int *param_1,int param_2)

{
  HWND pHVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  HWND hWndInsertAfter;
  int Y;
  int cx;
  int cy;
  WPARAM wParam;
  UINT UVar5;
  LPARAM lParam;
  
  if (((*(int *)(param_2 + 4) == 2) && (*(char *)((int)param_1 + 0x8b) != '\x01')) &&
     ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
    pHVar1 = (HWND)FUN_00445724(param_1);
    BVar2 = IsIconic(pHVar1);
    if ((BVar2 == 0) && (iVar3 = FUN_0044401c((int)param_1), 0 < iVar3)) {
      UVar5 = 7;
      cy = 0;
      cx = 0;
      Y = 0;
      iVar3 = 0;
      hWndInsertAfter = (HWND)0x0;
      pHVar1 = (HWND)FUN_00445724(param_1);
      SetWindowPos(pHVar1,hWndInsertAfter,iVar3,Y,cx,cy,UVar5);
      lParam = *(LPARAM *)(param_2 + 8);
      wParam = *(WPARAM *)(param_2 + 4);
      UVar5 = 0xa2;
      pHVar1 = (HWND)FUN_00445724(param_1);
      PostMessageA(pHVar1,UVar5,wParam,lParam);
      if (*(char *)((int)param_1 + 0x216) == '\0') {
        return;
      }
      piVar4 = (int *)FUN_00444030((int)param_1,0);
      FUN_0043fc90(piVar4,'\x01',-1);
      return;
    }
  }
  FUN_0042dcc0(param_1,param_2);
  return;
}

