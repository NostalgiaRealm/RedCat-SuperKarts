/*
 * FUN_0041c369 at 0041c369
 * undefined __cdecl FUN_0041c369(int param_1)
 * Address ranges: 0041c369-0041c397
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041c369(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_togglebutton__n_00436ae4);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

