/*
 * FUN_004025a0 at 004025a0
 * undefined FUN_004025a0(void)
 * Address ranges: 004025a0-004025dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_004025a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  if (0x22 < param_1) {
    return 0;
  }
  (&DAT_00503cc0)[param_1 * 4] = param_2;
  *(undefined4 *)(&DAT_00503cc4 + param_1 * 0x10) = param_3;
  (&DAT_00503cc8)[param_1 * 4] = param_4;
  (&DAT_00503ccc)[param_1 * 4] = param_5;
  return 1;
}

