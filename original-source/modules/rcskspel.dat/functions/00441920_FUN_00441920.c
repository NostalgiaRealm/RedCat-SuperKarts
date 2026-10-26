/*
 * FUN_00441920 at 00441920
 * undefined FUN_00441920(void)
 * Address ranges: 00441920-0044196d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00441920(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x290) = param_2;
  if (*(int *)(param_1 + 0x27c) != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x25c) + 100))
                      (*(int **)(param_1 + 0x25c),6,*(undefined4 *)(param_1 + 0x290));
    if (iVar1 != 0) {
      uVar2 = FUN_004aaa00(iVar1);
      FUN_004afee0(s__s__d_____FOG__error_setting_ren_004e3adc,
                   s____Libs_win3dlib_Include_d3dev_i_004e3040,0xb8,uVar2);
    }
  }
  return;
}

