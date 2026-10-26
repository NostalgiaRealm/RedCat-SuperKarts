/*
 * USER32.DLL::GetMenu at 004068a0
 * HMENU __stdcall GetMenu(HWND hWnd)
 * Address ranges: 004068a0-004068a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetMenu
 */

HMENU __stdcall GetMenu(HWND hWnd)

{
  HMENU pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004068a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetMenu(hWnd);
  return pHVar1;
}

