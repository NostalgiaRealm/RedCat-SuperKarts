/*
 * FUN_00401ae8 at 00401ae8
 * undefined __cdecl FUN_00401ae8(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 00401ae8-00401b01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00401ae8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}

