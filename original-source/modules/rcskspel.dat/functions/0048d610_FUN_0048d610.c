/*
 * FUN_0048d610 at 0048d610
 * undefined FUN_0048d610(void)
 * Address ranges: 0048d610-0048d922
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048d610(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  float10 fVar7;
  int local_36c;
  undefined4 *local_368;
  int local_360;
  undefined4 local_358;
  float local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340 [16];
  undefined4 local_300 [16];
  undefined4 local_2c0 [16];
  undefined4 local_280 [16];
  undefined4 local_240 [16];
  undefined4 local_200 [16];
  undefined4 local_1c0 [16];
  undefined1 local_180 [64];
  undefined1 local_140 [64];
  undefined1 local_100 [64];
  undefined1 local_c0 [64];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  if (((DAT_0053ba78 != 0) && (DAT_0053ba60 != 0)) && (DAT_0053b9b0 == 0)) {
    puVar4 = (undefined4 *)
             (DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x1180) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
             + 0x10);
    puVar2 = local_1c0;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    local_358 = 0;
    local_350 = 0xc2200000;
    local_354 = 0.0;
    fVar7 = (float10)FUN_0048f4e0();
    fVar7 = ((float10)60.0 / ((float10)1.0 / fVar7)) * (float10)60.0 +
            (float10)*(float *)(param_1 + 0x11a8);
    *(float *)(param_1 + 0x11a8) = (float)fVar7;
    if ((float10)4096.0 < fVar7) {
      *(float *)(param_1 + 0x11a8) = (float)(fVar7 - (float10)4096.0);
    }
    local_36c = 0;
    puVar4 = &DAT_006a5c90;
    puVar2 = local_2c0;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    puVar4 = &DAT_006a5c90;
    puVar2 = local_300;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    puVar4 = &DAT_006a5c90;
    puVar2 = local_240;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    puVar4 = &DAT_006a5c90;
    puVar2 = local_200;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    puVar4 = &DAT_006a5c90;
    puVar2 = local_280;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    puVar4 = &DAT_006a5c90;
    puVar2 = local_340;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    local_368 = (undefined4 *)(param_1 + 8);
    do {
      local_354 = local_354 + 2.0;
      local_360 = 0;
      if (0 < *(int *)(param_1 + 0x11a4)) {
        uVar1 = __ftol();
        puVar5 = &DAT_0067e478;
        puVar4 = local_368;
        do {
          puVar2 = (undefined4 *)FUN_004a2510(local_80,0x41200000,0x41200000,0x3f800000);
          puVar6 = local_340;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar6 = puVar6 + 1;
          }
          puVar2 = (undefined4 *)FUN_004a2270(local_100,uVar1);
          puVar6 = local_2c0;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar6 = puVar6 + 1;
          }
          puVar2 = (undefined4 *)FUN_004a24c0(local_180,&local_358);
          puVar6 = local_240;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar6 = puVar6 + 1;
          }
          puVar2 = (undefined4 *)FUN_004a2560(local_140,local_2c0,local_240);
          puVar6 = local_300;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar6 = puVar6 + 1;
          }
          puVar2 = (undefined4 *)FUN_004a2560(local_c0,local_300,local_340);
          puVar6 = local_280;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar6 = puVar6 + 1;
          }
          puVar2 = (undefined4 *)FUN_004a2560(local_40,local_1c0,local_280);
          puVar6 = local_200;
          for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar6 = puVar6 + 1;
          }
          FUN_004a19e0(&local_34c,puVar5,local_200);
          puVar4[-2] = local_34c;
          puVar4[-1] = local_348;
          *puVar4 = local_344;
          local_360 = local_360 + 1;
          puVar4 = puVar4 + 8;
          puVar5 = puVar5 + 0xc;
        } while (local_360 < *(int *)(param_1 + 0x11a4));
      }
      local_36c = local_36c + 0x198;
      local_368 = local_368 + 0x38;
    } while (local_36c < 0x1fe0);
  }
  return;
}

