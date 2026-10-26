/*
 * GDI32.DLL::SetBkColor at 00406648
 * COLORREF __stdcall SetBkColor(HDC hdc, COLORREF color)
 * Address ranges: 00406648-0040664d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetBkColor
 */

COLORREF __stdcall SetBkColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406648. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = SetBkColor(hdc,color);
  return CVar1;
}

