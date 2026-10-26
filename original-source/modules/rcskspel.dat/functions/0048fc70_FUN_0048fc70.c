/*
 * FUN_0048fc70 at 0048fc70
 * undefined FUN_0048fc70(void)
 * Address ranges: 0048fc70-0048fd9c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0048fc70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  
  iVar1 = DAT_0067ee28;
  if (DAT_0067ee2c == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_0067ee34,DAT_0067ee24,
                 &DAT_0067ee4d);
    iVar1 = DAT_0067ee28;
  }
  for (; iVar1 < DAT_0067ee24; iVar1 = iVar1 + 1) {
    if (*(char *)(DAT_0067ee30 + iVar1) == '\0') {
      *(undefined1 *)(DAT_0067ee30 + iVar1) = 1;
      DAT_0067ee28 = iVar1;
      goto LAB_0048fd17;
    }
  }
  iVar1 = 0;
  if (0 < DAT_0067ee28) {
    do {
      if (*(char *)(DAT_0067ee30 + iVar1) == '\0') {
        *(undefined1 *)(DAT_0067ee30 + iVar1) = 1;
        DAT_0067ee28 = iVar1;
        goto LAB_0048fd17;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0067ee28);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_0067ee34,DAT_0067ee24,
               &DAT_0067ee4d);
  iVar1 = -1;
LAB_0048fd17:
  FUN_004afce0(s_Adding_main_object___d__004fa500,iVar1);
  FUN_004afce0(s_mesh__d_texture__d_004fa4e8,param_7,param_8);
  FUN_0048ffc0(iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
               param_10,param_11,param_12);
  return iVar1;
}

