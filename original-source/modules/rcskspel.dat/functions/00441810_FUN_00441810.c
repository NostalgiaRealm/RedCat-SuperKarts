/*
 * FUN_00441810 at 00441810
 * undefined FUN_00441810(void)
 * Address ranges: 00441810-0044183f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00441810(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x20))(*(int **)(param_1 + 0x2c),param_2);
  if (iVar1 != 0) {
    uVar2 = FUN_004aaa00(iVar1);
    FUN_004afee0(s__s__d____error_setting_material_a_004ecd18,
                 s____Libs_win3dlib_Include_viewpor_004ecd50,0x5e,uVar2);
  }
  return;
}

