/*
 * FUN_00431d8c at 00431d8c
 * undefined __register FUN_00431d8c(int param_1)
 * Address ranges: 00431d8c-00431e79
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431d8c(int param_1)

{
  int *piVar1;
  BOOL BVar2;
  uint uVar3;
  int cx;
  int X;
  HWND hWnd;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int Y;
  int cy;
  UINT uFlags;
  
  BVar2 = IsIconic(*(HWND *)(param_1 + 0x24));
  if (BVar2 != 0) {
    SetActiveWindow(*(HWND *)(param_1 + 0x24));
    if ((*(int *)(param_1 + 0x38) == 0) ||
       ((*(char *)(param_1 + 0x4b) == '\0' && (*(char *)(*(int *)(param_1 + 0x38) + 0x47) == '\0')))
       ) {
      FUN_00430ee0(*(HWND *)(param_1 + 0x24),9);
    }
    else {
      DefWindowProcA(*(HWND *)(param_1 + 0x24),0x112,0xf120,0);
    }
    uFlags = 0;
    cy = 1;
    uVar3 = (**(code **)PTR_DAT_0047c734)();
    cx = (int)uVar3 >> 1;
    if (cx < 0) {
      cx = cx + (uint)((uVar3 & 1) != 0);
    }
    Y = 0;
    uVar3 = (**(code **)PTR_DAT_0047c734)();
    X = (int)uVar3 >> 1;
    if (X < 0) {
      X = X + (uint)((uVar3 & 1) != 0);
    }
    SetWindowPos(*(HWND *)(param_1 + 0x24),(HWND)0x0,X,Y,cx,cy,uFlags);
    piVar1 = *(int **)(param_1 + 0x38);
    if (((piVar1 != (int *)0x0) && (*(char *)((int)piVar1 + 0x213) == '\x01')) &&
       (*(char *)((int)piVar1 + 0x47) == '\0')) {
      FUN_0042ca2c(piVar1,0);
      FUN_0042ecd0(*(int **)(param_1 + 0x38),extraout_EDX,extraout_ECX);
    }
    FUN_004314c0(param_1);
    if (*(int **)(DAT_0047d774 + 0x58) != (int *)0x0) {
      hWnd = (HWND)FUN_00445724(*(int **)(DAT_0047d774 + 0x58));
      SetFocus(hWnd);
    }
    if (*(short *)(param_1 + 0xfa) != 0) {
      (**(code **)(param_1 + 0xf8))(*(undefined4 *)(param_1 + 0xfc),param_1);
    }
  }
  return;
}

