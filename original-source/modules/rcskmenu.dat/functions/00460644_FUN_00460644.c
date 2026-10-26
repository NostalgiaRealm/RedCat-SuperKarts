/*
 * FUN_00460644 at 00460644
 * undefined FUN_00460644(void)
 * Address ranges: 00460644-0046069b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460644(int param_1)

{
  bool bVar1;
  HWND hWnd;
  RECT *lpRect;
  BOOL bErase;
  RECT RStack_18;
  
  lpRect = &RStack_18;
  if (*(int *)(param_1 + 0x24) != 0) {
    bVar1 = FUN_00445a20(*(int *)(param_1 + 0x24));
    if (bVar1) {
      bVar1 = FUN_0046063c(param_1);
      if ((!bVar1) && (*(char *)(param_1 + 0x1f8) != '\0')) {
        FUN_0043f054(param_1,&RStack_18.left);
        bErase = -1;
        hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 0x24));
        InvalidateRect(hWnd,lpRect,bErase);
      }
    }
  }
  FUN_00445598(param_1);
  return;
}

