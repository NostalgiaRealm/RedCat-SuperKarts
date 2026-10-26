/*
 * COMCTL32.DLL::ImageList_DragMove at 004159c8
 * BOOL __stdcall ImageList_DragMove(int x, int y)
 * Address ranges: 004159c8-004159cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_DragMove
 */

BOOL __stdcall ImageList_DragMove(int x,int y)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004159c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_DragMove(x,y);
  return BVar1;
}

