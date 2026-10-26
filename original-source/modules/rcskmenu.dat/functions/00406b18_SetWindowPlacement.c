/*
 * USER32.DLL::SetWindowPlacement at 00406b18
 * BOOL __stdcall SetWindowPlacement(HWND hWnd, WINDOWPLACEMENT * lpwndpl)
 * Address ranges: 00406b18-00406b1d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetWindowPlacement
 */

BOOL __stdcall SetWindowPlacement(HWND hWnd,WINDOWPLACEMENT *lpwndpl)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetWindowPlacement(hWnd,lpwndpl);
  return BVar1;
}

