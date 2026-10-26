/*
 * USER32.DLL::SetCapture at 00406aa8
 * HWND __stdcall SetCapture(HWND hWnd)
 * Address ranges: 00406aa8-00406aad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetCapture
 */

HWND __stdcall SetCapture(HWND hWnd)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = SetCapture(hWnd);
  return pHVar1;
}

