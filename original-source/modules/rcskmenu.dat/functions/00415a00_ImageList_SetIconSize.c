/*
 * COMCTL32.DLL::ImageList_SetIconSize at 00415a00
 * BOOL __stdcall ImageList_SetIconSize(HIMAGELIST himl, int cx, int cy)
 * Address ranges: 00415a00-00415a05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_SetIconSize
 */

BOOL __stdcall ImageList_SetIconSize(HIMAGELIST himl,int cx,int cy)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00415a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_SetIconSize(himl,cx,cy);
  return BVar1;
}

