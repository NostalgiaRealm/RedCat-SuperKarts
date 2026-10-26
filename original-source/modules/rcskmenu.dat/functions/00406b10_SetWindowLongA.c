/*
 * USER32.DLL::SetWindowLongA at 00406b10
 * LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
 * Address ranges: 00406b10-00406b15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::SetWindowLongA
 */

LONG __stdcall SetWindowLongA(HWND hWnd,int nIndex,LONG dwNewLong)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = SetWindowLongA(hWnd,nIndex,dwNewLong);
  return LVar1;
}

