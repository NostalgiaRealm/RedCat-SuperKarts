/*
 * FUN_00428e50 at 00428e50
 * undefined FUN_00428e50(void)
 * Address ranges: 00428e50-00428ef5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428e50(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  if (DAT_004e7be8 == 1) {
    FUN_004afee0(s__s__d____Function___s___Unable_t_004e7e7c,
                 s_D__work_rcsk_Code_game_gm_body_c_004e7e58,0x6e,
                 s_skelet2d_set_image_filename___004e7e38);
  }
  _strncpy((char *)&DAT_004e7ba5,param_1,8);
  uVar4 = 0xffffffff;
  pcVar7 = (char *)&DAT_004e7ba5;
  do {
    pcVar8 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar8 + -uVar4;
  pcVar8 = (char *)&DAT_004e7b95;
  for (uVar5 = uVar4 >> 2; uVar3 = DAT_004e7ed8, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; cVar1 = DAT_004e7ed4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  PTR_DAT_004e7bae._0_1_ = 0;
  PTR_DAT_004e7b9e._0_1_ = 0;
  iVar6 = -1;
  pcVar7 = (char *)&DAT_004e7ba5;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  *(undefined4 *)(pcVar8 + -1) = DAT_004e7ed0;
  pcVar8[3] = cVar1;
  cVar1 = DAT_004e7edc;
  iVar6 = -1;
  pcVar7 = (char *)&DAT_004e7b95;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  *(undefined4 *)(pcVar8 + -1) = uVar3;
  pcVar8[3] = cVar1;
  return;
}

