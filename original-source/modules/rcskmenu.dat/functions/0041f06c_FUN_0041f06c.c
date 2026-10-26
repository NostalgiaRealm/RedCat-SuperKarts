/*
 * FUN_0041f06c at 0041f06c
 * undefined FUN_0041f06c(void)
 * Address ranges: 0041f06c-0041f17e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041f06c(void)

{
  undefined4 uVar1;
  BOOL BVar2;
  HDC in_stack_00000004;
  RECT *in_stack_00000008;
  code *in_stack_0000000c;
  tagRECT tStack_30;
  tagRECT tStack_20;
  int iStack_10;
  tagPOINT tStack_c;
  
  if (DAT_0047d70b == '\0') {
    DAT_0047d6f8 = (code *)FUN_0041eab4(7,DAT_0047d6f8,"EnumDisplayMonitors");
    uVar1 = (*DAT_0047d6f8)();
  }
  else {
    uVar1 = 0;
    if (in_stack_0000000c != (code *)0x0) {
      tStack_20.left = 0;
      tStack_20.top = 0;
      tStack_20.right = (*DAT_0047d6dc)();
      tStack_20.bottom = (*DAT_0047d6dc)();
      if (in_stack_00000004 == (HDC)0x0) {
        if ((in_stack_00000008 != (RECT *)0x0) &&
           (BVar2 = IntersectRect(&tStack_20,&tStack_20,in_stack_00000008), BVar2 == 0)) {
          return 1;
        }
      }
      else {
        iStack_10 = GetClipBox(in_stack_00000004,&tStack_30);
        BVar2 = GetDCOrgEx(in_stack_00000004,&tStack_c);
        if (BVar2 == 0) {
          return 0;
        }
        OffsetRect(&tStack_20,-tStack_c.x,-tStack_c.y);
        BVar2 = IntersectRect(&tStack_20,&tStack_20,&tStack_30);
        if (((BVar2 == 0) || (in_stack_00000008 != (RECT *)0x0)) &&
           (BVar2 = IntersectRect(&tStack_20,&tStack_20,in_stack_00000008), BVar2 == 0)) {
          if (iStack_10 != 1) {
            return 0;
          }
          return 1;
        }
      }
      uVar1 = (*in_stack_0000000c)();
    }
  }
  return uVar1;
}

