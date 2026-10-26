/*
 * FUN_00493a20 at 00493a20
 * undefined FUN_00493a20(void)
 * Address ranges: 00493a20-00493a3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00493a20(uint param_1)

{
  if (DAT_00680b2c <= (int)param_1) {
    param_1 = param_1 - DAT_00680b2c;
  }
  if ((int)param_1 < 0) {
    param_1 = DAT_00680b2c - ((param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f));
  }
  return param_1;
}

