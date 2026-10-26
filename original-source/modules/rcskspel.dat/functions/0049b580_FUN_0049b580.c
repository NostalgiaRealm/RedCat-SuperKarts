/*
 * FUN_0049b580 at 0049b580
 * undefined FUN_0049b580(void)
 * Address ranges: 0049b580-0049b865
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0049b580(char *param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined4 local_100 [32];
  char local_80 [128];
  
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x17b);
  iVar8 = 0;
  piVar3 = &DAT_00684898;
  do {
    if (*piVar3 < 0) break;
    piVar3 = piVar3 + 0x22;
    iVar8 = iVar8 + 1;
  } while ((int)piVar3 < 0x6a5bd8);
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x185);
  if (iVar8 == 1000) {
    return -1;
  }
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x18e);
  uVar5 = 0xffffffff;
  pcVar10 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  pcVar10 = param_2 + (~uVar5 - 4);
  uVar5 = 0xffffffff;
  pcVar10[0] = '\0';
  pcVar10[1] = '\0';
  pcVar10[2] = '\0';
  pcVar10 = &DAT_004fba58;
  do {
    pcVar13 = pcVar10;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar13 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar13;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar6 = -1;
  pcVar10 = param_2;
  do {
    pcVar11 = pcVar10;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar11 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar11;
  } while (cVar1 != '\0');
  pcVar10 = pcVar13 + -uVar5;
  pcVar13 = pcVar11 + -1;
  for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar13 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar13 = pcVar13 + 1;
  }
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x196);
  pcVar10 = local_80;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar10[0] = '\0';
    pcVar10[1] = '\0';
    pcVar10[2] = '\0';
    pcVar10[3] = '\0';
    pcVar10 = pcVar10 + 4;
  }
  puVar12 = local_100;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  FUN_0049b350(param_1,param_2,local_80,local_100);
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x19d);
  bVar2 = false;
  iVar6 = 0;
  if (0 < DAT_006a5ee4) {
    iVar9 = 0;
    do {
      if (bVar2) goto LAB_0049b75b;
      if ((iVar9 < 0) || (DAT_006a5ee4 <= iVar6)) {
        FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                     s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar6,&DAT_006a5ef4,
                     DAT_006a5ee4,&DAT_006a5f0d);
      }
      if (*(char *)(DAT_006a5ef0 + iVar6) == '\x01') {
        puVar12 = (undefined4 *)(iVar9 + 0xa8 + DAT_006a5ee0);
        if (*(int *)(iVar9 + 0xac + DAT_006a5ee0) == 0) {
          FUN_004afee0(s__s__d____string_is_not_initialis_004fb8fc,
                       s_______Libs_Win3DLib_Include_str__004fb924,0x24);
        }
        iVar4 = __strcmpi(local_80,(char *)*puVar12);
        if (iVar4 != 0) goto LAB_0049b743;
        bVar2 = true;
      }
      else {
LAB_0049b743:
        iVar6 = iVar6 + 1;
        iVar9 = iVar9 + 0xbc;
      }
    } while (iVar6 < DAT_006a5ee4);
    if (bVar2) {
LAB_0049b75b:
      if (iVar6 != -1) goto LAB_0049b77e;
    }
  }
  iVar6 = FUN_004a7680(2,local_80);
LAB_0049b77e:
  (&DAT_00684898)[iVar8 * 0x22] = iVar6;
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x1a2);
  iVar6 = FUN_0049b190(local_100);
  if (iVar6 == -1) {
    if (param_3 == 0) {
      iVar6 = FUN_004a3a70(local_100);
    }
    else if (param_4 == 0) {
      iVar6 = FUN_004a3760(local_100);
    }
    else {
      iVar6 = FUN_004a33b0(local_100);
    }
  }
  (&DAT_0068489c)[iVar8 * 0x22] = iVar6;
  FUN_004afce0(s___s__d_004fba5c,s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x1a7);
  uVar5 = 0xffffffff;
  pcVar10 = param_1;
  do {
    pcVar13 = pcVar10;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar13 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar13;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar10 = pcVar13 + -uVar5;
  pcVar13 = (char *)(&DAT_00684818 + iVar8 * 0x22);
  for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar13 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar13 = pcVar13 + 1;
  }
  FUN_004afce0(s_Created_ANIM__s_with_index__d__M_004fba24,param_1,iVar8,
               (&DAT_00684898)[iVar8 * 0x22],(&DAT_0068489c)[iVar8 * 0x22]);
  return iVar8;
}

