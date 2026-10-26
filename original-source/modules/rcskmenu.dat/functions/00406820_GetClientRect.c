/*
 * USER32.DLL::GetClientRect at 00406820
 * BOOL __stdcall GetClientRect(HWND hWnd, LPRECT lpRect)
 * Address ranges: 00406820-00406825
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetClientRect
 */

BOOL __stdcall GetClientRect(HWND hWnd,LPRECT lpRect)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetClientRect(hWnd,lpRect);
  return BVar1;
}

