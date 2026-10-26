/*
 * USER32.DLL::SetWindowTextA at 00406b28
 * BOOL __stdcall SetWindowTextA(HWND hWnd, LPCSTR lpString)
 * Address ranges: 00406b28-00406b2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetWindowTextA
 */

BOOL __stdcall SetWindowTextA(HWND hWnd,LPCSTR lpString)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetWindowTextA(hWnd,lpString);
  return BVar1;
}

