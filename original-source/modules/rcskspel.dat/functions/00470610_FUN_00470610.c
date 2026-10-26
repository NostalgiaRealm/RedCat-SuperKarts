/*
 * FUN_00470610 at 00470610
 * undefined FUN_00470610(void)
 * Address ranges: 00470610-004707e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00470610(undefined1 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 auStack_3c [4];
  char *pcStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  uint uStack_24;
  undefined1 auStack_1c [4];
  int iStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d07ea;
  pvStack_c = ExceptionList;
  if ((param_2 < 0) || (ExceptionList = &pvStack_c, 0xb < param_2)) {
    ExceptionList = &pvStack_c;
    FUN_004afee0(s__s__d____Illegal_index__d_004f65b4,s_D__work_rcsk_Code_game_rcr_stop__004f6584,
                 0xb5,param_2);
  }
  iVar2 = FUN_00470560();
  pcVar5 = (&PTR_s_BACKGROUND_004f63f0)[param_2];
  auStack_3c[0] = (undefined1)param_2;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar6 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar6 = pcStack_38;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcStack_38[uVar3] = '\0';
    uStack_34 = uVar3;
  }
  pcVar5 = (&PTR_DAT_004f63e4)[iVar2];
  auStack_2c[0] = (undefined1)param_2;
  uStack_4 = 0;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar6 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    pcVar6 = pcStack_28;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcStack_28[uVar3] = '\0';
    uStack_24 = uVar3;
  }
  uStack_4._0_1_ = 1;
  FUN_00459040(auStack_1c,auStack_2c,auStack_3c);
  uStack_4._0_1_ = 4;
  FUN_0040b4f0(1);
  uStack_4 = CONCAT31(uStack_4._1_3_,3);
  if (pcStack_38 != (char *)0x0) {
    cVar1 = pcStack_38[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(pcStack_38 + -1);
    }
    else {
      pcStack_38[-1] = cVar1 + -1;
    }
  }
  pcStack_38 = (char *)0x0;
  *param_1 = auStack_1c[0];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  FUN_00412870(auStack_1c,0,0xffffffff);
  if (iStack_18 != 0) {
    cVar1 = *(char *)(iStack_18 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(iStack_18 + -1);
    }
    else {
      *(char *)(iStack_18 + -1) = cVar1 + -1;
    }
  }
  ExceptionList = pvStack_c;
  return param_1;
}

