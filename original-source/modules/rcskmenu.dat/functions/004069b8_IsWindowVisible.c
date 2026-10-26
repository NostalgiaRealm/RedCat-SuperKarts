/*
 * USER32.DLL::IsWindowVisible at 004069b8
 * BOOL __stdcall IsWindowVisible(HWND hWnd)
 * Address ranges: 004069b8-004069bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::IsWindowVisible
 */

BOOL __stdcall IsWindowVisible(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004069b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = IsWindowVisible(hWnd);
  return BVar1;
}

