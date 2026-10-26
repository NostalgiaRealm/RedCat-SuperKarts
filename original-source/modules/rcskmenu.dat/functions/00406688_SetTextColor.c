/*
 * GDI32.DLL::SetTextColor at 00406688
 * COLORREF __stdcall SetTextColor(HDC hdc, COLORREF color)
 * Address ranges: 00406688-0040668d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetTextColor
 */

COLORREF __stdcall SetTextColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406688. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = SetTextColor(hdc,color);
  return CVar1;
}

