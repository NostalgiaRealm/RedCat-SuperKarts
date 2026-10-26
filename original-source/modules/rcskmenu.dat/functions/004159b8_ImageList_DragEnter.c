/*
 * COMCTL32.DLL::ImageList_DragEnter at 004159b8
 * BOOL __stdcall ImageList_DragEnter(HWND hwndLock, int x, int y)
 * Address ranges: 004159b8-004159bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_DragEnter
 */

BOOL __stdcall ImageList_DragEnter(HWND hwndLock,int x,int y)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004159b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_DragEnter(hwndLock,x,y);
  return BVar1;
}

