/*
 * USER32.DLL::IsRectEmpty at 004069a0
 * BOOL __stdcall IsRectEmpty(RECT * lprc)
 * Address ranges: 004069a0-004069a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::IsRectEmpty
 */

BOOL __stdcall IsRectEmpty(RECT *lprc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004069a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = IsRectEmpty(lprc);
  return BVar1;
}

