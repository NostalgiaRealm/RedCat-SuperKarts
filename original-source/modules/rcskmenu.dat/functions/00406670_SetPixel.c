/*
 * GDI32.DLL::SetPixel at 00406670
 * COLORREF __stdcall SetPixel(HDC hdc, int x, int y, COLORREF color)
 * Address ranges: 00406670-00406675
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetPixel
 */

COLORREF __stdcall SetPixel(HDC hdc,int x,int y,COLORREF color)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = SetPixel(hdc,x,y,color);
  return CVar1;
}

