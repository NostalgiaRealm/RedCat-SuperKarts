/*
 * COMCTL32.DLL::ImageList_DragLeave at 004159c0
 * BOOL __stdcall ImageList_DragLeave(HWND hwndLock)
 * Address ranges: 004159c0-004159c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to COMCTL32.DLL::ImageList_DragLeave
 */

BOOL __stdcall ImageList_DragLeave(HWND hwndLock)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004159c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ImageList_DragLeave(hwndLock);
  return BVar1;
}

