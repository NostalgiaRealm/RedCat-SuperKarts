/*
 * FUN_0041a415 at 0041a415
 * undefined __cdecl FUN_0041a415(int param_1, undefined2 * param_2, undefined2 param_3)
 * Address ranges: 0041a415-0041a480
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041a415(int param_1,undefined2 *param_2,undefined2 param_3)

{
  int iVar1;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  
  iVar1 = FUN_004128fa(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004128fa(param_1);
    if (iVar1 != 3) {
      FUN_0040187a((byte *)s__s__d_____get_edit_box_text__con_00436328);
    }
  }
  *param_2 = param_3;
  wParam = 0;
  Msg = 0xc4;
  hWnd = (HWND)FUN_004129a2(param_1);
  SendMessageA(hWnd,Msg,wParam,(LPARAM)param_2);
  return;
}

