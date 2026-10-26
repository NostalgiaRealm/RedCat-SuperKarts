/*
 * FUN_004607a8 at 004607a8
 * undefined __register FUN_004607a8(int * param_1, int param_2)
 * Address ranges: 004607a8-004607e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004607a8(int *param_1,int param_2)

{
  uint *puVar1;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  if ((char)param_1[0x7e] != '\0') {
    puVar1 = (uint *)(*(int *)(param_2 + 8) + 0x18);
    *puVar1 = *puVar1 | 0x100;
    *(undefined4 *)(param_2 + 0xc) = 0;
    return;
  }
  FUN_00443b24(param_1,param_2);
  lParam = 0;
  wParam = 0;
  Msg = 0x85;
  hWnd = (HWND)FUN_00445724(param_1);
  PostMessageA(hWnd,Msg,wParam,lParam);
  return;
}

