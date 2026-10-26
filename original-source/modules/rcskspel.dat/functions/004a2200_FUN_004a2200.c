/*
 * FUN_004a2200 at 004a2200
 * undefined FUN_004a2200(void)
 * Address ranges: 004a2200-004a2269
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2200(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40 [5];
  undefined4 local_2c;
  float local_28;
  float local_1c;
  undefined4 local_18;
  
  iVar3 = (DAT_004fc8f8 & param_2) * 4;
  uVar1 = *(undefined4 *)(iVar3 + DAT_006a5cd0);
  fVar2 = *(float *)(iVar3 + DAT_006a5c88);
  puVar4 = &DAT_006a5c90;
  puVar5 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_2c = uVar1;
  local_18 = uVar1;
  local_1c = fVar2;
  local_28 = -fVar2;
  puVar4 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

