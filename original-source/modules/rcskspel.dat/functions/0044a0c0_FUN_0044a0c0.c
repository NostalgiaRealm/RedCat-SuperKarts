/*
 * FUN_0044a0c0 at 0044a0c0
 * undefined FUN_0044a0c0(void)
 * Address ranges: 0044a0c0-0044a170
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044a0c0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004afce0(s_Adding_animation_type_object__d_004f0520,param_2);
  iVar1 = *(int *)(param_1 + 0x408);
  if ((iVar1 < 0) || (0x3f < iVar1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  FUN_00492fe0(uVar2,s__s___d__Illegal_index_number_of_o_004f0568,
               s_D__work_rcsk_Code_game_anm_type__004f0544,0x259,iVar1);
  iVar1 = FUN_0044a070(param_2);
  FUN_00492fe0(iVar1 != -1,s__s___d__Can_t_find_animation_typ_004f05d4,
               s_D__work_rcsk_Code_game_anm_type__004f05b0,0x25e,param_2);
  *(undefined4 *)(*(int *)(param_1 + 0x408) * 0x10 + 8 + param_1) = param_2;
  *(int *)((*(int *)(param_1 + 0x408) + 1) * 0x10 + param_1) = iVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x408) * 0x10 + 0xc + param_1) = 0;
  *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + 1;
  return;
}

