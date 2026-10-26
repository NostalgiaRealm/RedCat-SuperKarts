/*
 * USER32.DLL::GetFocus at 00406858
 * HWND __stdcall GetFocus(void)
 * Address ranges: 00406858-0040685d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetFocus
 */

HWND __stdcall GetFocus(void)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetFocus();
  return pHVar1;
}

