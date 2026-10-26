/*
 * FUN_00431408 at 00431408
 * undefined __register FUN_00431408(int param_1, undefined1 param_2)
 * Address ranges: 00431408-004314af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431408(int param_1,undefined1 param_2)

{
  uint uVar1;
  HWND hWnd;
  int iVar2;
  HWND hWndInsertAfter;
  int X;
  int Y;
  int cx;
  int cy;
  UINT uFlags;
  HWND local_10;
  undefined1 local_c;
  
  if (*(int *)(DAT_0047d770 + 0x24) != 0) {
    if (*(int *)(param_1 + 0x84) == 0) {
      local_10 = *(HWND *)(param_1 + 0x24);
      local_c = param_2;
      EnumWindows(FUN_00431398,(LPARAM)&local_10);
      if (*(int *)(*(int *)(param_1 + 0x80) + 8) != 0) {
        local_10 = GetWindow(local_10,3);
        uVar1 = GetWindowLongA(local_10,-0x14);
        if ((uVar1 & 8) != 0) {
          local_10 = (HWND)0xfffffffe;
        }
        iVar2 = *(int *)(*(int *)(param_1 + 0x80) + 8) + -1;
        if (-1 < iVar2) {
          do {
            uFlags = 0x13;
            cy = 0;
            cx = 0;
            Y = 0;
            X = 0;
            hWndInsertAfter = local_10;
            hWnd = (HWND)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x80),iVar2);
            SetWindowPos(hWnd,hWndInsertAfter,X,Y,cx,cy,uFlags);
            iVar2 = iVar2 + -1;
          } while (iVar2 != -1);
        }
      }
    }
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
  }
  return;
}

