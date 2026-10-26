/*
 * FUN_00418980 at 00418980
 * undefined FUN_00418980(void)
 * Address ranges: 00418980-004189c6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00418980(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 8) != -1) {
      FUN_0049dd20(*(int *)(param_1 + 8));
      FUN_0049d7a0();
    }
    if (*(int *)(param_1 + 0xc) != -1) {
      FUN_0049dd20(*(int *)(param_1 + 0xc));
      FUN_0049d7a0();
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

