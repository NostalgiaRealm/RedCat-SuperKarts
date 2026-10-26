/*
 * FUN_00445a2c at 00445a2c
 * undefined __register FUN_00445a2c(int param_1)
 * Address ranges: 00445a2c-00445ae3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445a2c(int param_1)

{
  BOOL BVar1;
  uint uVar2;
  HWND hWnd;
  int iVar3;
  RECT *pRVar4;
  LONG *pLVar5;
  undefined1 local_48 [12];
  int local_3c;
  WINDOWPLACEMENT local_38;
  
  BVar1 = IsIconic(*(HWND *)(param_1 + 0x14c));
  if (BVar1 == 0) {
    GetWindowRect(*(HWND *)(param_1 + 0x14c),(LPRECT)local_48);
  }
  else {
    local_38.length = 0x2c;
    GetWindowPlacement(*(HWND *)(param_1 + 0x14c),&local_38);
    pRVar4 = &local_38.rcNormalPosition;
    pLVar5 = (LONG *)local_48;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pLVar5 = pRVar4->left;
      pRVar4 = (RECT *)&pRVar4->top;
      pLVar5 = pLVar5 + 1;
    }
  }
  uVar2 = GetWindowLongA(*(HWND *)(param_1 + 0x14c),-0x10);
  if (((uVar2 & 0x40000000) != 0) &&
     (hWnd = (HWND)GetWindowLongA(*(HWND *)(param_1 + 0x14c),-8), hWnd != (HWND)0x0)) {
    ScreenToClient(hWnd,(LPPOINT)local_48);
    ScreenToClient(hWnd,(LPPOINT)(local_48 + 8));
  }
  *(undefined4 *)(param_1 + 0x30) = local_48._0_4_;
  *(undefined4 *)(param_1 + 0x34) = local_48._4_4_;
  *(undefined4 *)(param_1 + 0x38) = local_48._8_4_ - local_48._0_4_;
  *(int *)(param_1 + 0x3c) = local_3c - local_48._4_4_;
  FUN_0043ed90(param_1);
  return;
}

