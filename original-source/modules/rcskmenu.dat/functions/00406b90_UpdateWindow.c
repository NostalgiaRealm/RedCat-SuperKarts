/*
 * USER32.DLL::UpdateWindow at 00406b90
 * BOOL __stdcall UpdateWindow(HWND hWnd)
 * Address ranges: 00406b90-00406b95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::UpdateWindow
 */

BOOL __stdcall UpdateWindow(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = UpdateWindow(hWnd);
  return BVar1;
}

