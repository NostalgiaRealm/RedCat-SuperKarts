/*
 * FUN_004025e0 at 004025e0
 * undefined FUN_004025e0(void)
 * Address ranges: 004025e0-0040261c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004025e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  if (0x22 < param_1) {
    return 0;
  }
  (&DAT_00503a90)[param_1 * 4] = param_2;
  *(undefined4 *)(&DAT_00503a94 + param_1 * 0x10) = param_3;
  *(undefined4 *)(&DAT_00503a98 + param_1 * 0x10) = param_4;
  (&DAT_00503a9c)[param_1 * 4] = param_5;
  return 1;
}

