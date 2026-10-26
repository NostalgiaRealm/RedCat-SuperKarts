/*
 * USER32.DLL::GetPropA at 004068e0
 * HANDLE __stdcall GetPropA(HWND hWnd, LPCSTR lpString)
 * Address ranges: 004068e0-004068e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetPropA
 */

HANDLE __stdcall GetPropA(HWND hWnd,LPCSTR lpString)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = GetPropA(hWnd,lpString);
  return pvVar1;
}

