/*
 * FUN_0046e070 at 0046e070
 * undefined FUN_0046e070(void)
 * Address ranges: 0046e070-0046e25a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e070(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EBP;
  char *pcVar7;
  char *pcVar8;
  float local_48;
  float local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  char *local_38;
  uint local_34;
  int local_30;
  undefined1 local_2c [16];
  undefined1 local_1c [8];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d0572;
  pvStack_c = ExceptionList;
  local_4 = 0xffffffff;
  ExceptionList = &pvStack_c;
  uVar2 = FUN_00463d20(local_1c,param_1 + 1);
  local_4 = 2;
  FUN_00412710(local_2c,&DAT_004f5d70,uVar2);
  local_4._0_1_ = 4;
  FUN_0040b4f0(1);
  local_3c[0] = (undefined1)param_1;
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar7 = s_ovrlster_004f5d78;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  cVar1 = FUN_0040b600(uVar5,1);
  if (cVar1 != '\0') {
    pcVar7 = s_ovrlster_004f5d78;
    pcVar8 = local_38;
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
    local_38[uVar5] = '\0';
    local_34 = uVar5;
  }
  local_4._0_1_ = 5;
  piVar3 = (int *)FUN_00460940(param_2,local_3c,local_2c);
  local_4 = CONCAT31(local_4._1_3_,4);
  if (local_38 != (char *)0x0) {
    cVar1 = local_38[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_38 + -1);
    }
    else {
      local_38[-1] = cVar1 + -1;
    }
  }
  iVar4 = (DAT_004fc8f8 & (param_1 << 0xc) / 0xc) * 4;
  local_38 = (char *)0x0;
  local_34 = 0;
  local_44 = *(float *)(iVar4 + DAT_006a5cd0) * _DAT_004f5c70;
  local_48 = *(float *)(iVar4 + DAT_006a5c88) * _DAT_004f5c70;
  local_30 = 0;
  local_40 = 0x3a83126f;
  FUN_00458400(&local_48);
  (**(code **)(*piVar3 + 0x28))(&DAT_004d2db4);
  (**(code **)(*piVar3 + 0x24))(&DAT_00544b50);
  FUN_00458460(1);
  *(int **)(unaff_EBP + 0xc + param_1 * 4) = piVar3;
  if (local_30 != 0) {
    cVar1 = *(char *)(local_30 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_30 + -1) = cVar1 + -1;
      ExceptionList = pvStack_14;
      return;
    }
    FUN_004bc150(local_30 + -1);
  }
  ExceptionList = pvStack_14;
  return;
}

