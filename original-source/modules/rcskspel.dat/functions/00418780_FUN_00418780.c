/*
 * FUN_00418780 at 00418780
 * undefined FUN_00418780(void)
 * Address ranges: 00418780-00418943
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00418780(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 local_60 [32];
  char local_40 [64];
  
  FUN_004b1d60(s_car_snd_ini_004e1588);
  FUN_004bea92(local_60,&DAT_004e1598,&DAT_004e1594,param_2);
  iVar2 = FUN_004b1ed0(local_60,s_NrGears_004e15a0);
  *param_1 = iVar2;
  if ((iVar2 < 0) || (6 < iVar2)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  FUN_00492fe0(uVar4,s__s___d__Incorrect_value_for_nr_o_004e15d8,
               s_D__work_rcsk_Code_game_car_snd_c_004e15b4,0x11f,s_car_snd_ini_004e15a8,param_2,
               iVar2,local_60);
  FUN_004186c0();
  FUN_004182f0(local_60);
  FUN_004183d0(local_60);
  FUN_004184b0(local_60);
  FUN_00418590(local_60);
  FUN_004b1f10(local_60,s_Start_004e1630,local_40,0x3f);
  iVar2 = -1;
  pcVar5 = local_40;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00492fe0(iVar2 != -2,s__s___d__No_sound_type_name_found_004e1638,param_2);
  iVar2 = FUN_0049de80(local_40);
  param_1[2] = iVar2;
  FUN_004b1f10(local_60,s_SwitchGear_004e1674,local_40,0x3f);
  iVar2 = -1;
  pcVar5 = local_40;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00492fe0(iVar2 != -2,s__s___d__No_sound_type_name_found_004e1680,param_2);
  iVar2 = FUN_0049de80(local_40);
  param_1[3] = iVar2;
  iVar2 = FUN_0049dd20(iVar2);
  puVar3 = *(undefined1 **)(iVar2 + 0x1c);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  uVar4 = FUN_004b51e0(puVar3,0);
  *(undefined4 *)(iVar2 + 0x38) = uVar4;
  uVar4 = FUN_004b1ed0(local_60,s_MinRpm_004e16c0);
  FUN_00418750(0,uVar4);
  iVar2 = FUN_004b1ed0(local_60,s_MaxRpm_004e16c8);
  param_1[6] = iVar2;
  iVar2 = FUN_004b1ed0(local_60,s_MinSpeed_004e16d0);
  param_1[7] = iVar2;
  iVar2 = FUN_004b1ed0(local_60,s_MaxSpeed_004e16dc);
  param_1[8] = iVar2;
  return;
}

