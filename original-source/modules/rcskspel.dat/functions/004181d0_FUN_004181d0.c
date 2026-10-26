/*
 * FUN_004181d0 at 004181d0
 * undefined FUN_004181d0(void)
 * Address ranges: 004181d0-004182cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004181d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char local_40 [64];
  
  FUN_004b1f10(param_1,param_2,local_40,0x3f);
  iVar3 = -1;
  pcVar4 = local_40;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00492fe0(iVar3 != -2,s__s__d__Can_t_find_car_sound_sett_004e1254,
               s_D__work_rcsk_Code_game_car_snd_c_004e1230,0x55,param_1,param_2);
  iVar3 = FUN_004b1f60(local_40,0);
  FUN_00492fe0(iVar3 == 4,s__s___d__Incorrect_number_of_argu_004e12b8,
               s_D__work_rcsk_Code_game_car_snd_c_004e1294,0x5e,param_2,iVar3,4);
  uVar2 = FUN_004b20c0(0);
  *param_3 = uVar2;
  uVar2 = FUN_004b20c0(1);
  param_3[1] = uVar2;
  iVar3 = FUN_004b20c0(2);
  param_3[2] = iVar3;
  if ((iVar3 < 0) || (100 < iVar3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  FUN_00492fe0(uVar2,s__s___d__Incorrect_value_for_mini_004e1340,
               s_D__work_rcsk_Code_game_car_snd_c_004e131c,0x66,iVar3,param_1);
  iVar3 = FUN_004b20c0(3);
  param_3[3] = iVar3;
  if ((iVar3 < 0) || (100 < iVar3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  FUN_00492fe0(uVar2,s__s___d__Incorrect_value_for_maxi_004e13a8,
               s_D__work_rcsk_Code_game_car_snd_c_004e1384,0x6b,param_3[2],param_1);
  return;
}

