/*
 * FUN_00411830 at 00411830
 * undefined FUN_00411830(void)
 * Address ranges: 00411830-00411a89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411830(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  float10 fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int local_3c;
  undefined4 *local_38;
  uint local_34;
  undefined1 auStack_30 [4];
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [4];
  int iStack_1c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccdf0;
  pvStack_c = ExceptionList;
  local_3c = CONCAT31(local_3c._1_3_,param_3);
  ExceptionList = &pvStack_c;
  FUN_0040b4f0(0);
  uVar3 = 0xffffffff;
  pcVar6 = (char *)&DAT_004dfee4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  cVar1 = FUN_0040b600(uVar3,1);
  if (cVar1 != '\0') {
    puVar2 = &DAT_004dfee4;
    puVar5 = local_38;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(undefined1 *)((int)local_38 + uVar3) = 0;
    local_34 = uVar3;
  }
  local_4 = 0;
  puVar2 = (undefined4 *)FUN_0044a700(param_1);
  (**(code **)*puVar2)(&local_3c);
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_0040b4f0(1);
  param_1[0x1c] = 1;
  fVar7 = (float10)FUN_00456aa0(1,param_2);
  param_1[0x26] = (float)fVar7;
  cVar1 = FUN_0040c9b0();
  if (cVar1 != '\0') {
    FUN_004afce0(s___Attacked_by_redcat_with_shoote_004dfee8,param_2);
  }
  uVar3 = FUN_004be6c9();
  uVar3 = uVar3 & 0x80000001;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
  }
  FUN_0040c960(uVar3 == 0);
  FUN_00411a90(param_1,param_1);
  FUN_00481ec0(*param_1,*param_1);
  cVar1 = FUN_00417e90(param_1);
  if (cVar1 != '\0') {
    uVar3 = 0xffffffff;
    local_3c = 0;
    pcVar6 = s_HIT_BY_ROCKET_004dff1c;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    local_38 = (undefined4 *)0x0;
    local_34 = 0;
    FUN_0040b540(s_HIT_BY_ROCKET_004dff1c,~uVar3 - 1);
    puVar10 = &stack0xffffffc0;
    puStack_8 = (undefined1 *)0x1;
    uVar8 = 10;
    FUN_004371f0(10,puVar10);
    FUN_00437b40(uVar8,puVar10);
    puStack_8 = (undefined1 *)0xffffffff;
    if (local_3c != 0) {
      cVar1 = *(char *)(local_3c + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_3c + -1));
      }
      else {
        *(char *)(local_3c + -1) = cVar1 + -1;
      }
    }
    uVar8 = FUN_004314a0(auStack_20,param_2);
    puStack_8 = (undefined1 *)0x2;
    uVar8 = FUN_00412710(auStack_30,&PTR_DAT_004dff2c,uVar8);
    uVar9 = 10;
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
    FUN_004371f0(10,uVar8);
    FUN_00437b10(uVar9,uVar8);
    if (iStack_2c != 0) {
      cVar1 = *(char *)(iStack_2c + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(iStack_2c + -1));
      }
      else {
        *(char *)(iStack_2c + -1) = cVar1 + -1;
      }
    }
    iStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    if (iStack_1c != 0) {
      cVar1 = *(char *)(iStack_1c + -1);
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        *(char *)(iStack_1c + -1) = cVar1 + -1;
        ExceptionList = pvStack_10;
        return;
      }
      FUN_004bc150((char *)(iStack_1c + -1));
    }
  }
  ExceptionList = pvStack_10;
  return;
}

