/*
 * USER32.DLL::DrawFocusRect at 00406780
 * BOOL __stdcall DrawFocusRect(HDC hDC, RECT * lprc)
 * Address ranges: 00406780-00406785
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DrawFocusRect
 */

BOOL __stdcall DrawFocusRect(HDC hDC,RECT *lprc)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DrawFocusRect(hDC,lprc);
  return BVar1;
}

