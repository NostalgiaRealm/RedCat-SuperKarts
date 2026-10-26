/*
 * COMCTL32.DLL::ImageList_Draw at 00415990
 * BOOL __stdcall ImageList_Draw(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, UINT fStyle)
 * Address ranges: 00415990-00415995
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_Draw
 */

BOOL __stdcall ImageList_Draw(HIMAGELIST himl,int i,HDC hdcDst,int x,int y,UINT fStyle)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00415990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_Draw(himl,i,hdcDst,x,y,fStyle);
  return BVar1;
}

