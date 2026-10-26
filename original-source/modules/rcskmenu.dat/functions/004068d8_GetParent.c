/*
 * USER32.DLL::GetParent at 004068d8
 * HWND __stdcall GetParent(HWND hWnd)
 * Address ranges: 004068d8-004068dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetParent
 */

HWND __stdcall GetParent(HWND hWnd)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetParent(hWnd);
  return pHVar1;
}

