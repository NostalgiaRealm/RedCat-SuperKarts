/*
 * USER32.DLL::DestroyWindow at 00406768
 * BOOL __stdcall DestroyWindow(HWND hWnd)
 * Address ranges: 00406768-0040676d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DestroyWindow
 */

BOOL __stdcall DestroyWindow(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406768. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DestroyWindow(hWnd);
  return BVar1;
}

