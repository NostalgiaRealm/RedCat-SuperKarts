/*
 * FUN_004469b4 at 004469b4
 * undefined FUN_004469b4(void)
 * Address ranges: 004469b4-00446a26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004469b4(int *param_1)

{
  HWND pHVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  HDC hDC;
  tagRECT tStack_1c;
  HDC pHStack_c;
  int *piStack_8;
  
  piStack_8 = param_1;
  pHVar1 = (HWND)FUN_00445724(param_1);
  pHStack_c = GetWindowDC(pHVar1);
  uVar2 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffd8;
  FUN_0040ebe8(0,0,piStack_8[0xe],&tStack_1c.left,piStack_8[0xf]);
  DrawEdge(pHStack_c,&tStack_1c,1,0xf);
  *in_FS_OFFSET = uVar2;
  hDC = pHStack_c;
  pHVar1 = (HWND)FUN_00445724(piStack_8);
  ReleaseDC(pHVar1,hDC);
  return;
}

