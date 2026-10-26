/*
 * GDI32.DLL::GetPixel at 00406598
 * COLORREF __stdcall GetPixel(HDC hdc, int x, int y)
 * Address ranges: 00406598-0040659d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetPixel
 */

COLORREF __stdcall GetPixel(HDC hdc,int x,int y)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = GetPixel(hdc,x,y);
  return CVar1;
}

