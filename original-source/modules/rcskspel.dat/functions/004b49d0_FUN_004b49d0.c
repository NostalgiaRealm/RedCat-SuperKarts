/*
 * FUN_004b49d0 at 004b49d0
 * undefined FUN_004b49d0(void)
 * Address ranges: 004b49d0-004b4aaa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b49d0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_006ab7b4 != 0) {
    if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
      FUN_004afee0(s__s__d____sound_buffer_index_ille_005008b8,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x4a4,param_1);
    }
    iVar3 = param_1 * 0x44;
    if (*(int *)(iVar3 + 0x34 + DAT_006ab798) == 1) {
      FUN_004afee0(s__s__d____type_sound_buffer__d_in_00500958,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x4a9,param_1);
    }
    if (*(int *)(iVar3 + 0x30 + DAT_006ab798) != 0) {
      if ((param_2 < -10000) || (10000 < param_2)) {
        FUN_004afee0(s__s__d____attempt_at_setting_buff_00500924,
                     s_C__libraries_dxdraw_Sound_cpp_00500494,0x4b3,param_1,param_2);
      }
      piVar1 = *(int **)(iVar3 + 0x28 + DAT_006ab798);
      iVar3 = (**(code **)(*piVar1 + 0x40))(piVar1,param_2);
      if (iVar3 != 0) {
        uVar2 = FUN_004b3910(iVar3);
        FUN_004afee0(s__s__d____sound_buffer_index_ille_00500840,
                     s_C__libraries_dxdraw_Sound_cpp_00500494,0x4b7,param_1,uVar2);
      }
    }
  }
  return 0;
}

