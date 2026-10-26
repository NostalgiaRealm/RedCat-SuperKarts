/*
 * FUN_0047ea20 at 0047ea20
 * undefined FUN_0047ea20(void)
 * Address ranges: 0047ea20-0047ed4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0047ea20(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [4];
  char *pcStack_90;
  uint uStack_8c;
  undefined1 auStack_84 [16];
  int iStack_74;
  char acStack_70 [100];
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d118a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (param_4 < 6) {
    puVar2 = (undefined1 *)param_2[1];
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    ExceptionList = &pvStack_c;
    FUN_004afee0(s__s__d____requester_item__s_has_n_004f8de8,
                 s_D__work_rcsk_Code_game_Requester_004f8dc0,0x131,puVar2,param_4,6);
  }
  puVar2 = &DAT_004d2404;
  if (*(undefined1 **)(param_3 + 4) != (undefined1 *)0x0) {
    puVar2 = *(undefined1 **)(param_3 + 4);
  }
  puVar3 = (undefined1 *)param_2[1];
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Enter_InterpreteRequest_004f8e50,
               s_D__work_rcsk_Code_game_Requester_004f8e28,0x138,puVar3,puVar2,param_4);
  FUN_004b2110(1,acStack_70,99);
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar7 = acStack_70;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  cVar1 = FUN_0040b600(uVar5,1);
  if (cVar1 != '\0') {
    pcVar7 = acStack_70;
    pcVar8 = pcStack_90;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcStack_90[uVar5] = '\0';
    uStack_8c = uVar5;
  }
  iStack_4 = 0;
  FUN_00477790();
  FUN_004b20c0(2);
  uStack_a4 = __ftol();
  FUN_004b20c0(3);
  uStack_a0 = __ftol();
  FUN_004b20c0(4);
  uStack_9c = __ftol();
  FUN_004b20c0(5);
  uStack_98 = __ftol();
  pcVar7 = "";
  if (pcStack_90 != (char *)0x0) {
    pcVar7 = pcStack_90;
  }
  puVar2 = (undefined1 *)param_2[1];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar3 = *(undefined1 **)(param_3 + 4);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Create__s___s___s__c_re_004f8eac,
               s_D__work_rcsk_Code_game_Requester_004f8e84,0x14d,puVar3,puVar2,pcVar7,uStack_a4,
               uStack_a0,uStack_9c,uStack_98);
  puVar10 = &uStack_a4;
  puVar2 = auStack_94;
  iVar4 = param_3;
  puVar9 = param_2;
  FUN_0047df70(param_3,param_2,puVar2,puVar10);
  iVar4 = FUN_0047e030(iVar4,puVar9,puVar2,puVar10);
  if (iVar4 == 0) {
    FUN_004afce0(s__s__d____Failed_to_alloc_request_004f8f0c,
                 s_D__work_rcsk_Code_game_Requester_004f8ee4,0x15a,*param_2,param_2[1],param_2[2],
                 param_2[3]);
  }
  else {
    FUN_004afce0(s__s__d____Adding_to_items_list_004f8f64,
                 s_D__work_rcsk_Code_game_Requester_004f8f3c,0x160);
    FUN_0042eab0(param_2);
    iStack_4._0_1_ = 1;
    iStack_74 = iVar4;
    FUN_00480ab0(*(undefined4 *)(param_1 + 0x78),1,auStack_84);
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    FUN_0040b4f0(1);
  }
  puVar2 = &DAT_004d2404;
  if (*(undefined1 **)(param_3 + 4) != (undefined1 *)0x0) {
    puVar2 = *(undefined1 **)(param_3 + 4);
  }
  puVar3 = (undefined1 *)param_2[1];
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Leave_InterpreteRequest_004f8fac,
               s_D__work_rcsk_Code_game_Requester_004f8f84,0x164,puVar3,puVar2,param_4);
  if (pcStack_90 != (char *)0x0) {
    cVar1 = pcStack_90[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(pcStack_90 + -1);
    }
    else {
      pcStack_90[-1] = cVar1 + -1;
    }
  }
  ExceptionList = pvStack_c;
  return;
}

