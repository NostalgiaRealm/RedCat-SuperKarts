/*
 * USER32.DLL::EnableWindow at 004067c0
 * BOOL __stdcall EnableWindow(HWND hWnd, BOOL bEnable)
 * Address ranges: 004067c0-004067c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::EnableWindow
 */

BOOL __stdcall EnableWindow(HWND hWnd,BOOL bEnable)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = EnableWindow(hWnd,bEnable);
  return BVar1;
}

