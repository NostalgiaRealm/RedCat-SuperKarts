/*
 * USER32.DLL::GetLastActivePopup at 00406898
 * HWND __stdcall GetLastActivePopup(HWND hWnd)
 * Address ranges: 00406898-0040689d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetLastActivePopup
 */

HWND __stdcall GetLastActivePopup(HWND hWnd)

{
  HWND pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetLastActivePopup(hWnd);
  return pHVar1;
}

