/*
 * FUN_00465e74 at 00465e74
 * undefined FUN_00465e74(void)
 * Address ranges: 00465e74-00465eb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00465e74(int param_1,byte param_2)

{
  int *piVar1;
  uint wParam;
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  piVar1 = *(int **)(param_1 + 0xc);
  *(byte *)(piVar1 + 0x86) = param_2;
  lParam = 0;
  wParam = (param_2 ^ 1) & 0x7f;
  Msg = 0xb;
  hWnd = (HWND)FUN_00445724(piVar1);
  SendMessageA(hWnd,Msg,wParam,lParam);
  if (param_2 != 1) {
    (**(code **)(**(int **)(param_1 + 0xc) + 0x74))();
    FUN_004666d8(*(int **)(param_1 + 0xc));
  }
  return;
}

