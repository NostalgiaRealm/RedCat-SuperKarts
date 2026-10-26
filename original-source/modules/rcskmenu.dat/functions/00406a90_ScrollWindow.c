/*
 * USER32.DLL::ScrollWindow at 00406a90
 * BOOL __stdcall ScrollWindow(HWND hWnd, int XAmount, int YAmount, RECT * lpRect, RECT * lpClipRect)
 * Address ranges: 00406a90-00406a95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ScrollWindow
 */

BOOL __stdcall ScrollWindow(HWND hWnd,int XAmount,int YAmount,RECT *lpRect,RECT *lpClipRect)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ScrollWindow(hWnd,XAmount,YAmount,lpRect,lpClipRect);
  return BVar1;
}

