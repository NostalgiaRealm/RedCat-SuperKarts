/*
 * COMCTL32.DLL::ImageList_Destroy at 00415954
 * BOOL __stdcall ImageList_Destroy(HIMAGELIST himl)
 * Address ranges: 00415954-00415959
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_Destroy
 */

BOOL __stdcall ImageList_Destroy(HIMAGELIST himl)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00415954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_Destroy(himl);
  return BVar1;
}

