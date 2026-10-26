/*
 * FUN_00407940 at 00407940
 * undefined FUN_00407940(void)
 * Address ranges: 00407940-00407a3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407940(int *param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  bool bVar7;
  
  iVar3 = FUN_004be6c9();
  if (DAT_00505060 == 0) {
    iVar3 = (int)DAT_0050506d;
    iVar6 = 0;
    if (iVar3 <= DAT_00505900) {
      puVar5 = &DAT_0050506d;
      do {
        bVar7 = iVar6 == DAT_00505064;
        if (DAT_00505064 <= iVar6) goto LAB_004079e9;
        pcVar1 = puVar5 + 8;
        puVar5 = puVar5 + 8;
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + *pcVar1;
        FUN_004afce0(s_Trying_new_entry_004deaa4);
      } while (iVar3 <= DAT_00505900);
    }
    bVar7 = iVar6 == DAT_00505064;
LAB_004079e9:
    if (bVar7) {
      FUN_004afee0(s___s___d_Total_traffic_types_do_n_004deadc,
                   s_D__work_rcsk_Code_game_ai_nwtrf__004deab8,0x10f);
    }
    DAT_00505900 = DAT_00505900 + 1;
    FUN_004afce0(s_Added__d_cars_004deb14,DAT_00505900);
  }
  else {
    iVar4 = (int)DAT_0050506d;
    iVar6 = 0;
    if (iVar4 < iVar3 % 100) {
      puVar5 = &DAT_0050506d;
      do {
        iVar2 = iVar6 - DAT_00505064;
        if (DAT_00505064 <= iVar6) goto LAB_00407985;
        pcVar1 = puVar5 + 8;
        puVar5 = puVar5 + 8;
        iVar4 = iVar4 + *pcVar1;
        iVar6 = iVar6 + 1;
      } while (iVar4 < iVar3 % 100);
    }
    iVar2 = iVar6 - DAT_00505064;
LAB_00407985:
    if (iVar6 != DAT_00505064 && SBORROW4(iVar6,DAT_00505064) == iVar2 < 0) {
      FUN_004afee0(s___s___d_Total_traffic_types_do_n_004dea70,
                   s_D__work_rcsk_Code_game_ai_nwtrf__004dea4c,0xfe);
    }
  }
  *param_2 = (int)(char)(&DAT_0050506c)[iVar6 * 8];
  *param_1 = iVar6;
  FUN_004afce0(s_Returning_car_data_004deb24);
  return;
}

