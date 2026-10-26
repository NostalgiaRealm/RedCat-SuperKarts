/*
 * USER32.DLL::BeginPaint at 004066d8
 * HDC __stdcall BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
 * Address ranges: 004066d8-004066dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::BeginPaint
 */

HDC __stdcall BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint)

{
  HDC pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = BeginPaint(hWnd,lpPaint);
  return pHVar1;
}

