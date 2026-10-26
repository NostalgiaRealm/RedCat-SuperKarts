/*
 * COMCTL32.DLL::ImageList_BeginDrag at 004159a8
 * BOOL __stdcall ImageList_BeginDrag(HIMAGELIST himlTrack, int iTrack, int dxHotspot, int dyHotspot)
 * Address ranges: 004159a8-004159ad
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_BeginDrag
 */

BOOL __stdcall ImageList_BeginDrag(HIMAGELIST himlTrack,int iTrack,int dxHotspot,int dyHotspot)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004159a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_BeginDrag(himlTrack,iTrack,dxHotspot,dyHotspot);
  return BVar1;
}

