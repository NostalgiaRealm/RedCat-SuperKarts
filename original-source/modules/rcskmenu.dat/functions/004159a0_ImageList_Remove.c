/*
 * COMCTL32.DLL::ImageList_Remove at 004159a0
 * BOOL __stdcall ImageList_Remove(HIMAGELIST himl, int i)
 * Address ranges: 004159a0-004159a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_Remove
 */

BOOL __stdcall ImageList_Remove(HIMAGELIST himl,int i)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004159a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_Remove(himl,i);
  return BVar1;
}

