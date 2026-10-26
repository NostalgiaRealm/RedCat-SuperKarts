/*
 * USER32.DLL::GetWindowLongA at 00406938
 * LONG __stdcall GetWindowLongA(HWND hWnd, int nIndex)
 * Address ranges: 00406938-0040693d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetWindowLongA
 */

LONG __stdcall GetWindowLongA(HWND hWnd,int nIndex)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406938. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = GetWindowLongA(hWnd,nIndex);
  return LVar1;
}

