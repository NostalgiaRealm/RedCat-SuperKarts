/*
 * USER32.DLL::GetDCEx at 00406848
 * HDC __stdcall GetDCEx(HWND hWnd, HRGN hrgnClip, DWORD flags)
 * Address ranges: 00406848-0040684d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetDCEx
 */

HDC __stdcall GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetDCEx(hWnd,hrgnClip,flags);
  return pHVar1;
}

