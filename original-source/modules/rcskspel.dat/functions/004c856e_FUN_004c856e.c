/*
 * FUN_004c856e at 004c856e
 * undefined FUN_004c856e(void)
 * Address ranges: 004c856e-004c8596
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_004c856e(undefined8 param_1,short param_2)

{
  undefined8 local_c;
  
  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(undefined6)param_1);
  return (float10)local_c;
}

