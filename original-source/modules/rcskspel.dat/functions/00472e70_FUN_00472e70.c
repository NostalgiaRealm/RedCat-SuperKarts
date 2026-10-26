/*
 * FUN_00472e70 at 00472e70
 * undefined FUN_00472e70(void)
 * Address ranges: 00472e70-00472ed0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00472e70(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_004afce0(s_load_tga_file___s__004f72a0,param_2);
  if (param_1 == 1) {
    uVar1 = FUN_00472ce0(DAT_006a64c0,param_2);
    return uVar1;
  }
  if (param_1 != 2) {
    FUN_004afee0(s__s__d____unidentified_focus_erro_004f72d8,
                 s_D__work_rcsk_Code_game_rrrtga_cp_004f72b4,0x290,param_1);
    return 1;
  }
  uVar1 = FUN_00472ce0(DAT_006a64a0,param_2);
  return uVar1;
}

