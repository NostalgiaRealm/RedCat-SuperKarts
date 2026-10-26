/*
 * FUN_0043d1cc at 0043d1cc
 * undefined FUN_0043d1cc(void)
 * Address ranges: 0043d1cc-0043d234
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043d1cc(void)

{
  undefined4 uVar1;
  BOOL BVar2;
  HWND in_stack_00000004;
  int *in_stack_00000008;
  tagRECT tStack_14;
  
  if (in_stack_00000004 == (HWND)in_stack_00000008[1]) {
    uVar1 = 0;
  }
  else {
    if (in_stack_00000008[2] == 0) {
      GetWindowRect(in_stack_00000004,&tStack_14);
      BVar2 = PtInRect(&tStack_14,*(POINT *)(in_stack_00000008 + 3));
      if (BVar2 != 0) {
        in_stack_00000008[2] = (int)in_stack_00000004;
      }
    }
    if (in_stack_00000004 == (HWND)in_stack_00000008[2]) {
      uVar1 = 0;
      *(undefined1 *)(in_stack_00000008 + 5) = 1;
    }
    else if (in_stack_00000004 == (HWND)*in_stack_00000008) {
      uVar1 = 0xffffffff;
      in_stack_00000008[2] = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

