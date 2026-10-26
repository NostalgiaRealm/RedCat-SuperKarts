/*
 * FUN_00485c10 at 00485c10
 * undefined FUN_00485c10(void)
 * Address ranges: 00485c10-004860f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00485c10(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_364;
  int local_360;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  float local_344;
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
  
  local_364 = 0;
  iVar5 = *(int *)(param_1 + 0x244);
  puVar6 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x230) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 +
           0x10);
  puVar3 = local_1c0;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar3 = puVar3 + 1;
  }
  if (0 < iVar5) {
    local_360 = param_1 + 0x200;
    puVar6 = (undefined4 *)(param_1 + 8);
    do {
      puVar3 = (undefined4 *)
               FUN_004a2510(local_80,*(undefined4 *)(param_1 + 0x25c),
                            *(undefined4 *)(param_1 + 0x25c),0x3f800000);
      puVar7 = local_240;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a22e0(local_100,*(undefined4 *)(param_1 + 0x254));
      puVar7 = local_300;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a24c0(local_180,param_1 + 0x238);
      puVar7 = local_2c0;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_140,local_2c0,local_300);
      puVar7 = local_340;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_c0,local_340,local_240);
      puVar7 = local_280;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_40,local_1c0,local_280);
      puVar7 = local_200;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_004a19e0(&local_358,local_360,local_200);
      puVar6[-2] = local_358;
      puVar6[-1] = local_354;
      *puVar6 = local_350;
      local_364 = local_364 + 1;
      local_360 = local_360 + 0xc;
      puVar6 = puVar6 + 8;
    } while (local_364 < *(int *)(param_1 + 0x244));
  }
  local_364 = 0;
  local_34c = *(undefined4 *)(param_1 + 0x238);
  local_348 = *(undefined4 *)(param_1 + 0x23c);
  local_344 = *(float *)(param_1 + 0x240) - 3.0;
  if (0 < *(int *)(param_1 + 0x244)) {
    local_360 = param_1 + 0x200;
    puVar6 = (undefined4 *)(param_1 + 0x84);
    do {
      fVar2 = *(float *)(param_1 + 0x25c) * 1.5;
      puVar3 = (undefined4 *)FUN_004a2510(local_40,fVar2,fVar2,0x3f800000);
      uVar1 = *(undefined4 *)(param_1 + 0x254);
      puVar7 = local_240;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a22e0(local_c0,uVar1);
      puVar7 = local_300;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a24c0(local_140,&local_34c);
      puVar7 = local_2c0;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_180,local_2c0,local_300);
      puVar7 = local_340;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_100,local_340,local_240);
      puVar7 = local_280;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_80,local_1c0,local_280);
      puVar7 = local_200;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_004a19e0(&local_358,local_360,local_200);
      puVar6[-1] = local_358;
      *puVar6 = local_354;
      puVar6[1] = local_350;
      local_364 = local_364 + 1;
      local_360 = local_360 + 0xc;
      puVar6 = puVar6 + 8;
    } while (local_364 < *(int *)(param_1 + 0x244));
  }
  local_344 = local_344 - 4.0;
  local_364 = 0;
  if (0 < *(int *)(param_1 + 0x244)) {
    local_360 = param_1 + 0x200;
    puVar6 = (undefined4 *)(param_1 + 0x104);
    do {
      fVar2 = *(float *)(param_1 + 0x25c) + *(float *)(param_1 + 0x25c);
      puVar3 = (undefined4 *)FUN_004a2510(local_40,fVar2,fVar2,0x3f800000);
      uVar1 = *(undefined4 *)(param_1 + 0x254);
      puVar7 = local_240;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a22e0(local_c0,uVar1);
      puVar7 = local_300;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a24c0(local_140,&local_34c);
      puVar7 = local_2c0;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_180,local_2c0,local_300);
      puVar7 = local_340;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_100,local_340,local_240);
      puVar7 = local_280;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (undefined4 *)FUN_004a2560(local_80,local_1c0,local_280);
      puVar7 = local_200;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_004a19e0(&local_358,local_360,local_200);
      puVar6[-1] = local_358;
      *puVar6 = local_354;
      puVar6[1] = local_350;
      local_364 = local_364 + 1;
      local_360 = local_360 + 0xc;
      puVar6 = puVar6 + 8;
    } while (local_364 < *(int *)(param_1 + 0x244));
  }
  return;
}

