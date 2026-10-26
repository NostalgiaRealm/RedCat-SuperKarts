/*
 * USER32.DLL::FrameRect at 00406800
 * int __stdcall FrameRect(HDC hDC, RECT * lprc, HBRUSH hbr)
 * Address ranges: 00406800-00406805
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::FrameRect
 */

int __stdcall FrameRect(HDC hDC,RECT *lprc,HBRUSH hbr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = FrameRect(hDC,lprc,hbr);
  return iVar1;
}

