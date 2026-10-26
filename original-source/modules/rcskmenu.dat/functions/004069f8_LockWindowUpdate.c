/*
 * USER32.DLL::LockWindowUpdate at 004069f8
 * BOOL __stdcall LockWindowUpdate(HWND hWndLock)
 * Address ranges: 004069f8-004069fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::LockWindowUpdate
 */

BOOL __stdcall LockWindowUpdate(HWND hWndLock)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004069f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = LockWindowUpdate(hWndLock);
  return BVar1;
}

