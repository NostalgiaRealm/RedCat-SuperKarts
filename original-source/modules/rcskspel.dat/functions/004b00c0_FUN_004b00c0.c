/*
 * FUN_004b00c0 at 004b00c0
 * undefined FUN_004b00c0(void)
 * Address ranges: 004b00c0-004b0183
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b00c0(int param_1,uint param_2,int param_3)

{
  if (param_1 == 0) {
    if (((int)param_2 < 0) || (0x14 < (int)param_2)) {
      FUN_004afee0(s__s__d____error_predefined_screen_004febe0,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x576);
    }
    DAT_004fe92c = param_2;
    DAT_004fe930 = (&DAT_004fe948)[param_2 * 5];
    DAT_004fe934 = (&DAT_004fe94c)[param_2 * 5];
    DAT_004fe938 = (&DAT_004fe950)[param_2 * 5];
    DAT_006a64f0 = *(undefined4 *)(&DAT_004fe954 + param_2 * 0x14);
    return 0;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      FUN_004afee0(s__s__d____unknown_variable___d__r_004fec24,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x589,param_1);
      return 0;
    }
    DAT_004fe944 = param_2;
    return 0;
  }
  if (param_3 == 1) {
    DAT_004fe93c = DAT_004fe93c | param_2;
    return 0;
  }
  DAT_004fe93c = param_2;
  return 0;
}

