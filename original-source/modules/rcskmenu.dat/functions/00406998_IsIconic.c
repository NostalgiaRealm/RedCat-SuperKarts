/*
 * USER32.DLL::IsIconic at 00406998
 * BOOL __stdcall IsIconic(HWND hWnd)
 * Address ranges: 00406998-0040699d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::IsIconic
 */

BOOL __stdcall IsIconic(HWND hWnd)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = IsIconic(hWnd);
  return BVar1;
}

