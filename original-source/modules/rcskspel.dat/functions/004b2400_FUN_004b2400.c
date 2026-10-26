/*
 * FUN_004b2400 at 004b2400
 * undefined FUN_004b2400(void)
 * Address ranges: 004b2400-004b24b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b2400(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_006ab470 == 0) {
    if (DAT_006ab46c == 0) {
      FUN_004afee0(s__s__d____palette_was_not_initial_004ffe00,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0xbe);
    }
    if (param_2 < 0) {
      FUN_004afee0(s__s__d____illegal_palette_base_en_004ffe8c,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0xc1,param_2);
    }
    iVar1 = param_2 + param_3;
    if ((iVar1 < 0) || (0x100 < iVar1)) {
      FUN_004afee0(s__s__d____trying_to_reference_an_i_004ffe4c,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0xc4,iVar1);
    }
    iVar1 = (**(code **)(*DAT_006ab464 + 0x10))(DAT_006ab464,0,param_2,param_3,param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_004b0190(iVar1);
      FUN_004afee0(s__s__d____could_set_entries___s__004ffe28,s_C__libraries_dxdraw_Pal_cpp_004ffd94
                   ,200,uVar2);
    }
  }
  return 0;
}

