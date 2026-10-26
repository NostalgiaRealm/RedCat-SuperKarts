/*
 * FUN_004a2510 at 004a2510
 * undefined FUN_004a2510(void)
 * Address ranges: 004a2510-004a2553
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a2510(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [5];
  undefined4 local_2c;
  undefined4 local_18;
  
  puVar2 = &DAT_006a5c90;
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_40[0] = param_2;
  local_2c = param_3;
  local_18 = param_4;
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

