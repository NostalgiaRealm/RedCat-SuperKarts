/*
 * FUN_0045fe38 at 0045fe38
 * undefined __register FUN_0045fe38(int * param_1)
 * Address ranges: 0045fe38-0045feb6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045fe38(int *param_1)

{
  POINT pt;
  BOOL BVar1;
  HWND hWnd;
  undefined4 extraout_ECX;
  UINT_PTR uIDEvent;
  tagPOINT local_24;
  LONG local_1c;
  LONG local_18;
  RECT local_14;
  
  GetCursorPos(&local_24);
  FUN_0043f1f0(param_1,&local_24.x,&local_1c);
  local_24.x = local_1c;
  local_24.y = local_18;
  FUN_0043f054(param_1[0x84],&local_14.left);
  pt.y = local_18;
  pt.x = local_1c;
  BVar1 = PtInRect(&local_14,pt);
  if (BVar1 == 0) {
    FUN_00403088(param_1,0,CONCAT31((int3)((uint)extraout_ECX >> 8),8));
  }
  else {
    uIDEvent = 2;
    hWnd = (HWND)FUN_00445724(param_1);
    KillTimer(hWnd,uIDEvent);
  }
  return;
}

