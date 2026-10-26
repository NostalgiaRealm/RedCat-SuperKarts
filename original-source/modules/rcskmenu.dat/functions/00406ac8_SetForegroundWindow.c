/*
 * USER32.DLL::SetForegroundWindow at 00406ac8
 * BOOL __stdcall SetForegroundWindow(HWND hWnd)
 * Address ranges: 00406ac8-00406acd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetForegroundWindow
 */

BOOL __stdcall SetForegroundWindow(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406ac8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetForegroundWindow(hWnd);
  return BVar1;
}

