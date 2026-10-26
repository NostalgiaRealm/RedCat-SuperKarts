/*
 * FUN_00418ad8 at 00418ad8
 * undefined __cdecl FUN_00418ad8(int param_1, int param_2, int param_3, uint param_4)
 * Address ranges: 00418ad8-00418c40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418ad8(int param_1,int param_2,int param_3,uint param_4)

{
  FUN_00418a53(param_1);
  if ((double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40 +
      (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) < (double)param_2) {
    *(undefined4 *)(&DAT_0043dcf8 + param_1 * 0x5c) = 1;
  }
  if ((double)param_2 <
      (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) -
      (double)*(int *)(&DAT_0043dd2c + param_1 * 0x5c) * _DAT_00435c40) {
    *(undefined4 *)(&DAT_0043dcf0 + param_1 * 0x5c) = 1;
  }
  if ((double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40 +
      (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) < (double)param_3) {
    *(undefined4 *)(&DAT_0043dd08 + param_1 * 0x5c) = 1;
  }
  if ((double)param_3 <
      (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) -
      (double)*(int *)(&DAT_0043dd30 + param_1 * 0x5c) * _DAT_00435c40) {
    *(undefined4 *)(&DAT_0043dd00 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 1) != 0) {
    *(undefined4 *)(&DAT_0043dd10 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 2) != 0) {
    *(undefined4 *)(&DAT_0043dd18 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 4) != 0) {
    *(undefined4 *)(&DAT_0043dd20 + param_1 * 0x5c) = 1;
  }
  if ((param_4 & 8) != 0) {
    *(undefined4 *)(&DAT_0043dd28 + param_1 * 0x5c) = 1;
  }
  return;
}

