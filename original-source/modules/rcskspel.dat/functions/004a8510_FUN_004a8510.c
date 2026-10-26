/*
 * FUN_004a8510 at 004a8510
 * undefined FUN_004a8510(void)
 * Address ranges: 004a8510-004a8553
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a8510(int param_1)

{
  if (*(int *)(param_1 + 0x9c) != 0) {
    FUN_004bc150(*(undefined4 *)(param_1 + 0x98));
    *(undefined4 *)(param_1 + 0x9c) = 0;
    *(undefined4 *)(param_1 + 0x98) = 0;
    FUN_004bc150(*(undefined4 *)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  return;
}

