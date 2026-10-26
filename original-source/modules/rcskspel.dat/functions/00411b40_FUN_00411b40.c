/*
 * FUN_00411b40 at 00411b40
 * undefined FUN_00411b40(void)
 * Address ranges: 00411b40-00411da0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411b40(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  float10 fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int local_3c [4];
  undefined1 local_2c [4];
  char *local_28;
  uint local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  int local_18;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cce1a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined4 *)(param_2 + 0x70) = 1;
  fVar7 = (float10)FUN_00456aa0(2,param_3);
  *(float *)(param_2 + 0x98) = (float)fVar7;
  *(undefined1 *)(param_2 + 0xfc) = 1;
  cVar1 = FUN_0040c9b0();
  if (cVar1 != '\0') {
    FUN_004afce0(s___Attacked_by_redcat_with_shoote_004dff74,param_3);
  }
  FUN_0040c960(6);
  if ((param_3 == 2) || (param_3 == 3)) {
    FUN_00411db0(param_1,param_2);
  }
  cVar1 = FUN_00417e90(param_1);
  if (cVar1 != '\0') {
    local_2c[0] = (undefined1)param_1;
    FUN_0040b4f0(0);
    uVar3 = 0xffffffff;
    pcVar5 = s_HIT_BY_SOAP_004dffa8;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar5 = s_HIT_BY_SOAP_004dffa8;
      pcVar6 = local_28;
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
      local_28[uVar3] = '\0';
      local_24 = uVar3;
    }
    puVar10 = local_2c;
    local_4 = 0;
    uVar8 = 10;
    FUN_004371f0(10,puVar10);
    FUN_00437b40(uVar8,puVar10);
    local_4 = 0xffffffff;
    FUN_0040b4f0(1);
    uVar8 = FUN_004314a0(local_1c,param_3);
    local_4 = 1;
    uVar8 = FUN_00412710(local_2c,s_SOAP_UP_004dffb4,uVar8);
    uVar9 = 10;
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_004371f0(10,uVar8);
    FUN_00437b10(uVar9,uVar8);
    if (local_28 != (char *)0x0) {
      cVar1 = local_28[-1];
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150(local_28 + -1);
      }
      else {
        local_28[-1] = cVar1 + -1;
      }
    }
    local_28 = (char *)0x0;
    local_24 = 0;
    local_20 = 0;
    local_4 = 0xffffffff;
    if (local_18 != 0) {
      cVar1 = *(char *)(local_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_18 + -1));
      }
      else {
        *(char *)(local_18 + -1) = cVar1 + -1;
      }
    }
  }
  uVar3 = 0xffffffff;
  pcVar5 = &DAT_004dffbc;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_3c[0] = CONCAT31(local_3c[0]._1_3_,(undefined1)param_1);
  local_3c[1] = 0;
  local_3c[2] = 0;
  local_3c[3] = 0;
  FUN_0040b540(&DAT_004dffbc,~uVar3 - 1);
  local_4 = 3;
  puVar2 = (undefined4 *)FUN_0044a700(param_1);
  (**(code **)*puVar2)(local_3c);
  puStack_8 = (undefined1 *)0xffffffff;
  if (local_3c[0] != 0) {
    cVar1 = *(char *)(local_3c[0] + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_3c[0] + -1));
    }
    else {
      *(char *)(local_3c[0] + -1) = cVar1 + -1;
    }
  }
  local_3c[0] = 0;
  local_3c[1] = 0;
  local_3c[2] = 0;
  FUN_00457730(param_1);
  FUN_00457780(param_1);
  ExceptionList = pvStack_10;
  return;
}

