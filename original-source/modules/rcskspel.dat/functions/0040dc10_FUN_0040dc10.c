/*
 * FUN_0040dc10 at 0040dc10
 * undefined FUN_0040dc10(void)
 * Address ranges: 0040dc10-0040ddcd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040dc10(int param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int unaff_ESI;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  float10 fVar9;
  undefined1 local_2c [4];
  undefined4 *local_28;
  char *local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccd52;
  local_c = ExceptionList;
  if ((&DAT_00503ef4)[param_1 * 0x47] != 9) {
    ExceptionList = &local_c;
    (&DAT_00503fe0)[param_1 * 0x11c] = 1;
    fVar9 = (float10)FUN_0048f4d0();
    local_2c[0] = (undefined1)param_1;
    uVar3 = 0xffffffff;
    pcVar6 = (char *)&DAT_004defdc;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    *(float *)(&DAT_00503fe4 + param_1 * 0x11c) = (float)fVar9;
    local_28 = (undefined4 *)0x0;
    local_24 = (char *)0x0;
    local_20 = 0;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      puVar5 = &DAT_004defdc;
      puVar7 = local_28;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      FUN_0040b5e0(uVar3);
    }
    local_4 = 0;
    piVar2 = (int *)FUN_0044a700(param_1);
    (**(code **)(*piVar2 + 0xc))(local_2c,6,6);
    uStack_10 = 0xffffffff;
    if (unaff_ESI != 0) {
      cVar1 = *(char *)(unaff_ESI + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(unaff_ESI + -1));
      }
      else {
        *(char *)(unaff_ESI + -1) = cVar1 + -1;
      }
    }
    uVar3 = 0xffffffff;
    pcVar6 = s_IDLE_TURBO_004defe4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    local_28 = (undefined4 *)CONCAT31(local_28._1_3_,puStack_8._0_1_);
    local_24 = (char *)0x0;
    local_20 = 0;
    uStack_1c = 0;
    cVar1 = FUN_0040b600(uVar3,1);
    if (cVar1 != '\0') {
      pcVar6 = s_IDLE_TURBO_004defe4;
      pcVar8 = local_24;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      }
      FUN_0040b5e0(uVar3);
    }
    uStack_10 = 1;
    piVar2 = (int *)FUN_0044a700(puStack_8);
    (**(code **)(*piVar2 + 0xc))(&local_28,0,6);
    if (iStack_18 != 0) {
      cVar1 = *(char *)(iStack_18 + -1);
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        *(char *)(iStack_18 + -1) = cVar1 + -1;
        ExceptionList = local_c;
        return;
      }
      FUN_004bc150((char *)(iStack_18 + -1));
    }
  }
  ExceptionList = local_c;
  return;
}

