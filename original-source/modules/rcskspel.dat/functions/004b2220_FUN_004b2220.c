/*
 * FUN_004b2220 at 004b2220
 * undefined FUN_004b2220(void)
 * Address ranges: 004b2220-004b2335
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b2220(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_006ab470 == 0) {
    if (DAT_006ab46c == 0) {
      FUN_004afee0(s__s__d____palette_was_not_initial_004ffe00,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x5b);
    }
    if (param_1 == 0) {
      FUN_004b08e0(DAT_006a64bc);
      iVar1 = (**(code **)(*DAT_006a64bc + 0x7c))(DAT_006a64bc,DAT_006ab464);
      if (iVar1 != 0) {
        uVar2 = FUN_004b0190(iVar1);
        FUN_004afee0(s__s__d____could_not_set_the_palet_004ffdb0,
                     s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x65,uVar2);
      }
    }
    else if (param_1 == 1) {
      FUN_004b08e0(DAT_006a64c0);
      iVar1 = (**(code **)(*DAT_006a64c0 + 0x7c))(DAT_006a64c0,DAT_006ab464);
      if (iVar1 != 0) {
        uVar2 = FUN_004b0190(iVar1);
        FUN_004afee0(s__s__d____could_not_set_the_palet_004ffdb0,
                     s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x6e,uVar2);
        return;
      }
    }
    else {
      if (param_1 != 2) {
        FUN_004afee0(s__s__d____unknown_focus_defined_004ffddc,
                     s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x7b);
        return;
      }
      FUN_004b08e0(DAT_006a64a0);
      iVar1 = (**(code **)(*DAT_006a64a0 + 0x7c))(DAT_006a64a0,DAT_006ab464);
      if (iVar1 != 0) {
        uVar2 = FUN_004b0190(iVar1);
        FUN_004afee0(s__s__d____could_not_set_the_palet_004ffdb0,
                     s_C__libraries_dxdraw_Pal_cpp_004ffd94,0x77,uVar2);
        return;
      }
    }
  }
  return;
}

