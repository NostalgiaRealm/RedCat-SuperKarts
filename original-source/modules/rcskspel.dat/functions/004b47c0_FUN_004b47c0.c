/*
 * FUN_004b47c0 at 004b47c0
 * undefined FUN_004b47c0(void)
 * Address ranges: 004b47c0-004b4876
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b47c0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_006ab7b4 != 0) {
    if ((param_1 < 0) || (DAT_006ab78c < param_1)) {
      FUN_004afee0(s__s__d____sound_buffer_index_ille_005008b8,
                   s_C__libraries_dxdraw_Sound_cpp_00500494,0x402,param_1);
    }
    if (*(int *)(param_1 * 0x44 + 0x30 + DAT_006ab798) != 0) {
      if (((param_2 < 100) || (100000 < param_2)) && (param_2 != 0)) {
        FUN_004afee0(s__s__d____attempt_at_setting_buff_00500870,
                     s_C__libraries_dxdraw_Sound_cpp_00500494,0x40c,param_1,param_2);
      }
      piVar1 = *(int **)(param_1 * 0x44 + 0x28 + DAT_006ab798);
      iVar2 = (**(code **)(*piVar1 + 0x44))(piVar1,param_2);
      if (iVar2 != 0) {
        uVar3 = FUN_004b3910(iVar2);
        FUN_004afee0(s__s__d____sound_buffer_index_ille_00500840,
                     s_C__libraries_dxdraw_Sound_cpp_00500494,0x410,param_1,uVar3);
      }
    }
  }
  return 0;
}

