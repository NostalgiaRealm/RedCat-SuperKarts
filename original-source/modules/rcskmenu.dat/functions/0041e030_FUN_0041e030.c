/*
 * FUN_0041e030 at 0041e030
 * undefined FUN_0041e030(void)
 * Address ranges: 0041e030-0041e046
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e030(int param_1)

{
  if (*(HICON *)(param_1 + 8) != (HICON)0x0) {
    DestroyIcon(*(HICON *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

