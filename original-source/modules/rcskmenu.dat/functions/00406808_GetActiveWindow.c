/*
 * USER32.DLL::GetActiveWindow at 00406808
 * HWND __stdcall GetActiveWindow(void)
 * Address ranges: 00406808-0040680d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetActiveWindow
 */

HWND __stdcall GetActiveWindow(void)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406808. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetActiveWindow();
  return pHVar1;
}

