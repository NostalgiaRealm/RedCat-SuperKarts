/*
 * FUN_00481730 at 00481730
 * undefined FUN_00481730(void)
 * Address ranges: 00481730-004817a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00481730(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00428df0();
  switch(uVar1) {
  case 0:
    FUN_004afce0(s__s__d____Lowres_screen_004f9858,s_D__work_rcsk_Code_game_ScreenInf_004f9830,0x2d)
    ;
    return 0;
  case 1:
    FUN_004afce0(s__s__d____Highres_screen_004f9814,s_D__work_rcsk_Code_game_ScreenInf_004f97ec,0x2a
                );
    return 1;
  default:
    FUN_004afee0(s__s__d____Unsupported_resolution___004f9898,
                 s_D__work_rcsk_Code_game_ScreenInf_004f9870,0x32,uVar1);
    return 0;
  case 3:
  case 4:
  case 6:
    FUN_004afce0(s__s__d____Highres_screen_004f97d0,s_D__work_rcsk_Code_game_ScreenInf_004f97a8,0x27
                );
    return 1;
  }
}

