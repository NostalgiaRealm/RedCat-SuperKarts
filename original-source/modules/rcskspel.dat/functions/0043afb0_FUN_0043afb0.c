/*
 * FUN_0043afb0 at 0043afb0
 * undefined FUN_0043afb0(void)
 * Address ranges: 0043afb0-0043afd5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_0043afb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  } while (param_1 != param_2);
  return param_3;
}

