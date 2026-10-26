/*
 * FUN_004126d4 at 004126d4
 * undefined __cdecl FUN_004126d4(undefined4 param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 004126d4-004127af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004126d4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  if ((((param_2 < 0) || (param_3 < 0)) || (DAT_0042c350 < param_2)) || (DAT_0042c354 < param_3)) {
    FUN_0040187a((byte *)s__s__d_____check_control_position_004345b8);
  }
  if ((param_4 < 1) || (param_5 < 1)) {
    FUN_0040187a((byte *)s__s__d_____check_control_position_00434624);
  }
  if (((DAT_0042c350 < param_4) || (DAT_0042c354 < param_5)) ||
     ((DAT_0042c350 < param_2 + param_4 || (DAT_0042c354 < param_5 + param_3)))) {
    FUN_0040187a((byte *)s__s__d_____check_control_position_00434694);
  }
  return;
}

