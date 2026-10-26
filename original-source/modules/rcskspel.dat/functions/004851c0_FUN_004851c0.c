/*
 * FUN_004851c0 at 004851c0
 * undefined FUN_004851c0(void)
 * Address ranges: 004851c0-00485444
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004851c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_358;
  int local_354;
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
  
  puVar4 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x134) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 +
           0x10);
  puVar2 = local_1c0;
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
  puVar2 = local_300;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar4 = &DAT_006a5c90;
  puVar2 = local_2c0;
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
  puVar2 = local_340;
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
  FUN_0048f4e0();
  iVar3 = *(int *)(param_1 + 0x168);
  iVar1 = iVar3 + -0xf;
  *(int *)(param_1 + 0x168) = iVar1;
  if (iVar1 < 0) {
    *(int *)(param_1 + 0x168) = iVar3 + 0xff1;
  }
  local_354 = 0;
  *(float *)(param_1 + 0x16c) = *(float *)(param_1 + 0x16c) + 15.0;
  if (0 < *(int *)(param_1 + 0x154)) {
    local_358 = param_1 + 0x100;
    puVar4 = (undefined4 *)(param_1 + 8);
    do {
      puVar2 = (undefined4 *)
               FUN_004a2510(local_80,*(undefined4 *)(param_1 + 0x16c),0x3f800000,
                            *(undefined4 *)(param_1 + 0x16c));
      puVar5 = local_240;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2270(local_100,*(undefined4 *)(param_1 + 0x168));
      puVar5 = local_280;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a24c0(local_180,param_1 + 0x13c);
      puVar5 = local_2c0;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2560(local_140,local_2c0,local_280);
      puVar5 = local_300;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2560(local_c0,local_300,local_240);
      puVar5 = local_340;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2560(local_40,local_1c0,local_340);
      puVar5 = local_200;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_004a19e0(&local_34c,local_358,local_200);
      puVar4[-2] = local_34c;
      puVar4[-1] = local_348;
      *puVar4 = local_344;
      local_354 = local_354 + 1;
      local_358 = local_358 + 0xc;
      puVar4 = puVar4 + 8;
    } while (local_354 < *(int *)(param_1 + 0x154));
  }
  if (350.0 <= *(float *)(param_1 + 0x16c)) {
    *(undefined1 *)(param_1 + 0x138) = 0;
  }
  return;
}

