/*
 * FUN_004ba9d0 at 004ba9d0
 * undefined FUN_004ba9d0(void)
 * Address ranges: 004ba9d0-004baab3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba9d0(int param_1,int param_2,int param_3,byte param_4)

{
  FUN_004ba980(param_1);
  param_1 = param_1 * 0x5c;
  if ((double)*(int *)(&DAT_006aba04 + param_1) * _DAT_00502060 +
      (double)*(int *)(&DAT_006aba04 + param_1) < (double)param_2) {
    *(undefined4 *)(&DAT_006ab9d0 + param_1) = 1;
  }
  if ((double)param_2 <
      (double)*(int *)(&DAT_006aba04 + param_1) -
      (double)*(int *)(&DAT_006aba04 + param_1) * _DAT_00502060) {
    *(undefined4 *)(&DAT_006ab9c8 + param_1) = 1;
  }
  if ((double)*(int *)(&DAT_006aba08 + param_1) * _DAT_00502060 +
      (double)*(int *)(&DAT_006aba08 + param_1) < (double)param_3) {
    *(undefined4 *)(&DAT_006ab9e0 + param_1) = 1;
  }
  if ((double)param_3 <
      (double)*(int *)(&DAT_006aba08 + param_1) -
      (double)*(int *)(&DAT_006aba08 + param_1) * _DAT_00502060) {
    *(undefined4 *)(&DAT_006ab9d8 + param_1) = 1;
  }
  if ((param_4 & 1) != 0) {
    *(undefined4 *)(&DAT_006ab9e8 + param_1) = 1;
  }
  if ((param_4 & 2) != 0) {
    *(undefined4 *)(&DAT_006ab9f0 + param_1) = 1;
  }
  if ((param_4 & 4) != 0) {
    *(undefined4 *)(&DAT_006ab9f8 + param_1) = 1;
  }
  if ((param_4 & 8) != 0) {
    *(undefined4 *)(&DAT_006aba00 + param_1) = 1;
  }
  return;
}

