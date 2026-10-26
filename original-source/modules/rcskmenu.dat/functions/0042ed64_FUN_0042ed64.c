/*
 * FUN_0042ed64 at 0042ed64
 * undefined __register FUN_0042ed64(int * param_1)
 * Address ranges: 0042ed64-0042ed7e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ed64(int *param_1)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  lParam = 0;
  wParam = 0;
  Msg = 0xb021;
  hWnd = (HWND)FUN_00445724(param_1);
  PostMessageA(hWnd,Msg,wParam,lParam);
  return;
}

