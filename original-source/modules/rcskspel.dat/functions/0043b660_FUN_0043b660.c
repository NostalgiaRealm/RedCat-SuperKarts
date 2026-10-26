/*
 * FUN_0043b660 at 0043b660
 * undefined FUN_0043b660(void)
 * Address ranges: 0043b660-0043b75d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043b660(void)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float local_4c [3];
  undefined4 local_40 [8];
  float local_20;
  float local_1c;
  float local_18;
  
  puVar5 = (undefined4 *)(DAT_00680ba0 + 0x14 + (&DAT_00508620)[DAT_00508670] * 0x178);
  puVar6 = local_40;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  local_20 = -local_20;
  local_1c = -local_1c;
  local_18 = -local_18;
  iVar4 = DAT_0067ee20 + DAT_0053be28 * 0xd0;
  fVar1 = *(float *)(iVar4 + 0x9c);
  fVar2 = *(float *)(iVar4 + 0xa4);
  uVar3 = __ftol();
  iVar4 = (DAT_004fc8f8 & uVar3) * 4;
  local_4c[0] = *(float *)(iVar4 + DAT_006a5cd0) * fVar1 - *(float *)(iVar4 + DAT_006a5c88) * fVar2;
  local_4c[2] = *(float *)(iVar4 + DAT_006a5cd0) * fVar2 + *(float *)(iVar4 + DAT_006a5c88) * fVar1;
  local_4c[1] = 0.0;
  FUN_0049ea30(local_40,local_4c);
  return;
}

