/*
 * FUN_004b2340 at 004b2340
 * undefined FUN_004b2340(void)
 * Address ranges: 004b2340-004b23f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b2340(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_006ab470 == 0) {
    if (DAT_006ab46c == 0) {
      FUN_004afee0(s__s__d____palette_was_not_initial_004ffe00,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x97);
    }
    if (param_2 < 0) {
      FUN_004afee0(s__s__d____illegal_palette_base_en_004ffe8c,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x9b,param_2);
    }
    iVar1 = param_2 + param_3;
    if ((iVar1 < 0) || (0x100 < iVar1)) {
      FUN_004afee0(s__s__d____trying_to_reference_an_i_004ffe4c,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x9e,iVar1);
    }
    iVar1 = (**(code **)(*DAT_006ab464 + 0x18))(DAT_006ab464,0,param_2,param_3,param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_004b0190(iVar1);
      FUN_004afee0(s__s__d____could_set_entries___s__004ffe28,s_C__libraries_dxdraw_Pal_cpp_004ffd94
                   ,0xa2,uVar2);
    }
  }
  return 0;
}

