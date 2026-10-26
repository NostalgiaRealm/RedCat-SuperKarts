/*
 * FUN_0041cc70 at 0041cc70
 * undefined FUN_0041cc70(void)
 * Address ranges: 0041cc70-0041cd42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041cc70(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 local_e8 [32];
  char local_c8 [200];
  
  FUN_004b1d60(s_SndGfx_ini_004e2acc);
  FUN_004bea92(local_e8,&DAT_004e2ad8,4);
  FUN_004b1f10(&DAT_004e2adc,local_e8,local_c8,199);
  iVar2 = -1;
  pcVar3 = local_c8;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    FUN_004afee0(s__s__d____No__valid__ini_settings_004e2b08,
                 s_D__work_rcsk_Code_game_cm_main_c_004e2ae4,0x68);
  }
  iVar2 = FUN_004b1f60(local_c8,0);
  if (iVar2 != 3) {
    FUN_004afee0(s__s__d____Not_the_right_number_of_004e2b5c,
                 s_D__work_rcsk_Code_game_cm_main_c_004e2b38,0x71);
  }
  FUN_0041baf0(0,&uStack_f4);
  FUN_0041baf0(1,&uStack_f0);
  FUN_0041baf0(2,&uStack_ec);
  *param_1 = uStack_f4;
  param_1[1] = uStack_f0;
  param_1[2] = uStack_ec;
  return;
}

