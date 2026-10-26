/*
 * FUN_004c9b7e at 004c9b7e
 * undefined FUN_004c9b7e(void)
 * Address ranges: 004c9b7e-004c9ba5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c9b7e(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_00502f8c) {
    uVar1 = FUN_004c3680(param_1,8);
    return uVar1;
  }
  return (byte)PTR_DAT_00502d80[param_1 * 2] & 8;
}

