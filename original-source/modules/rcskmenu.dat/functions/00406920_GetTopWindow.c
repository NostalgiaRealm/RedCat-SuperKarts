/*
 * USER32.DLL::GetTopWindow at 00406920
 * HWND __stdcall GetTopWindow(HWND hWnd)
 * Address ranges: 00406920-00406925
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetTopWindow
 */

HWND __stdcall GetTopWindow(HWND hWnd)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetTopWindow(hWnd);
  return pHVar1;
}

