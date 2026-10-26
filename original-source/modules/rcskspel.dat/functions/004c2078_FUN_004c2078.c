/*
 * FUN_004c2078 at 004c2078
 * undefined FUN_004c2078(void)
 * Address ranges: 004c2078-004c208d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c2078(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) != 0x7ff00000) {
    return param_2 & 0x7ff00000;
  }
  return param_2;
}

