/*
 * FUN_004a4fc0 at 004a4fc0
 * undefined FUN_004a4fc0(void)
 * Address ranges: 004a4fc0-004a50f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a4fc0(int *param_1)

{
  FUN_004afce0(s_Exit_animsys_004fcd88);
  if (*param_1 != 0) {
    FUN_004a6470();
    if (param_1[9] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x45,param_1 + 0xb,
                   param_1[7]);
      FUN_004bc150(param_1[6]);
    }
    if (param_1[9] != 0) {
      FUN_004bc150(param_1[10]);
      param_1[9] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
    if (*(int *)((int)param_1 + 0x6a) == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x8b,
                   (int)param_1 + 0x72,*(undefined4 *)((int)param_1 + 0x62));
      FUN_004bc150(*(undefined4 *)((int)param_1 + 0x5e));
    }
    if (*(int *)((int)param_1 + 0x6a) != 0) {
      FUN_004bc150(*(undefined4 *)((int)param_1 + 0x6e));
      *(undefined4 *)((int)param_1 + 0x6a) = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
    if (param_1[0x2c] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0xd1,param_1 + 0x2e,
                   param_1[0x2a]);
      FUN_004bc150(param_1[0x29]);
    }
    if (param_1[0x2c] != 0) {
      FUN_004bc150(param_1[0x2d]);
      param_1[0x2c] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  *param_1 = 0;
  return;
}

