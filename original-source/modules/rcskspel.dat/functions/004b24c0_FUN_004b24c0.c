/*
 * FUN_004b24c0 at 004b24c0
 * undefined FUN_004b24c0(void)
 * Address ranges: 004b24c0-004b2596
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004b24c0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (DAT_006ab470 == 0) {
    if (DAT_006ab46c == 0) {
      FUN_004afee0(s__s__d____palette_was_not_initial_004ffe00,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0xee);
    }
    if (param_2 < 0) {
      FUN_004afee0(s__s__d____illegal_palette_base_en_004ffe8c,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0xf1,param_2);
    }
    iVar2 = param_2 + param_3;
    if ((iVar2 < 0) || (0x100 < iVar2)) {
      FUN_004afee0(s__s__d____trying_to_reference_an_i_004ffe4c,
                   s_C__libraries_dxdraw_Pal_cpp_004ffd94,0xf4,iVar2);
    }
    if (((param_4 != 0) && (param_4 != 0x40)) && (param_4 != 0x80)) {
      FUN_004afee0(s__s__d____illegal_flag_value__d_004ffeb8,s_C__libraries_dxdraw_Pal_cpp_004ffd94,
                   0xfa,param_4);
    }
    if (param_2 < iVar2) {
      puVar1 = (undefined1 *)(param_1 + 3 + param_2 * 4);
      iVar2 = iVar2 - param_2;
      do {
        *puVar1 = (char)param_4;
        puVar1 = puVar1 + 4;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (param_5 != 0) {
      FUN_004b2340(param_1,param_2,param_3);
    }
  }
  return;
}

