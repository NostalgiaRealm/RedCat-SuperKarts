/*
 * FUN_00491670 at 00491670
 * undefined FUN_00491670(void)
 * Address ranges: 00491670-004916e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00491670(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_0067ee68 = 0;
  DAT_0067ee6c = 0;
  if (DAT_006802b2 == 0) {
    FUN_004afce0(s_drawing_object_textured_004fa920);
    FUN_004918f0(param_1,param_2,param_3,param_4);
  }
  else {
    FUN_004afce0(s_drawing_normal_004fa910);
    FUN_004916f0(param_1,param_2,param_3,param_4);
  }
  FUN_0048f600();
  FUN_004afce0(s_Ready_drawing_004fa900);
  return;
}

