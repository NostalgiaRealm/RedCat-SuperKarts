/*
 * USER32.DLL::IsChild at 00406988
 * BOOL __stdcall IsChild(HWND hWndParent, HWND hWnd)
 * Address ranges: 00406988-0040698d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::IsChild
 */

BOOL __stdcall IsChild(HWND hWndParent,HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = IsChild(hWndParent,hWnd);
  return BVar1;
}

