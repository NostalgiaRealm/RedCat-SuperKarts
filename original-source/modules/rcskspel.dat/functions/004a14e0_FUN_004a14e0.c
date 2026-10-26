/*
 * FUN_004a14e0 at 004a14e0
 * undefined FUN_004a14e0(void)
 * Address ranges: 004a14e0-004a1508
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a14e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [16];
  
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

