/*
 * USER32.DLL::PtInRect at 00406a40
 * BOOL __stdcall PtInRect(RECT * lprc, POINT pt)
 * Address ranges: 00406a40-00406a45
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::PtInRect
 */

BOOL __stdcall PtInRect(RECT *lprc,POINT pt)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = PtInRect(lprc,pt);
  return BVar1;
}

