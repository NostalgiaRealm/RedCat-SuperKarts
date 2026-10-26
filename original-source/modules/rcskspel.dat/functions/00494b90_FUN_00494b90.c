/*
 * FUN_00494b90 at 00494b90
 * undefined FUN_00494b90(void)
 * Address ranges: 00494b90-00494d1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00494b90(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  unkbyte10 extraout_ST0;
  float10 fVar9;
  undefined1 local_100 [64];
  undefined4 local_c0 [16];
  undefined4 local_80 [16];
  undefined4 local_40 [16];
  
  fVar1 = *(float *)(param_1 + 0x48);
  fVar2 = *(float *)(param_1 + 0x50);
  fVar8 = SQRT((float10)fVar1 * (float10)fVar1 + (float10)fVar2 * (float10)fVar2);
  fVar1 = (float)((float10)fVar1 / fVar8);
  fpatan((float10)fVar2 / fVar8,(float10)fVar1);
  uVar3 = __ftol();
  fVar9 = (float10)fpatan((float10)fVar1,extraout_ST0);
  *(undefined4 *)(param_1 + 0x58) = uVar3;
  fVar8 = (float10)*(float *)(param_1 + 0x48);
  fVar8 = (float10)fpatan((float10)*(float *)(param_1 + 0x4c),
                          SQRT((float10)*(float *)(param_1 + 0x50) *
                               (float10)*(float *)(param_1 + 0x50) + fVar8 * fVar8));
  uVar3 = __ftol();
  *(undefined4 *)(param_1 + 0x54) = uVar3;
  puVar4 = (undefined4 *)FUN_004a2140(local_100,-(float)fVar9);
  puVar6 = local_c0;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2140(local_100,(float)fVar9);
  puVar6 = local_80;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a20e0(local_100,(float)fVar8);
  puVar6 = (undefined4 *)(param_1 + 0x9c);
  puVar7 = local_40;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar4 = &DAT_006a5c90;
  puVar7 = puVar6;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2560(local_100,puVar6,local_c0);
  puVar7 = puVar6;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2560(local_100,puVar6,local_40);
  puVar7 = puVar6;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar4 = (undefined4 *)FUN_004a2560(local_100,puVar6,local_80);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}

