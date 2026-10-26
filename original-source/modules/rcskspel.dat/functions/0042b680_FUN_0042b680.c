/*
 * FUN_0042b680 at 0042b680
 * undefined FUN_0042b680(void)
 * Address ranges: 0042b680-0042b7af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b680(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  CHAR local_40 [64];
  
  FUN_004b1d60(s_Race_ini_004e9430);
  wsprintfA(local_40,s_LAP_RECORD_E_d_004e943c,DAT_0053b9b4);
  DAT_0053ba0c = FUN_004b1ed0(s_BEST_TIMES_004e944c,local_40);
  if (DAT_0053ba0c == 0) {
    DAT_0053ba0c = 0xfffffff;
  }
  wsprintfA(local_40,s_RACE_RECORD_E_d_004e9458,DAT_0053b9b4);
  DAT_0053ba10 = FUN_004b1ed0(s_BEST_TIMES_004e9468,local_40);
  if (DAT_0053ba10 == 0) {
    DAT_0053ba10 = 0xfffffff;
  }
  FUN_004bea92(local_40,s_TIME_CHECK_COUNT_E_d_004e9474,DAT_0053b9b4);
  iVar1 = FUN_004b1ed0(s_BEST_TIMES_004e948c,local_40);
  if ((iVar1 < 0) || (9 < iVar1)) {
    FUN_004afee0(s__s___d__Incorrect_nr_of_time_che_004e94bc,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e9498,0x251,iVar1);
  }
  iVar3 = 0;
  if (0 < iVar1) {
    piVar4 = &DAT_0053d300;
    do {
      wsprintfA(local_40,s_TIME_CHECK_E_d_C_d_004e94f4,DAT_0053b9b4,iVar3);
      iVar2 = FUN_004b1ed0(s_BEST_TIMES_004e9508,local_40);
      *piVar4 = iVar2;
      if (iVar2 == 0) {
        FUN_004afee0(s__s___d__Value_not_found_for_chec_004e9538,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e9514,0x25c,DAT_0053b9b4,iVar3);
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

