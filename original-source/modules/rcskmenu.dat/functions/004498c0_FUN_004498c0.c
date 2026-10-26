/*
 * FUN_004498c0 at 004498c0
 * undefined __register FUN_004498c0(undefined4 param_1, HWND param_2)
 * Address ranges: 004498c0-004498e4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004498c0(undefined4 param_1,HWND param_2)

{
  HWND pHVar1;
  
  pHVar1 = (HWND)FUN_00449844();
  if (param_2 != pHVar1) {
    if (param_2 == (HWND)0x0) {
      ReleaseCapture();
    }
    else {
      SetCapture(param_2);
    }
  }
  return;
}

