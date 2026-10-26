/*
 * COMCTL32.DLL::ImageList_SetDragCursorImage at 004159d0
 * BOOL __stdcall ImageList_SetDragCursorImage(HIMAGELIST himlDrag, int iDrag, int dxHotspot, int dyHotspot)
 * Address ranges: 004159d0-004159d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_SetDragCursorImage
 */

BOOL __stdcall
ImageList_SetDragCursorImage(HIMAGELIST himlDrag,int iDrag,int dxHotspot,int dyHotspot)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004159d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_SetDragCursorImage(himlDrag,iDrag,dxHotspot,dyHotspot);
  return BVar1;
}

