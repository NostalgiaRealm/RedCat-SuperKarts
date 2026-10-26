/*
 * USER32.DLL::OffsetRect at 00406a20
 * BOOL __stdcall OffsetRect(LPRECT lprc, int dx, int dy)
 * Address ranges: 00406a20-00406a25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::OffsetRect
 */

BOOL __stdcall OffsetRect(LPRECT lprc,int dx,int dy)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = OffsetRect(lprc,dx,dy);
  return BVar1;
}

