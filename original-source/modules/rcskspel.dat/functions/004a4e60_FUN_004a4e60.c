/*
 * FUN_004a4e60 at 004a4e60
 * undefined FUN_004a4e60(void)
 * Address ranges: 004a4e60-004a4fb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a4e60(int *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_004d17c4;
  local_c = ExceptionList;
  local_4 = 2;
  ExceptionList = &local_c;
  if (*param_1 == 1) {
    ExceptionList = &local_c;
    FUN_004a4fc0();
  }
  local_4 = CONCAT31(local_4._1_3_,1);
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
  local_4 = local_4 & 0xffffff00;
  if (*(int *)((int)param_1 + 0x6a) == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x8b,(int)param_1 + 0x72
                 ,*(undefined4 *)((int)param_1 + 0x62));
    FUN_004bc150(*(undefined4 *)((int)param_1 + 0x5e));
  }
  if (*(int *)((int)param_1 + 0x6a) != 0) {
    FUN_004bc150(*(undefined4 *)((int)param_1 + 0x6e));
    *(undefined4 *)((int)param_1 + 0x6a) = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  local_4 = 0xffffffff;
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
  ExceptionList = local_c;
  return;
}

