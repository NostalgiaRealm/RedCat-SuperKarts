/*
 * FUN_0043d0ec at 0043d0ec
 * uint __register FUN_0043d0ec(uint param_1, uint param_2)
 * Address ranges: 0043d0ec-0043d10f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0043d0ec(uint param_1,uint param_2)

{
  if ((int)((param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f)) <
      (int)((param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f))) {
    return param_1;
  }
  return param_2;
}

