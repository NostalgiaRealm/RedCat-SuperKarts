/*
 * FUN_00449710 at 00449710
 * undefined FUN_00449710(void)
 * Address ranges: 00449710-00449857
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00449710(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_80 [64];
  CHAR aCStack_40 [64];
  
  FUN_004b1d60(s_SndGfx_ini_004efef4);
  FUN_004b1f10(s_3D_Anims_004eff08,s_general_004eff00,local_80,0x40);
  iVar2 = -1;
  pcVar3 = local_80;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    FUN_004afee0(s__s___d__Couldn_t_find_filename_f_004eff38,
                 s_D__work_rcsk_Code_game_anm_main__004eff14,0xae);
  }
  FUN_004afce0(s__s__d____Game_etappe_id_before_l_004eff98,
               s_D__work_rcsk_Code_game_anm_main__004eff74,0xb4,DAT_0053b9b4);
  FUN_00449520(local_80);
  FUN_004afce0(s__s__d____Game_etappe_id_after_lo_004efff8,
               s_D__work_rcsk_Code_game_anm_main__004effd4,0xbe,DAT_0053b9b4);
  FUN_004b1d60(s_SndGfx_ini_004f0034);
  wsprintfA(aCStack_40,&DAT_004f0040,DAT_0053b9b4);
  FUN_004b1f10(s_3D_Anims_004f0044,aCStack_40,local_80,0x40);
  iVar2 = -1;
  pcVar3 = local_80;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    FUN_004afee0(s__s___d__Couldn_t_find_filename_f_004f0074,
                 s_D__work_rcsk_Code_game_anm_main__004f0050,0xcd,DAT_0053b9b4);
  }
  FUN_004afce0(s__s__d____Game_etappe_id_before_l_004f00d4,
               s_D__work_rcsk_Code_game_anm_main__004f00b0,0xd4,local_80,DAT_0053b9b4);
  FUN_00449520(local_80);
  FUN_004afce0(s__s__d____Game_etappe_id_after_lo_004f0138,
               s_D__work_rcsk_Code_game_anm_main__004f0114,0xdd,local_80,DAT_0053b9b4);
  return;
}

