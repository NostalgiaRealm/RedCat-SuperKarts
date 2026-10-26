/*
 * FUN_0041be06 at 0041be06
 * undefined __cdecl FUN_0041be06(int param_1)
 * Address ranges: 0041be06-0041be34
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041be06(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_0040187a((byte *)s__s__d_____destroy_areabutton__no_004367ec);
  }
  DestroyWindow(*(HWND *)(param_1 + 0x18));
  return;
}

