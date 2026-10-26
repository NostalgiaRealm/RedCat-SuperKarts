/*
 * FUN_0041cc20 at 0041cc20
 * undefined __cdecl FUN_0041cc20(int param_1)
 * Address ranges: 0041cc20-0041cc4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041cc20(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_button__no_val_00436c34);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

