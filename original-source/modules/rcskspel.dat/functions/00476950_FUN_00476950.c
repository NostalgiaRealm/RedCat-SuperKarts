/*
 * FUN_00476950 at 00476950
 * undefined FUN_00476950(void)
 * Address ranges: 00476950-0047697d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00476950(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
    }
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  } while (param_1 != param_2);
  return param_3;
}

