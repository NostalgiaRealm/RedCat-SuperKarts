/*
 * FUN_00423ac0 at 00423ac0
 * undefined __register FUN_00423ac0(int * param_1, byte param_2)
 * Address ranges: 00423ac0-00423af5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423ac0(int *param_1,byte param_2)

{
  bool bVar1;
  uint wParam;
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    lParam = 0;
    wParam = (uint)param_2;
    Msg = 0xb9;
    hWnd = (HWND)FUN_00445724(param_1);
    SendMessageA(hWnd,Msg,wParam,lParam);
    return;
  }
  *(byte *)((int)param_1 + 0x1fd) = param_2;
  return;
}

