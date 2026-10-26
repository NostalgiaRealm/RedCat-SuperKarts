/*
 * FUN_0040fe50 at 0040fe50
 * undefined FUN_0040fe50(void)
 * Address ranges: 0040fe50-00410098
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0040fe50(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 local_164 [100];
  undefined4 local_100 [64];
  
  FUN_004afce0(s__s__d____Reading_AI_data_for__d_004df9e0,
               s_D__work_rcsk_Code_game_ai_rcr_se_004df9b4,0x371,param_2);
  FUN_004b1d60(PTR_s_npc_ai_INI_004df2a4);
  FUN_004be8cb(local_164,100,s_Person__d_004df9a8,param_2);
  FUN_004100a0(local_164,param_2);
  iVar2 = FUN_004b1ed0(local_164,s_bonus_awareness_004df95c);
  if (iVar2 == 0) {
    iVar2 = 3;
    FUN_004b1e70(local_164,s_bonus_awareness_004df95c,3);
  }
  *param_1 = iVar2;
  FUN_004afce0(s__s__d____bonus_awareness____d_004dfa30,s_D__work_rcsk_Code_game_ai_rcr_se_004dfa04,
               0x388,iVar2);
  iVar2 = FUN_004b1ed0(local_164,s_driving_style_004df96c);
  if (iVar2 == 0) {
    iVar2 = 3;
    FUN_004b1e70(local_164,s_driving_style_004df96c,3);
  }
  param_1[1] = iVar2;
  FUN_004afce0(s__s__d____driving_style____d_004dfa7c,s_D__work_rcsk_Code_game_ai_rcr_se_004dfa50,
               0x396,iVar2);
  iVar2 = FUN_004b1ed0(local_164,s_efficiency_004df97c);
  if (iVar2 == 0) {
    iVar2 = 3;
    FUN_004b1e70(local_164,s_efficiency_004df97c,3);
  }
  param_1[2] = iVar2;
  FUN_004afce0(s__s__d____efficiency____d_004dfac8,s_D__work_rcsk_Code_game_ai_rcr_se_004dfa9c,0x3a6
               ,iVar2);
  iVar2 = FUN_004b1ed0(local_164,s_reaction_004df988);
  if (iVar2 == 0) {
    iVar2 = 3;
    FUN_004b1e70(local_164,s_reaction_004df988,3);
  }
  param_1[4] = iVar2;
  FUN_004afce0(s__s__d____reaction____d_004dfb10,s_D__work_rcsk_Code_game_ai_rcr_se_004dfae4,0x3b4,
               iVar2);
  iVar2 = FUN_004b1ed0(local_164,&DAT_004df994);
  if (iVar2 == 0) {
    iVar2 = 3;
    FUN_004b1e70(local_164,&DAT_004df994,3);
  }
  param_1[3] = iVar2;
  FUN_004afce0(s__s__d____mass____d_004dfb54,s_D__work_rcsk_Code_game_ai_rcr_se_004dfb28,0x3c2,iVar2
              );
  FUN_004b1f10(local_164,s_pref_bonus_004df99c,local_100,0xff);
  iVar2 = -1;
  pcVar3 = (char *)local_100;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    FUN_004b1e30(local_164,s_pref_bonus_004df99c,&DAT_004dfb68);
    local_100[0] = CONCAT31(local_100[0]._1_3_,0x52);
  }
  iVar2 = FUN_0040f410(local_100[0]);
  param_1[5] = iVar2;
  if (iVar2 == 4) {
    param_1[5] = 0;
    local_100[0] = CONCAT31(local_100[0]._1_3_,0x52);
  }
  FUN_004afce0(s__s__d____preferred_bonus____c_004dfb98,s_D__work_rcsk_Code_game_ai_rcr_se_004dfb6c,
               0x3da,(int)(char)local_100[0]);
  return;
}

