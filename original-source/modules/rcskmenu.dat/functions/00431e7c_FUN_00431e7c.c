/*
 * FUN_00431e7c at 00431e7c
 * undefined __register FUN_00431e7c(int param_1)
 * Address ranges: 00431e7c-00431eb4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431e7c(int param_1)

{
  HWND hWnd;
  BOOL BVar1;
  
  if (*(HWND *)(param_1 + 0x24) != (HWND)0x0) {
    hWnd = GetLastActivePopup(*(HWND *)(param_1 + 0x24));
    if ((hWnd != (HWND)0x0) && (hWnd != *(HWND *)(param_1 + 0x24))) {
      BVar1 = IsWindowVisible(hWnd);
      if (BVar1 != 0) {
        BVar1 = IsWindowEnabled(hWnd);
        if (BVar1 != 0) {
          SetForegroundWindow(hWnd);
        }
      }
    }
  }
  return;
}

