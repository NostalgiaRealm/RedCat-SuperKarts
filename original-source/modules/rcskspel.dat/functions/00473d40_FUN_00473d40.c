/*
 * FUN_00473d40 at 00473d40
 * undefined FUN_00473d40(void)
 * Address ranges: 00473d40-00473d60;00473d70-00473ed5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473d40(void)

{
  undefined4 local_4;
  
  if (DAT_006abae0 == 0) {
    do {
      local_4 = 0x473d4e;
      FUN_004baf80();
    } while (DAT_006abae0 == 0);
    FUN_004707f0();
    FUN_004afce0(s___Restoring_all_surfaces_004f7634);
    FUN_00471820();
    FUN_004b08e0(DAT_006a64a0);
    FUN_004b08e0(DAT_006a64c0);
    FUN_004b08e0(DAT_006a64bc);
    FUN_004afce0(s_redrawing__s__d__004f7674,s_D__work_rcsk_Code_game_stoppen_c_004f7650,0x117);
    FUN_004715e0(2,0,9);
    FUN_004afce0(s_redrawing__s__d__004f76ac,s_D__work_rcsk_Code_game_stoppen_c_004f7688,0x119);
    FUN_004715e0(2,1,9);
    FUN_004afce0(s_redrawing__s__d__004f76e4,s_D__work_rcsk_Code_game_stoppen_c_004f76c0,0x11b);
    FUN_004715e0(2,3,9);
    FUN_004afce0(s_redrawing__s__d__004f771c,s_D__work_rcsk_Code_game_stoppen_c_004f76f8,0x11d);
    FUN_004715e0(2,5,9);
    FUN_004afce0(s_redrawing__s__d__004f7754,s_D__work_rcsk_Code_game_stoppen_c_004f7730,0x11f);
    FUN_004715e0(2,8,9);
    FUN_004afce0(s_back_screen_update_004f7768);
    if (DAT_006abae0 != 0) {
      FUN_004b6120(2,1,0,0,0x280,0x1e0,0,0,DAT_004fe930,DAT_004fe934,4);
    }
    FUN_004afce0(s_rendering_screen_004f777c);
    FUN_004739c0(&local_4);
    FUN_00471df0(1);
    FUN_004afce0(s_flipping_page_004f7790);
    FUN_004aff70();
    return;
  }
  FUN_004baf80();
  return;
}

