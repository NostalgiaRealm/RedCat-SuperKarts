/*
 * FUN_00405f70 at 00405f70
 * undefined FUN_00405f70(void)
 * Address ranges: 00405f70-00405fc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00405f70(undefined4 *param_1)

{
  if (param_1[3] == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x2d,param_1 + 5,
                 param_1[1]);
    FUN_004bc150(*param_1);
  }
  if (param_1[3] != 0) {
    FUN_004bc150(param_1[4]);
    param_1[3] = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

