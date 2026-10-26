/*
 * USER32.DLL::GetForegroundWindow at 00406860
 * HWND __stdcall GetForegroundWindow(void)
 * Address ranges: 00406860-00406865
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetForegroundWindow
 */

HWND __stdcall GetForegroundWindow(void)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetForegroundWindow();
  return pHVar1;
}

