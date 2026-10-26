/*
 * FUN_0049dd70 at 0049dd70
 * undefined FUN_0049dd70(void)
 * Address ranges: 0049dd70-0049de7f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0049dd70(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d161b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0049f2a0(*param_1 != 0,s__s___d__Sound_sources_not_alloca_004fc01c,
               s_D__work_rcracer_oursoundlib_soun_004fbe98,0xae);
  iVar1 = param_1[1];
  if ((iVar1 < 0) || (param_1[2] <= iVar1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  FUN_0049f2a0(uVar3,s__s___d__Illegal_index_number_of_s_004fbfe4,
               s_D__work_rcracer_oursoundlib_soun_004fbe98,0xb3,iVar1);
  pvVar2 = operator_new(0x58);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_0049f2a0(param_1[3] != 0,s__s___d__Sound_source_list_not_in_004fbf90,s___csslist_h_004fbfd8,
                 100);
    uVar3 = FUN_0049d320(param_1[3],param_2,param_1[1]);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(*param_1 + param_1[1] * 4) = uVar3;
  FUN_0049f2a0(*(int *)(*param_1 + param_1[1] * 4) != 0,s__s___d__Couldn_t_allocate_sound_s_004fbf64
               ,s_D__work_rcracer_oursoundlib_soun_004fbe98,0xb8,param_1[1]);
  iVar1 = param_1[1];
  param_1[1] = iVar1 + 1;
  ExceptionList = local_c;
  return iVar1;
}

