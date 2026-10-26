/*
 * FUN_004669e4 at 004669e4
 * undefined __register FUN_004669e4(int * param_1, undefined4 param_2)
 * Address ranges: 004669e4-00466a02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004669e4(int *param_1,undefined4 param_2)

{
  HWND hWnd;
  RECT *lprcUpdate;
  HRGN hrgnUpdate;
  UINT flags;
  
  FUN_00443b74(param_1,param_2);
  flags = 5;
  hrgnUpdate = (HRGN)0x0;
  lprcUpdate = (RECT *)0x0;
  hWnd = (HWND)FUN_00445724(param_1);
  RedrawWindow(hWnd,lprcUpdate,hrgnUpdate,flags);
  return;
}

