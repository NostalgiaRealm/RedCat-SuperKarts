/*
 * FUN_00470560 at 00470560
 * undefined FUN_00470560(void)
 * Address ranges: 00470560-00470597
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00470560(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00428df0();
  switch(uVar1) {
  case 0:
    goto switchD_0047056a_caseD_0;
  case 1:
    return 1;
  default:
    FUN_004afee0(s__s__d____Unsupported_resolution___004f650c,
                 s_D__work_rcsk_Code_game_rcr_stop__004f64dc,0x84,uVar1);
switchD_0047056a_caseD_0:
    return 0;
  case 3:
  case 4:
  case 6:
    return 2;
  }
}

