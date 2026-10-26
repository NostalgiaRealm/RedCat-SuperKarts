/*
 * FUN_00429500 at 00429500
 * undefined1 __register FUN_00429500(void)
 * Address ranges: 00429500-00429529
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00429500(void)

{
  DWORD dwThreadId;
  code *lpfn;
  HWND *lParam;
  HWND local_8;
  undefined1 local_4;
  
  local_8 = GetActiveWindow();
  lParam = &local_8;
  local_4 = 0;
  lpfn = FUN_004294e0;
  dwThreadId = GetCurrentThreadId();
  EnumThreadWindows(dwThreadId,lpfn,(LPARAM)lParam);
  return local_4;
}

