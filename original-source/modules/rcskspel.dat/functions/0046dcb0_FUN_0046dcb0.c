/*
 * FUN_0046dcb0 at 0046dcb0
 * undefined FUN_0046dcb0(void)
 * Address ranges: 0046dcb0-0046dcdd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_0046dcb0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_004662b0(param_2);
  param_1[2] = 0;
  *param_1 = &PTR_FUN_004d2dbc;
  puVar2 = param_1 + 3;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

