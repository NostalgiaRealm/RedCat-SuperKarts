/*
 * FUN_004a24c0 at 004a24c0
 * undefined FUN_004a24c0(void)
 * Address ranges: 004a24c0-004a2503
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a24c0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = param_2[1];
  puVar3 = &DAT_006a5c90;
  puVar4 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_8 = param_2[2];
  local_10 = *param_2;
  local_c = uVar1;
  puVar3 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

