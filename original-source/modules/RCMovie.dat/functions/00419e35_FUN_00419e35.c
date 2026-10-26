/*
 * FUN_00419e35 at 00419e35
 * undefined __cdecl FUN_00419e35(int param_1)
 * Address ranges: 00419e35-00419e72
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00419e35(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_ownedit_box__n_0043606c);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

