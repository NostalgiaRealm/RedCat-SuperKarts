/*
 * FUN_0046a340 at 0046a340
 * undefined FUN_0046a340(void)
 * Address ranges: 0046a340-0046a37d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_0046a340(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_004662b0(param_2);
  iVar2 = 5;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 5;
  *param_1 = &PTR_FUN_004d2d30;
  puVar1 = param_1 + 2;
  do {
    puVar1[5] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return param_1;
}

