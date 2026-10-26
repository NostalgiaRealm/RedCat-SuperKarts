/*
 * GDI32.DLL::MaskBlt at 004065e8
 * BOOL __stdcall MaskBlt(HDC hdcDest, int xDest, int yDest, int width, int height, HDC hdcSrc, int xSrc, int ySrc, HBITMAP hbmMask, int xMask, int yMask, DWORD rop)
 * Address ranges: 004065e8-004065ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::MaskBlt
 */

BOOL __stdcall
MaskBlt(HDC hdcDest,int xDest,int yDest,int width,int height,HDC hdcSrc,int xSrc,int ySrc,
       HBITMAP hbmMask,int xMask,int yMask,DWORD rop)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = MaskBlt(hdcDest,xDest,yDest,width,height,hdcSrc,xSrc,ySrc,hbmMask,xMask,yMask,rop);
  return BVar1;
}

