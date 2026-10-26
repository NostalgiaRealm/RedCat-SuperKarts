/*
 * FUN_0045e1c8 at 0045e1c8
 * undefined __register FUN_0045e1c8(int * param_1)
 * Address ranges: 0045e1c8-0045e232
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e1c8(int *param_1)

{
  HRGN pHVar1;
  HWND hWnd;
  BOOL bRedraw;
  
  FUN_004258e0(param_1);
  param_1[0x85] = 0;
  if ((param_1[0x82] != 0) && (*(int *)(param_1[0x82] + 0x40) != 0)) {
    pHVar1 = CreateRectRgn(0,0,1,1);
    param_1[0x85] = (int)pHVar1;
    CombineRgn(pHVar1,*(HRGN *)(param_1[0x82] + 0x40),(HRGN)0x0,5);
  }
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    bRedraw = -1;
    pHVar1 = (HRGN)param_1[0x85];
    hWnd = (HWND)FUN_00445724(param_1);
    SetWindowRgn(hWnd,pHVar1,bRedraw);
  }
  return;
}

