/*
 * FUN_0041aba6 at 0041aba6
 * undefined __cdecl FUN_0041aba6(int param_1)
 * Address ranges: 0041aba6-0041abd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041aba6(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_radiobutton__n_004365e0);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

