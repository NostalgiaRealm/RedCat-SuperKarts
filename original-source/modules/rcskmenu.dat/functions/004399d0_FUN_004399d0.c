/*
 * FUN_004399d0 at 004399d0
 * undefined __register FUN_004399d0(int * param_1, int param_2)
 * Address ranges: 004399d0-00439a07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004399d0(int *param_1,int param_2)

{
  param_1[0xb] = param_2;
  FUN_004398c0(param_1);
  if ((PTR_DAT_0047c9d8[9] != '\0') && (param_2 != 0)) {
    if (*(char *)((int)param_1 + 0x35) == '\0') {
      FUN_00439954(param_1);
    }
    else {
      FUN_00439e88(param_1);
    }
  }
  return;
}

