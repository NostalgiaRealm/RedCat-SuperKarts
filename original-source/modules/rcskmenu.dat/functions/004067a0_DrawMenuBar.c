/*
 * USER32.DLL::DrawMenuBar at 004067a0
 * BOOL __stdcall DrawMenuBar(HWND hWnd)
 * Address ranges: 004067a0-004067a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DrawMenuBar
 */

BOOL __stdcall DrawMenuBar(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DrawMenuBar(hWnd);
  return BVar1;
}

