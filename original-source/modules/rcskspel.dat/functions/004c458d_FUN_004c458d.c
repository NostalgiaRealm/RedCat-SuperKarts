/*
 * FUN_004c458d at 004c458d
 * undefined FUN_004c458d(void)
 * Address ranges: 004c458d-004c45c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c458d(uint param_1)

{
  uint uVar1;
  
  if (DAT_00502f8c < 2) {
    uVar1 = (byte)PTR_DAT_00502d80[param_1 * 2] & 4;
  }
  else {
    uVar1 = FUN_004c3680(param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}

