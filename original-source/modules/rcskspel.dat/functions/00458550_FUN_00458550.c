/*
 * FUN_00458550 at 00458550
 * undefined FUN_00458550(void)
 * Address ranges: 00458550-0045856e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00458550(undefined4 *param_1,undefined4 param_2)

{
  if ((code *)param_1[0xc] != (code *)0x0) {
    (*(code *)param_1[0xc])(param_1);
  }
  (**(code **)*param_1)(param_2);
  return;
}

