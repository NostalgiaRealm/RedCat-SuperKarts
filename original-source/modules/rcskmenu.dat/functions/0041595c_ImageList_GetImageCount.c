/*
 * COMCTL32.DLL::ImageList_GetImageCount at 0041595c
 * int __stdcall ImageList_GetImageCount(HIMAGELIST himl)
 * Address ranges: 0041595c-00415961
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_GetImageCount
 */

int __stdcall ImageList_GetImageCount(HIMAGELIST himl)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041595c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ImageList_GetImageCount(himl);
  return iVar1;
}

