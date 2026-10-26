/*
 * FUN_004a09e0 at 004a09e0
 * undefined FUN_004a09e0(void)
 * Address ranges: 004a09e0-004a0d70
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a09e0(int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined1 local_600 [64];
  undefined1 local_5c0 [64];
  undefined1 local_580 [64];
  undefined1 local_540 [64];
  undefined1 local_500 [64];
  undefined1 local_4c0 [64];
  undefined1 local_480 [64];
  undefined1 local_440 [64];
  undefined1 local_400 [64];
  undefined1 local_3c0 [64];
  undefined1 local_380 [64];
  undefined1 local_340 [64];
  undefined1 local_300 [64];
  undefined1 local_2c0 [64];
  undefined1 local_280 [64];
  undefined1 local_240 [64];
  undefined1 local_200 [64];
  undefined1 local_1c0 [64];
  undefined1 local_180 [64];
  undefined1 local_140 [64];
  undefined1 local_100 [64];
  undefined1 local_c0 [64];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  puVar1 = (undefined4 *)(param_1 + 0x10);
  puVar4 = &DAT_006a5c90;
  puVar7 = puVar1;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  if (DAT_004fc6e8 == 0) {
    if (*(float *)(param_1 + 0x7c) != 0.0) {
      uVar3 = __ftol(puVar1);
      uVar3 = FUN_004a22e0(local_2c0,uVar3);
      puVar4 = (undefined4 *)FUN_004a2560(local_240,uVar3);
      puVar7 = puVar1;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if (*(float *)(param_1 + 0x74) != 0.0) {
      uVar3 = __ftol(puVar1);
      uVar3 = FUN_004a2200(local_1c0,uVar3);
      puVar4 = (undefined4 *)FUN_004a2560(local_140,uVar3);
      puVar7 = puVar1;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if (*(float *)(param_1 + 0x78) == 0.0) goto LAB_004a0d2f;
    uVar3 = __ftol(puVar1);
    uVar3 = FUN_004a2270(local_c0,uVar3);
    puVar6 = local_40;
  }
  else if (DAT_004fc6e8 == 1) {
    if (*(float *)(param_1 + 0x7c) != 0.0) {
      uVar3 = __ftol(puVar1);
      uVar3 = FUN_004a22e0(local_5c0,uVar3);
      puVar4 = (undefined4 *)FUN_004a2560(local_540,uVar3);
      puVar7 = puVar1;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if (*(float *)(param_1 + 0x78) != 0.0) {
      uVar3 = __ftol(puVar1);
      uVar3 = FUN_004a2270(local_4c0,uVar3);
      puVar4 = (undefined4 *)FUN_004a2560(local_440,uVar3);
      puVar7 = puVar1;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if (*(float *)(param_1 + 0x74) == 0.0) goto LAB_004a0d2f;
    uVar3 = __ftol(puVar1);
    uVar3 = FUN_004a2200(local_3c0,uVar3);
    puVar6 = local_340;
  }
  else {
    bVar2 = *(float *)(param_1 + 0x74) != 0.0;
    if (DAT_004fc6e8 == 2) {
      if (bVar2) {
        uVar3 = __ftol(puVar1);
        uVar3 = FUN_004a2200(local_80,uVar3);
        puVar4 = (undefined4 *)FUN_004a2560(local_400,uVar3);
        puVar7 = puVar1;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      if (*(float *)(param_1 + 0x78) != 0.0) {
        uVar3 = __ftol(puVar1);
        uVar3 = FUN_004a2270(local_200,uVar3);
        puVar4 = (undefined4 *)FUN_004a2560(local_380,uVar3);
        puVar7 = puVar1;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      if (*(float *)(param_1 + 0x7c) == 0.0) goto LAB_004a0d2f;
      uVar3 = __ftol(puVar1);
      uVar3 = FUN_004a22e0(local_100,uVar3);
      puVar6 = local_600;
    }
    else {
      if (bVar2) {
        uVar3 = __ftol(puVar1);
        uVar3 = FUN_004a2200(local_300,uVar3);
        puVar4 = (undefined4 *)FUN_004a2560(local_580,uVar3);
        puVar7 = puVar1;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      if (*(float *)(param_1 + 0x78) != 0.0) {
        uVar3 = __ftol(puVar1);
        uVar3 = FUN_004a2270(local_180,uVar3);
        puVar4 = (undefined4 *)FUN_004a2560(local_500,uVar3);
        puVar7 = puVar1;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      if (*(float *)(param_1 + 0x7c) == 0.0) goto LAB_004a0d2f;
      uVar3 = __ftol(puVar1);
      uVar3 = FUN_004a22e0(local_280,uVar3);
      puVar6 = local_480;
    }
  }
  puVar4 = (undefined4 *)FUN_004a2560(puVar6,uVar3);
  puVar7 = puVar1;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
LAB_004a0d2f:
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x58);
  FUN_004a26b0(puVar1,*(undefined4 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x84),
               *(undefined4 *)(param_1 + 0x88));
  return;
}

