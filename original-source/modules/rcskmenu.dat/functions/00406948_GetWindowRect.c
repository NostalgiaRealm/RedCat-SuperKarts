/*
 * USER32.DLL::GetWindowRect at 00406948
 * BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
 * Address ranges: 00406948-0040694d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetWindowRect
 */

BOOL __stdcall GetWindowRect(HWND hWnd,LPRECT lpRect)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406948. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetWindowRect(hWnd,lpRect);
  return BVar1;
}

