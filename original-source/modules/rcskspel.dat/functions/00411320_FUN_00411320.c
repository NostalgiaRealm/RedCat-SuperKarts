/*
 * FUN_00411320 at 00411320
 * undefined FUN_00411320(void)
 * Address ranges: 00411320-0041133b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00411320(int param_1)

{
  if ((7 < param_1) && (param_1 < 0)) {
    return 0xffffffff;
  }
  return (&DAT_00505a38)[param_1 * 6];
}

