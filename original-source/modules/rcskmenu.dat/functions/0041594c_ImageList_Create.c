/*
 * COMCTL32.DLL::ImageList_Create at 0041594c
 * HIMAGELIST __stdcall ImageList_Create(int cx, int cy, UINT flags, int cInitial, int cGrow)
 * Address ranges: 0041594c-00415951
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_Create
 */

HIMAGELIST __stdcall ImageList_Create(int cx,int cy,UINT flags,int cInitial,int cGrow)

{
  HIMAGELIST p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0041594c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = ImageList_Create(cx,cy,flags,cInitial,cGrow);
  return p_Var1;
}

