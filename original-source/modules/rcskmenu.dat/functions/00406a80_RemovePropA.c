/*
 * USER32.DLL::RemovePropA at 00406a80
 * HANDLE __stdcall RemovePropA(HWND hWnd, LPCSTR lpString)
 * Address ranges: 00406a80-00406a85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::RemovePropA
 */

HANDLE __stdcall RemovePropA(HWND hWnd,LPCSTR lpString)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = RemovePropA(hWnd,lpString);
  return pvVar1;
}

