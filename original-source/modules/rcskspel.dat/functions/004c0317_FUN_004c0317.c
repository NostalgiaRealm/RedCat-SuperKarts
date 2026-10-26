/*
 * FUN_004c0317 at 004c0317
 * undefined FUN_004c0317(void)
 * Address ranges: 004c0317-004c0330
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c0317(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}

