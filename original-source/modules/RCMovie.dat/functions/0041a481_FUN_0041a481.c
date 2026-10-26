/*
 * FUN_0041a481 at 0041a481
 * undefined __cdecl FUN_0041a481(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 0041a481-0041a4fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_0041a481(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  HBRUSH pHVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x28));
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  pHVar1 = CreateSolidBrush(*(COLORREF *)(param_1 + 0x14));
  *(HBRUSH *)(param_1 + 0x1c) = pHVar1;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  *(undefined4 *)(param_1 + 0x24) = param_5;
  pHVar1 = CreateSolidBrush(*(COLORREF *)(param_1 + 0x20));
  *(HBRUSH *)(param_1 + 0x28) = pHVar1;
  return;
}

