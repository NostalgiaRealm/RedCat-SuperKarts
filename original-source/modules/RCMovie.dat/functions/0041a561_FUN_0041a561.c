/*
 * FUN_0041a561 at 0041a561
 * undefined __cdecl FUN_0041a561(int param_1)
 * Address ranges: 0041a561-0041a5c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041a561(int param_1)

{
  if (DAT_0043e12c == '\0') {
    FUN_0040187a((byte *)s__s__d_____destroy_edit_box__edit_00436370);
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_edit_box__no_v_004363cc);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

