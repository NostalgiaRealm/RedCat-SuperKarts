/*
 * FUN_0040d980 at 0040d980
 * undefined FUN_0040d980(void)
 * Address ranges: 0040d980-0040d9b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d980(int param_1)

{
  if ((&DAT_00503ef4)[param_1 * 0x47] != 9) {
    FUN_0040eb20(0x1a);
    (&DAT_00503ef4)[param_1 * 0x47] = 0x1a;
  }
  return;
}

