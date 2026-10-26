/*
 * FUN_004897e0 at 004897e0
 * undefined FUN_004897e0(void)
 * Address ranges: 004897e0-00489c61
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004897e0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined1 local_1a0 [64];
  undefined1 local_160 [32];
  undefined4 local_140 [16];
  undefined4 local_100 [16];
  undefined4 local_c0 [16];
  undefined4 local_80 [16];
  undefined4 local_40 [16];
  
  cVar1 = *(char *)(param_1 + 0x100);
  puVar4 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0xe8) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 +
           0x10);
  puVar6 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  if (cVar1 == '\0') {
    puVar4 = (undefined4 *)
             FUN_004a2470(local_1a0,*(undefined4 *)(param_1 + 0xf0),*(undefined4 *)(param_1 + 0xf4),
                          *(undefined4 *)(param_1 + 0xf8));
    puVar6 = local_140;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar4 = (undefined4 *)FUN_004a2560(local_1a0,local_40,local_140);
    puVar6 = local_100;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    local_1c4 = 10.0;
    local_1c0 = 0.0;
    local_1bc = 0.0;
    FUN_004a19e0(&local_1b8,&local_1c4,local_100);
    FUN_0048b370(*(undefined4 *)(*(int *)(param_1 + 4) + 4),1,local_160);
    **(undefined4 **)(*(int *)(param_1 + 4) + 4) = local_1b8;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4) = local_1b4;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 8) = local_1b0;
    local_1c4 = -10.0;
    local_1c0 = 0.0;
    local_1bc = 0.0;
    FUN_004a19e0(&local_1b8,&local_1c4,local_100);
    FUN_0048b370(*(undefined4 *)(*(int *)(param_1 + 4) + 4),1,local_160);
    **(undefined4 **)(*(int *)(param_1 + 4) + 4) = local_1b8;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4) = local_1b4;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 8) = local_1b0;
    return;
  }
  fVar7 = (float10)FUN_0048f4e0();
  fVar7 = ((float10)60.0 / ((float10)1.0 / fVar7)) * (float10)100.0 +
          (float10)*(float *)(param_1 + 0x10c);
  *(float *)(param_1 + 0x10c) = (float)fVar7;
  if ((float10)4096.0 < fVar7) {
    *(float *)(param_1 + 0x10c) = (float)(fVar7 - (float10)4096.0);
  }
  puVar4 = &DAT_006a5c90;
  puVar6 = local_c0;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar3 = __ftol();
  puVar4 = (undefined4 *)FUN_004a22e0(local_1a0,uVar3);
  uVar3 = *(undefined4 *)(param_1 + 0xf8);
  uVar2 = *(undefined4 *)(param_1 + 0xf4);
  puVar6 = local_c0;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2470(local_1a0,*(undefined4 *)(param_1 + 0xf0),uVar2,uVar3);
  puVar6 = local_100;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2560(local_1a0,local_100,local_c0);
  puVar6 = local_80;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2560(local_1a0,local_40,local_80);
  local_1c4 = *(float *)(param_1 + 0x104) * 0.5;
  puVar6 = local_140;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  local_1c0 = 0.0;
  local_1bc = 0.0;
  FUN_004a19e0(&local_1b8,&local_1c4,local_140);
  FUN_0048b000(*(undefined4 *)(*(int *)(param_1 + 4) + 4),local_160);
  **(undefined4 **)(*(int *)(param_1 + 4) + 4) = local_1b8;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4) = local_1b4;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 8) = local_1b0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_1c4 = -(*(float *)(param_1 + 0x104) * 0.5) + *(float *)(param_1 + 0xf0);
  local_1c0 = *(float *)(param_1 + 0xf4) + 0.0;
  local_1bc = *(float *)(param_1 + 0xf8) + 0.0;
  puVar4 = (undefined4 *)FUN_004a2560(local_1a0,local_100,local_c0);
  puVar6 = local_80;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2560(local_1a0,local_40,local_80);
  puVar6 = local_140;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  local_1c4 = -10.0;
  local_1c0 = 0.0;
  local_1bc = 0.0;
  FUN_004a19e0(&local_1b8,&local_1c4,local_140);
  FUN_0048b370(*(undefined4 *)(*(int *)(param_1 + 4) + 4),1,local_160);
  **(undefined4 **)(*(int *)(param_1 + 4) + 4) = local_1b8;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4) = local_1b4;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 8) = local_1b0;
  return;
}

