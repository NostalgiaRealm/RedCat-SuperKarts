/*
 * FUN_0041cdd0 at 0041cdd0
 * undefined FUN_0041cdd0(void)
 * Address ranges: 0041cdd0-0041d000
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041cdd0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 uStack_128;
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [4];
  undefined1 auStack_100 [4];
  undefined1 auStack_fc [4];
  undefined1 auStack_f8 [4];
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [4];
  undefined1 auStack_ec [4];
  undefined1 local_e8 [32];
  char local_c8 [200];
  
  FUN_004b1d60(s_SndGfx_ini_004e2bb4);
  FUN_004bea92(local_e8,&DAT_004e2bc0,5);
  FUN_004b1f10(&DAT_004e2bc4,local_e8,local_c8,199);
  iVar2 = -1;
  pcVar4 = local_c8;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    FUN_004afee0(s__s__d____No__valid__ini_settings_004e2bf0,
                 s_D__work_rcsk_Code_game_cm_main_c_004e2bcc,0x98);
  }
  iVar2 = FUN_004b1f60(local_c8,0);
  if (iVar2 != 4) {
    FUN_004afee0(s__s__d____Not_the_right_number_of_004e2c44,
                 s_D__work_rcsk_Code_game_cm_main_c_004e2c20,0xa1);
  }
  FUN_0041baf0(0,&uStack_128);
  FUN_0041baf0(1,auStack_124);
  FUN_0041baf0(2,auStack_120);
  FUN_0041baf0(3,auStack_11c);
  FUN_004bea92(local_e8,&DAT_004e2c78,6);
  FUN_004b1f10(&DAT_004e2c7c,local_e8,local_c8,199);
  FUN_004b1f60(local_c8,0);
  FUN_0041baf0(0,auStack_118);
  FUN_0041baf0(1,auStack_114);
  FUN_0041baf0(2,auStack_110);
  FUN_0041baf0(3,auStack_10c);
  FUN_004bea92(local_e8,&DAT_004e2c84,7);
  FUN_004b1f10(&DAT_004e2c88,local_e8,local_c8,199);
  FUN_004b1f60(local_c8,0);
  FUN_0041baf0(0,auStack_108);
  FUN_0041baf0(1,auStack_104);
  FUN_0041baf0(2,auStack_100);
  FUN_0041baf0(3,auStack_fc);
  FUN_004bea92(local_e8,&DAT_004e2c90,8);
  FUN_004b1f10(&DAT_004e2c94,local_e8,local_c8,199);
  FUN_004b1f60(local_c8,0);
  FUN_0041baf0(0,auStack_f8);
  FUN_0041baf0(1,auStack_f4);
  FUN_0041baf0(2,auStack_f0);
  FUN_0041baf0(3,auStack_ec);
  puVar3 = &uStack_128;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

