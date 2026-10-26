/*
 * FUN_0041d1d0 at 0041d1d0
 * undefined FUN_0041d1d0(void)
 * Address ranges: 0041d1d0-0041d27d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_0041d1d0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  float fStack_ec;
  undefined1 local_e8 [32];
  char local_c8 [200];
  
  FUN_004b1d60(s_SndGfx_ini_004e2d08);
  FUN_004bea92(local_e8,&DAT_004e2d14,param_1);
  FUN_004b1f10(&DAT_004e2d18,local_e8,local_c8,199);
  iVar2 = -1;
  pcVar3 = local_c8;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    FUN_004afee0(s__s__d____No__valid__ini_settings_004e2d44,
                 s_D__work_rcsk_Code_game_cm_main_c_004e2d20,0xf7);
  }
  iVar2 = FUN_004b1f60(local_c8,0);
  if (iVar2 != 1) {
    FUN_004afee0(s__s__d____Not_the_right_number_of_004e2d98,
                 s_D__work_rcsk_Code_game_cm_main_c_004e2d74,0x100);
  }
  FUN_0041baf0(0,&fStack_ec);
  return (float10)fStack_ec;
}

