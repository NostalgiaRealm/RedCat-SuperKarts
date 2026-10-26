/*
 * FUN_004817c0 at 004817c0
 * undefined FUN_004817c0(void)
 * Address ranges: 004817c0-00481816
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004817c0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00428df0();
  switch(uVar1) {
  case 0:
  case 1:
    FUN_004afce0(s__s__d____Palette_required_004f992c,s_D__work_rcsk_Code_game_ScreenInf_004f9904,
                 0x4b);
    return 1;
  default:
    FUN_004afee0(s__s__d____Unsupported_resolution___004f9970,
                 s_D__work_rcsk_Code_game_ScreenInf_004f9948,0x50,uVar1);
    return 0;
  case 3:
  case 4:
  case 6:
    FUN_004afce0(s__s__d____No_palette_required_004f98e4,s_D__work_rcsk_Code_game_ScreenInf_004f98bc
                 ,0x47);
    return 0;
  }
}

