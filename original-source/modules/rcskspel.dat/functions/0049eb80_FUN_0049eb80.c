/*
 * FUN_0049eb80 at 0049eb80
 * undefined FUN_0049eb80(void)
 * Address ranges: 0049eb80-0049ebd3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0049eb80(int param_1,byte param_2)

{
  if ((param_2 & 2) != 0) {
    FUN_004be99e(param_1,0x38,*(undefined4 *)(param_1 + -4),FUN_0049f1a0);
    if ((param_2 & 1) != 0) {
      FUN_004bc150(param_1 + -4);
    }
    return param_1 + -4;
  }
  FUN_0049f1a0();
  if ((param_2 & 1) != 0) {
    FUN_004bc150(param_1);
  }
  return param_1;
}

