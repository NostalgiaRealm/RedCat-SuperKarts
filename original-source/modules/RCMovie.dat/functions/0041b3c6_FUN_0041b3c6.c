/*
 * FUN_0041b3c6 at 0041b3c6
 * undefined __cdecl FUN_0041b3c6(int param_1)
 * Address ranges: 0041b3c6-0041b3f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041b3c6(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_animbutton__no_00436718);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

