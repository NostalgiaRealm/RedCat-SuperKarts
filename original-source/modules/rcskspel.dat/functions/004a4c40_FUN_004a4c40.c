/*
 * FUN_004a4c40 at 004a4c40
 * undefined FUN_004a4c40(void)
 * Address ranges: 004a4c40-004a4e55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004a4c40(undefined4 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1796;
  local_c = ExceptionList;
  pcVar2 = (char *)(param_1 + 0xb);
  ExceptionList = &local_c;
  param_1[9] = 0;
  _strncpy(pcVar2,s_Meshlist_004fcd7c,0x19);
  pcVar1 = (char *)((int)param_1 + 0x45);
  _strncpy(pcVar1,s_meshes_t_004fcd70,0x19);
  if (param_1[9] != 0) {
    if (param_1[9] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,pcVar1,pcVar2,param_1[7]);
      FUN_004bc150(param_1[6]);
    }
    if (param_1[9] != 0) {
      FUN_004bc150(param_1[10]);
      param_1[9] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,pcVar1,pcVar2,0);
  param_1[10] = 0;
  param_1[9] = 0;
  pcVar2 = (char *)((int)param_1 + 0x72);
  local_4 = 0;
  *(undefined4 *)((int)param_1 + 0x6a) = 0;
  _strncpy(pcVar2,s_Texturelist_004fcd64,0x19);
  pcVar1 = (char *)((int)param_1 + 0x8b);
  _strncpy(pcVar1,s_textures_t_004fcd58,0x19);
  if (*(int *)((int)param_1 + 0x6a) != 0) {
    if (*(int *)((int)param_1 + 0x6a) == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,pcVar1,pcVar2,
                   *(undefined4 *)((int)param_1 + 0x62));
      FUN_004bc150(*(undefined4 *)((int)param_1 + 0x5e));
    }
    if (*(int *)((int)param_1 + 0x6a) != 0) {
      FUN_004bc150(*(undefined4 *)((int)param_1 + 0x6e));
      *(undefined4 *)((int)param_1 + 0x6a) = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  *(undefined4 *)((int)param_1 + 0x5e) = 0;
  *(undefined4 *)((int)param_1 + 0x62) = 0;
  *(undefined4 *)((int)param_1 + 0x66) = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,pcVar1,pcVar2,0);
  *(undefined4 *)((int)param_1 + 0x6e) = 0;
  *(undefined4 *)((int)param_1 + 0x6a) = 0;
  pcVar2 = (char *)(param_1 + 0x2e);
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x2c] = 0;
  _strncpy(pcVar2,s_Animnamelist_004fcd48,0x19);
  pcVar1 = (char *)((int)param_1 + 0xd1);
  _strncpy(pcVar1,s_anim_name_t_004fcd3c,0x19);
  if (param_1[0x2c] != 0) {
    if (param_1[0x2c] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,pcVar1,pcVar2,param_1[0x2a]);
      FUN_004bc150(param_1[0x29]);
    }
    if (param_1[0x2c] != 0) {
      FUN_004bc150(param_1[0x2d]);
      param_1[0x2c] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,pcVar1,pcVar2,0);
  param_1[0x2d] = 0;
  param_1[0x2c] = 0;
  *param_1 = 0;
  param_1[5] = 0;
  ExceptionList = local_c;
  return param_1;
}

