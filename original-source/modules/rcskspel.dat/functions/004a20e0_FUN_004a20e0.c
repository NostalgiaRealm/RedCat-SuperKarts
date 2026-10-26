/*
 * FUN_004a20e0 at 004a20e0
 * undefined FUN_004a20e0(void)
 * Address ranges: 004a20e0-004a2135
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a20e0(undefined4 *param_1,float param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 local_40 [5];
  float local_2c;
  float local_28;
  float local_1c;
  float local_18;
  
  fVar4 = (float10)fcos((float10)param_2);
  puVar2 = &DAT_006a5c90;
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = 0x10;
  fVar5 = (float10)fsin((float10)param_2);
  local_2c = (float)fVar4;
  local_18 = (float)fVar4;
  local_1c = (float)fVar5;
  local_28 = -(float)fVar5;
  puVar2 = local_40;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

