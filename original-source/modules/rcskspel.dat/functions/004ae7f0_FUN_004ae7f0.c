/*
 * FUN_004ae7f0 at 004ae7f0
 * undefined FUN_004ae7f0(void)
 * Address ranges: 004ae7f0-004ae820
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004ae7f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x33;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  param_1[0x66] = 1;
  return;
}

