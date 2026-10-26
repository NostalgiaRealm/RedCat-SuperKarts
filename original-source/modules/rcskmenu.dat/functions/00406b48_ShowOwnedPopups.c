/*
 * USER32.DLL::ShowOwnedPopups at 00406b48
 * BOOL __stdcall ShowOwnedPopups(HWND hWnd, BOOL fShow)
 * Address ranges: 00406b48-00406b4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ShowOwnedPopups
 */

BOOL __stdcall ShowOwnedPopups(HWND hWnd,BOOL fShow)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ShowOwnedPopups(hWnd,fShow);
  return BVar1;
}

