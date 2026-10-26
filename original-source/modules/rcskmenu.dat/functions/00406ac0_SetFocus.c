/*
 * USER32.DLL::SetFocus at 00406ac0
 * HWND __stdcall SetFocus(HWND hWnd)
 * Address ranges: 00406ac0-00406ac5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetFocus
 */

HWND __stdcall SetFocus(HWND hWnd)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = SetFocus(hWnd);
  return pHVar1;
}

