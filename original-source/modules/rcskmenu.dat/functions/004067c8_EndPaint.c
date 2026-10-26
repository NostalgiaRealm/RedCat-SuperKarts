/*
 * USER32.DLL::EndPaint at 004067c8
 * BOOL __stdcall EndPaint(HWND hWnd, PAINTSTRUCT * lpPaint)
 * Address ranges: 004067c8-004067cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::EndPaint
 */

BOOL __stdcall EndPaint(HWND hWnd,PAINTSTRUCT *lpPaint)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = EndPaint(hWnd,lpPaint);
  return BVar1;
}

