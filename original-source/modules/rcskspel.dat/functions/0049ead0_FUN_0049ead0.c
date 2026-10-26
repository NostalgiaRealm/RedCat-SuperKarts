/*
 * FUN_0049ead0 at 0049ead0
 * undefined FUN_0049ead0(void)
 * Address ranges: 0049ead0-0049eb75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049ead0(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d16eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[2] = param_2;
  piVar1 = operator_new(param_2 * 0x38 + 4);
  local_4 = 0;
  if (piVar1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = piVar1 + 1;
    *piVar1 = param_2;
    FUN_004be91c(piVar2,0x38,param_2,FUN_0049f040,FUN_0049f1a0);
  }
  local_4 = 0xffffffff;
  *param_1 = (int)piVar2;
  FUN_0049f2a0(piVar2 != (int *)0x0,s__s___d__Couldn_t_allocate_sound_t_004fc454,
               s_D__work_rcracer_oursoundlib_soun_004fc4a8,0x50,param_1[2]);
  ExceptionList = local_c;
  return;
}

