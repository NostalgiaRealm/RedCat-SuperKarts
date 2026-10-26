/*
 * USER32.DLL::EqualRect at 004067e8
 * BOOL __stdcall EqualRect(RECT * lprc1, RECT * lprc2)
 * Address ranges: 004067e8-004067ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::EqualRect
 */

BOOL __stdcall EqualRect(RECT *lprc1,RECT *lprc2)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = EqualRect(lprc1,lprc2);
  return BVar1;
}

