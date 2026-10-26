/*
 * USER32.DLL::GetWindowDC at 00406930
 * HDC __stdcall GetWindowDC(HWND hWnd)
 * Address ranges: 00406930-00406935
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetWindowDC
 */

HDC __stdcall GetWindowDC(HWND hWnd)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406930. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetWindowDC(hWnd);
  return pHVar1;
}

