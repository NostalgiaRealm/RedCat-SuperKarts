/*
 * FUN_0043cd50 at 0043cd50
 * HWND __register FUN_0043cd50(void)
 * Address ranges: 0043cd50-0043cd67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HWND FUN_0043cd50(void)

{
  HWND hWnd;
  
  hWnd = FUN_00429694();
  SetCapture(hWnd);
  return hWnd;
}

