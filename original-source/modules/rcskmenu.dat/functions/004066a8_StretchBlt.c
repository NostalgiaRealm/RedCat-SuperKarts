/*
 * GDI32.DLL::StretchBlt at 004066a8
 * BOOL __stdcall StretchBlt(HDC hdcDest, int xDest, int yDest, int wDest, int hDest, HDC hdcSrc, int xSrc, int ySrc, int wSrc, int hSrc, DWORD rop)
 * Address ranges: 004066a8-004066ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::StretchBlt
 */

BOOL __stdcall
StretchBlt(HDC hdcDest,int xDest,int yDest,int wDest,int hDest,HDC hdcSrc,int xSrc,int ySrc,int wSrc
          ,int hSrc,DWORD rop)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = StretchBlt(hdcDest,xDest,yDest,wDest,hDest,hdcSrc,xSrc,ySrc,wSrc,hSrc,rop);
  return BVar1;
}

