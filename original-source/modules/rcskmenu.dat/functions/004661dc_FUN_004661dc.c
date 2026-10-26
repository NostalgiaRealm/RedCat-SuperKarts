/*
 * FUN_004661dc at 004661dc
 * undefined __register FUN_004661dc(int * param_1, int param_2)
 * Address ranges: 004661dc-00466206
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004661dc(int *param_1,int param_2)

{
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  int lParam;
  
  (**(code **)(*param_1 + 0x40))(param_1,param_2);
  wParam = 0;
  Msg = 0x1328;
  lParam = param_2;
  hWnd = (HWND)FUN_00445724(param_1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 2;
  return;
}

