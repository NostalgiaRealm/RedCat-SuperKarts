/*
 * COMCTL32.DLL::ImageList_Read at 004159e8
 * HIMAGELIST __stdcall ImageList_Read(IStream * pstm)
 * Address ranges: 004159e8-004159ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_Read
 */

HIMAGELIST __stdcall ImageList_Read(IStream *pstm)

{
  HIMAGELIST p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x004159e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = ImageList_Read(pstm);
  return p_Var1;
}

