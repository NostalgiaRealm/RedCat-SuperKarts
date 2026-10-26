/*
 * GDI32.DLL::CombineRgn at 00406490
 * int __stdcall CombineRgn(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode)
 * Address ranges: 00406490-00406495
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CombineRgn
 */

int __stdcall CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,int iMode)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = CombineRgn(hrgnDst,hrgnSrc1,hrgnSrc2,iMode);
  return iVar1;
}

