/*
 * FUN_00422810 at 00422810
 * undefined FUN_00422810(void)
 * Address ranges: 00422810-004228fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00422810(undefined4 *param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[3] != 0) {
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
  }
  if ((int)param_2 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s____Libs_win3dlib_Include_array_h_004de7b4,0x107,(int)param_1 + 0x2d,param_1 + 5,
                 param_2);
  }
  pvVar1 = operator_new(param_2 * 0x44);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  *param_1 = pvVar1;
  param_1[1] = param_2;
  param_1[2] = 0;
  pvVar1 = operator_new(param_2);
  param_1[4] = pvVar1;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,(int)param_1 + 0x2d,param_1 + 5,
               param_1[1]);
  param_1[3] = 1;
  iVar2 = 0;
  if (0 < (int)param_2) {
    do {
      iVar3 = iVar2 + 1;
      *(undefined1 *)(iVar2 + param_1[4]) = 0;
      iVar2 = iVar3;
    } while (iVar3 < (int)param_2);
  }
  return;
}

