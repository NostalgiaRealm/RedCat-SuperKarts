/*
 * FUN_00424744 at 00424744
 * undefined __register FUN_00424744(int * param_1, WPARAM param_2)
 * Address ranges: 00424744-0042476c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424744(int *param_1,WPARAM param_2)

{
  WPARAM WVar1;
  HWND hWnd;
  UINT Msg;
  LPARAM lParam;
  
  WVar1 = FUN_00424728(param_1);
  if (param_2 != WVar1) {
    lParam = 0;
    Msg = 0x14e;
    hWnd = (HWND)FUN_00445724(param_1);
    SendMessageA(hWnd,Msg,param_2,lParam);
  }
  return;
}

