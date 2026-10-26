/*
 * FUN_004666d8 at 004666d8
 * undefined __register FUN_004666d8(int * param_1)
 * Address ranges: 004666d8-00466716
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004666d8(int *param_1)

{
  bool bVar1;
  LPARAM lParam;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  
  if ((char)param_1[0x86] == '\0') {
    bVar1 = FUN_00445a20((int)param_1);
    if (bVar1) {
      lParam = CONCAT22((short)param_1[0xf],(short)param_1[0xe]);
      wParam = 0;
      Msg = 5;
      hWnd = (HWND)FUN_00445724(param_1);
      SendMessageA(hWnd,Msg,wParam,lParam);
    }
    FUN_0044221c(param_1);
  }
  return;
}

