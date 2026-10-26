/*
 * FUN_0049aec0 at 0049aec0
 * undefined FUN_0049aec0(void)
 * Address ranges: 0049aec0-0049b09b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049aec0(uint param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004afce0(s_Initing__d_damage_objects__004fb8b4,param_1);
  if (DAT_006847dc != 0) {
    if (DAT_006847dc == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006847fd,&DAT_006847e4,
                   DAT_006847d4);
      FUN_004bc150(DAT_006847d0);
    }
    if (DAT_006847dc != 0) {
      FUN_004bc150(DAT_006847e0);
      DAT_006847dc = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_006847fd,&DAT_006847e4,
                 param_1);
  }
  DAT_006847d0 = operator_new(param_1 * 4);
  DAT_006847d4 = param_1;
  DAT_006847d8 = 0;
  DAT_006847e0 = operator_new(param_1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006847fd,&DAT_006847e4,DAT_006847d4)
  ;
  DAT_006847dc = 1;
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      iVar1 = iVar2 + 1;
      *(undefined1 *)((int)DAT_006847e0 + iVar2) = 0;
      iVar2 = iVar1;
    } while (iVar1 < (int)param_1);
  }
  FUN_004afce0(s_Initialising____004fb8a0);
  iVar2 = 0;
  if ((int)param_1 < 1) {
LAB_0049b081:
    FUN_004afce0(s_Done__004fb898);
    return;
  }
LAB_0049afe3:
  iVar1 = DAT_006847d8;
  if (DAT_006847dc == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_006847e4,DAT_006847d4,
                 &DAT_006847fd);
    iVar1 = DAT_006847d8;
  }
  for (; iVar1 < (int)DAT_006847d4; iVar1 = iVar1 + 1) {
    if (*(char *)((int)DAT_006847e0 + iVar1) == '\0') goto LAB_0049b091;
  }
  iVar1 = 0;
  if (0 < DAT_006847d8) {
    do {
      if (*(char *)((int)DAT_006847e0 + iVar1) == '\0') goto LAB_0049b091;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_006847d8);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_006847e4,DAT_006847d4,
               &DAT_006847fd);
  goto LAB_0049b069;
LAB_0049b091:
  *(undefined1 *)((int)DAT_006847e0 + iVar1) = 1;
  DAT_006847d8 = iVar1;
LAB_0049b069:
  iVar2 = iVar2 + 1;
  *(undefined4 *)((int)DAT_006847d0 + iVar2 * 4 + -4) = 0;
  if ((int)param_1 <= iVar2) goto LAB_0049b081;
  goto LAB_0049afe3;
}

