/*
 * USER32.DLL::GetDesktopWindow at 00406850
 * HWND __stdcall GetDesktopWindow(void)
 * Address ranges: 00406850-00406855
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetDesktopWindow
 */

HWND __stdcall GetDesktopWindow(void)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetDesktopWindow();
  return pHVar1;
}

