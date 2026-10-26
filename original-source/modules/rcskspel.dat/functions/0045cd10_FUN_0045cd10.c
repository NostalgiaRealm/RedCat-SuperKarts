/*
 * FUN_0045cd10 at 0045cd10
 * undefined FUN_0045cd10(void)
 * Address ranges: 0045cd10-0045d006
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0045cd10(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  float10 fVar8;
  undefined1 auStack_4c [4];
  char *pcStack_48;
  undefined1 auStack_3c [4];
  char *pcStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  int iStack_28;
  int iStack_24;
  undefined1 auStack_1c [16];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004ce72e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar2 != (int *)0x0) {
    param_2._0_1_ = SUB41(piVar2,0);
    auStack_4c[0] = param_2._0_1_;
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = s_Width_004f2d0c;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = s_Width_004f2d0c;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcStack_48 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcStack_48 = pcStack_48 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcStack_48 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcStack_48 = pcStack_48 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    uStack_4 = 0;
    uVar3 = FUN_004583c0(auStack_4c);
    FUN_00464150(auStack_2c,uVar3);
    uStack_4 = CONCAT31(uStack_4._1_3_,2);
    FUN_0040b4f0(1);
    if (iStack_24 != 0) {
      auStack_3c[0] = param_2._0_1_;
      FUN_0040b4f0(0);
      uVar4 = 0xffffffff;
      pcVar6 = s_Width_004f2d0c;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4 - 1;
      cVar1 = FUN_0040b600(uVar4,1);
      if (cVar1 != '\0') {
        pcVar6 = s_Width_004f2d0c;
        pcVar7 = pcStack_38;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
          pcVar6 = pcVar6 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar7 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        }
        FUN_0040b5e0(uVar4);
      }
      uStack_4._0_1_ = 3;
      uVar3 = FUN_004583c0(auStack_3c);
      fVar8 = (float10)FUN_00463fb0(uVar3);
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      FUN_0040b4f0(1);
      (**(code **)(*piVar2 + 0x3c))((float)fVar8 / *(float *)(param_1 + 0x18));
    }
    auStack_3c[0] = param_2._0_1_;
    FUN_0040b4f0(0);
    uVar4 = 0xffffffff;
    pcVar6 = s_Height_004f2d14;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4 - 1;
    cVar1 = FUN_0040b600(uVar4,1);
    if (cVar1 != '\0') {
      pcVar6 = s_Height_004f2d14;
      pcVar7 = pcStack_38;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_0040b5e0(uVar4);
    }
    uStack_4._0_1_ = 4;
    uVar3 = FUN_004583c0(auStack_3c);
    uVar3 = FUN_00464150(auStack_1c,uVar3);
    uStack_4._0_1_ = 5;
    FUN_00412870(uVar3,0,0xffffffff);
    uStack_4._0_1_ = 4;
    FUN_0040b4f0(1);
    uStack_4._0_1_ = 2;
    FUN_0040b4f0(1);
    if (iStack_24 != 0) {
      auStack_3c[0] = param_2._0_1_;
      uVar4 = 0xffffffff;
      pcStack_38 = (char *)0x0;
      uStack_34 = 0;
      uStack_30 = 0;
      pcVar6 = s_Height_004f2d14;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b540(s_Height_004f2d14,~uVar4 - 1);
      uStack_4._0_1_ = 6;
      uVar3 = FUN_004583c0(auStack_3c);
      fVar8 = (float10)FUN_00463fb0(uVar3);
      uStack_4._0_1_ = 2;
      if (pcStack_38 != (char *)0x0) {
        cVar1 = pcStack_38[-1];
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150(pcStack_38 + -1);
        }
        else {
          pcStack_38[-1] = cVar1 + -1;
        }
      }
      (**(code **)(*piVar2 + 0x40))((float)fVar8 / *(float *)(param_1 + 0x1c));
    }
    if (iStack_28 != 0) {
      cVar1 = *(char *)(iStack_28 + -1);
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        *(char *)(iStack_28 + -1) = cVar1 + -1;
        ExceptionList = pvStack_c;
        return;
      }
      FUN_004bc150(iStack_28 + -1);
    }
  }
  ExceptionList = pvStack_c;
  return;
}

