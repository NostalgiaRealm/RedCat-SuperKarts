/*
 * FUN_00466330 at 00466330
 * undefined FUN_00466330(void)
 * Address ranges: 00466330-0046635d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_00466330(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_004662b0(param_2);
  param_1[0xb] = 0;
  *param_1 = &PTR_FUN_004d2c94;
  puVar2 = param_1 + 2;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

