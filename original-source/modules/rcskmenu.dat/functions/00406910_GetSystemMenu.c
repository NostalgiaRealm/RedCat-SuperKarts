/*
 * USER32.DLL::GetSystemMenu at 00406910
 * HMENU __stdcall GetSystemMenu(HWND hWnd, BOOL bRevert)
 * Address ranges: 00406910-00406915
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetSystemMenu
 */

HMENU __stdcall GetSystemMenu(HWND hWnd,BOOL bRevert)

{
  HMENU pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetSystemMenu(hWnd,bRevert);
  return pHVar1;
}

