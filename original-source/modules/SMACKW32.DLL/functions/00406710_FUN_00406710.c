/*
 * FUN_00406710 at 00406710
 * undefined FUN_00406710(void)
 * Address ranges: 00406710-0040678f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406710(uint param_1,uint param_2,int param_3)

{
  if (0x8000 < param_2) {
    param_2 = 0x8000;
  }
  (**(code **)(**(int **)(*(int *)(param_3 + 0x38) + 4) + 0x40))
            (*(undefined4 *)(*(int *)(param_3 + 0x38) + 4),
             (int)(((ulonglong)param_1 * 20000) / 0x10000) + -10000);
  (**(code **)(**(int **)(*(int *)(param_3 + 0x38) + 4) + 0x3c))
            (*(undefined4 *)(*(int *)(param_3 + 0x38) + 4),
             ((int)(((ulonglong)param_2 * 100000) / 0x8000) + 5U) / 10 - 10000);
  return;
}

