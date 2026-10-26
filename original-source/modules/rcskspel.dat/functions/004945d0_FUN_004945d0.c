/*
 * FUN_004945d0 at 004945d0
 * undefined FUN_004945d0(void)
 * Address ranges: 004945d0-0049460a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004945d0(int param_1,byte param_2)

{
  if ((param_2 & 2) == 0) {
    if ((param_2 & 1) != 0) {
      FUN_004bc150(param_1);
    }
  }
  else {
    param_1 = param_1 + -4;
    if ((param_2 & 1) != 0) {
      FUN_004bc150(param_1);
      return param_1;
    }
  }
  return param_1;
}

