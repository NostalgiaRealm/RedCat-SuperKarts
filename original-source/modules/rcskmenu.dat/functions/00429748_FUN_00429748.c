/*
 * FUN_00429748 at 00429748
 * undefined __register FUN_00429748(HWND param_1)
 * Address ranges: 00429748-0042976d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429748(HWND param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)GetWindowLongA(param_1,-4);
  DestroyWindow(param_1);
  if (pcVar1 != DefWindowProcA) {
    FUN_00429670((int)pcVar1);
  }
  return;
}

