/*
 * FUN_004885c0 at 004885c0
 * undefined FUN_004885c0(void)
 * Address ranges: 004885c0-0048884a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004885c0(int param_1,float param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
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
  
  param_2 = param_2 + *(float *)(param_1 + 0x168);
  puVar5 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x138) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 +
           0x10);
  puVar2 = local_1c0;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_0048f4e0();
  if (*(char *)(param_1 + 0x151) == '\0') {
    iVar3 = *(int *)(param_1 + 0x164);
    iVar4 = iVar3 + -0xf;
    *(int *)(param_1 + 0x164) = iVar4;
    if (-1 < iVar4) goto LAB_0048866a;
    iVar3 = iVar3 + 0xff1;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x164);
    iVar4 = iVar3 + 0xf;
    *(int *)(param_1 + 0x164) = iVar4;
    if (iVar4 < 0x1001) goto LAB_0048866a;
    iVar3 = iVar3 + -0xff1;
  }
  *(int *)(param_1 + 0x164) = iVar3;
LAB_0048866a:
  iVar3 = *(int *)(param_1 + 0x154);
  puVar5 = &DAT_006a5c90;
  puVar2 = local_280;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  local_354 = 0;
  puVar5 = &DAT_006a5c90;
  puVar2 = local_300;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar5 = &DAT_006a5c90;
  puVar2 = local_2c0;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar5 = &DAT_006a5c90;
  puVar2 = local_200;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar5 = &DAT_006a5c90;
  puVar2 = local_340;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar5 = &DAT_006a5c90;
  puVar2 = local_240;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  if (0 < iVar3) {
    local_358 = param_1 + 0xe0;
    puVar5 = (undefined4 *)(param_1 + 8);
    do {
      puVar2 = (undefined4 *)FUN_004a2510(local_80,param_2,param_2,0x3f800000);
      uVar1 = *(undefined4 *)(param_1 + 0x164);
      puVar6 = local_240;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a22e0(local_100,uVar1);
      puVar6 = local_280;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a24c0(local_180,param_1 + 0x140);
      puVar6 = local_2c0;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2560(local_140,local_2c0,local_280);
      puVar6 = local_300;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2560(local_c0,local_300,local_240);
      puVar6 = local_340;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = (undefined4 *)FUN_004a2560(local_40,local_1c0,local_340);
      puVar6 = local_200;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      FUN_004a19e0(&local_34c,local_358,local_200);
      puVar5[-2] = local_34c;
      puVar5[-1] = local_348;
      local_354 = local_354 + 1;
      *puVar5 = local_344;
      local_358 = local_358 + 0xc;
      puVar5 = puVar5 + 8;
    } while (local_354 < *(int *)(param_1 + 0x154));
  }
  return;
}

