/*
 * FUN_004a8490 at 004a8490
 * undefined FUN_004a8490(void)
 * Address ranges: 004a8490-004a8506
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a8490(int param_1)

{
  if (*(int *)(param_1 + 4) == 1) {
    if (*(int *)(param_1 + 0x7c) != 0) {
      FUN_004bc150(*(undefined4 *)(param_1 + 0x78));
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
    }
  }
  else if ((*(int *)(param_1 + 4) == 2) && (*(int *)(param_1 + 0x84) != 0)) {
    FUN_004bc150(*(undefined4 *)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(int *)(param_1 + 0x8c) != 0) {
    FUN_004bc150(*(undefined4 *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

