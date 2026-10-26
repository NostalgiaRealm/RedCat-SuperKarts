/*
 * FUN_00449ae0 at 00449ae0
 * undefined FUN_00449ae0(void)
 * Address ranges: 00449ae0-00449b2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00449ae0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0xc) <= param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  FUN_00492fe0(uVar1,s__s___d__Illegal_index_frame__Fra_004f0274,
               s_D__work_rcsk_Code_game_anm_type__004f0250,0xd9,param_2);
  *(undefined4 *)(*(int *)(param_1 + 8) + param_2 * 8) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 8) + 4 + param_2 * 8) = param_4;
  return;
}

