/*
 * KERNEL32.DLL::GlobalUnlock at 004063c0
 * BOOL __stdcall GlobalUnlock(HGLOBAL hMem)
 * Address ranges: 004063c0-004063c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GlobalUnlock
 */

BOOL __stdcall GlobalUnlock(HGLOBAL hMem)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004063c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GlobalUnlock(hMem);
  return BVar1;
}

