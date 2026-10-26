/*
 * USER32.DLL::SetPropA at 00406ae0
 * BOOL __stdcall SetPropA(HWND hWnd, LPCSTR lpString, HANDLE hData)
 * Address ranges: 00406ae0-00406ae5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetPropA
 */

BOOL __stdcall SetPropA(HWND hWnd,LPCSTR lpString,HANDLE hData)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406ae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetPropA(hWnd,lpString,hData);
  return BVar1;
}

