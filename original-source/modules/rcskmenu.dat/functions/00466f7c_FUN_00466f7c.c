/*
 * FUN_00466f7c at 00466f7c
 * undefined __register FUN_00466f7c(int param_1, byte param_2)
 * Address ranges: 00466f7c-00466fba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466f7c(int param_1,byte param_2)

{
  uint lParam;
  WPARAM wParam;
  HWND hWnd;
  UINT Msg;
  
  if ((*(byte *)(param_1 + 0x20) & 2) == 0) {
    lParam = FUN_00406bb0((uint)param_2,0);
    wParam = FUN_00466cc0(param_1);
    Msg = 0x1333;
    hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 500));
    SendMessageA(hWnd,Msg,wParam,lParam);
  }
  *(byte *)(param_1 + 0x1fa) = param_2;
  return;
}

