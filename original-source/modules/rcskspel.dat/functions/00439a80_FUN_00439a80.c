/*
 * FUN_00439a80 at 00439a80
 * undefined FUN_00439a80(void)
 * Address ranges: 00439a80-00439ab7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00439a80(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_0043a140(param_3,param_1);
    param_1 = param_1 + 0x14;
    param_3 = param_3 + 0x14;
  } while (param_1 != param_2);
  return param_3;
}

