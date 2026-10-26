/*
 * COMCTL32.DLL::ImageList_GetBkColor at 0041597c
 * COLORREF __stdcall ImageList_GetBkColor(HIMAGELIST himl)
 * Address ranges: 0041597c-00415981
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_GetBkColor
 */

COLORREF __stdcall ImageList_GetBkColor(HIMAGELIST himl)

{
  COLORREF CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041597c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = ImageList_GetBkColor(himl);
  return CVar1;
}

