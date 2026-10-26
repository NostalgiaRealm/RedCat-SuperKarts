/*
 * USER32.DLL::IsWindow at 004069a8
 * BOOL __stdcall IsWindow(HWND hWnd)
 * Address ranges: 004069a8-004069ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::IsWindow
 */

BOOL __stdcall IsWindow(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004069a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = IsWindow(hWnd);
  return BVar1;
}

