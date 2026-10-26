/*
 * USER32.DLL::ShowWindow at 00406b58
 * BOOL __stdcall ShowWindow(HWND hWnd, int nCmdShow)
 * Address ranges: 00406b58-00406b5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ShowWindow
 */

BOOL __stdcall ShowWindow(HWND hWnd,int nCmdShow)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ShowWindow(hWnd,nCmdShow);
  return BVar1;
}

