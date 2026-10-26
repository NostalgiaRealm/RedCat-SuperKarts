/*
 * FUN_0049dc60 at 0049dc60
 * undefined FUN_0049dc60(void)
 * Address ranges: 0049dc60-0049dca6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049dc60(undefined4 *param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  
  param_1[2] = param_3;
  param_1[1] = 0;
  pvVar1 = operator_new(param_3 << 2);
  *param_1 = pvVar1;
  FUN_0049f2a0(pvVar1 != (void *)0x0,s__s___d__Couldn_t_allocate_sound_s_004fbe40,
               s_D__work_rcracer_oursoundlib_soun_004fbe98,0x53,param_1[2]);
  param_1[3] = param_2;
  return;
}

