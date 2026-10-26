/*
 * FUN_00430470 at 00430470
 * undefined FUN_00430470(void)
 * Address ranges: 00430470-004304c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430470(void)

{
  int iVar1;
  
  iVar1 = FUN_00429210();
  if (iVar1 == 1) {
    FUN_004aff70();
    return;
  }
  if (iVar1 != 2) {
    FUN_004afee0(s__s__d_____winmain____Illegal_ren_004eb094,
                 s_D__work_rcsk_Code_game_Gm_main_c_004eb070,0x46d);
    return;
  }
  FUN_004b6120(2,1,0,0,DAT_004fe930,DAT_004fe934,0,0,DAT_004fe930,DAT_004fe934,0);
  FUN_004aff70();
  return;
}

