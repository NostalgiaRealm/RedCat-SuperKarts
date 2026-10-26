/*
 * USER32.DLL::SetActiveWindow at 00406aa0
 * HWND __stdcall SetActiveWindow(HWND hWnd)
 * Address ranges: 00406aa0-00406aa5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetActiveWindow
 */

HWND __stdcall SetActiveWindow(HWND hWnd)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = SetActiveWindow(hWnd);
  return pHVar1;
}

