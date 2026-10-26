/*
 * FUN_0041f783 at 0041f783
 * undefined __cdecl FUN_0041f783(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 0041f783-0041f79c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041f783(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}

