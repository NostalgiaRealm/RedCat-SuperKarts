/*
 * USER32.DLL::ScreenToClient at 00406a88
 * BOOL __stdcall ScreenToClient(HWND hWnd, LPPOINT lpPoint)
 * Address ranges: 00406a88-00406a8d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ScreenToClient
 */

BOOL __stdcall ScreenToClient(HWND hWnd,LPPOINT lpPoint)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ScreenToClient(hWnd,lpPoint);
  return BVar1;
}

