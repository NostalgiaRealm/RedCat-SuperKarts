/*
 * FUN_0046655c at 0046655c
 * undefined __register FUN_0046655c(int * param_1, WPARAM param_2)
 * Address ranges: 0046655c-00466579
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046655c(int *param_1,WPARAM param_2)

{
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  lParam = 0;
  Msg = 0x130c;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,param_2,lParam);
  return;
}

