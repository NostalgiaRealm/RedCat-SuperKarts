/*
 * FUN_00424130 at 00424130
 * undefined FUN_00424130(void)
 * Address ranges: 00424130-0042416e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424130(int *param_1)

{
  HWND pHVar1;
  uint uVar2;
  UINT Msg;
  WPARAM wParam;
  int nIndex;
  LPARAM lParam;
  
  (**(code **)(*param_1 + -0x10))();
  if (*PTR_DAT_0047c7a0 != '\0') {
    nIndex = -0x10;
    pHVar1 = (HWND)FUN_00445724(param_1);
    uVar2 = GetWindowLongA(pHVar1,nIndex);
    if ((uVar2 & 4) == 0) {
      lParam = 0;
      wParam = 3;
      Msg = 0xd3;
      pHVar1 = (HWND)FUN_00445724(param_1);
      SendMessageA(pHVar1,Msg,wParam,lParam);
    }
  }
  return;
}

