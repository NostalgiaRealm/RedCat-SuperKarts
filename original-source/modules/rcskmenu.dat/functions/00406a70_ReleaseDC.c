/*
 * USER32.DLL::ReleaseDC at 00406a70
 * int __stdcall ReleaseDC(HWND hWnd, HDC hDC)
 * Address ranges: 00406a70-00406a75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ReleaseDC
 */

int __stdcall ReleaseDC(HWND hWnd,HDC hDC)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ReleaseDC(hWnd,hDC);
  return iVar1;
}

