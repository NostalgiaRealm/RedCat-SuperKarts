/*
 * USER32.DLL::DefFrameProcA at 00406730
 * LRESULT __stdcall DefFrameProcA(HWND hWnd, HWND hWndMDIClient, UINT uMsg, WPARAM wParam, LPARAM lParam)
 * Address ranges: 00406730-00406735
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DefFrameProcA
 */

LRESULT __stdcall DefFrameProcA(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam)

{
  LRESULT LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = DefFrameProcA(hWnd,hWndMDIClient,uMsg,wParam,lParam);
  return LVar1;
}

