/*
 * FUN_0044b7d0 at 0044b7d0
 * undefined FUN_0044b7d0(void)
 * Address ranges: 0044b7d0-0044b807
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0044b7d0(int param_1,int param_2,int param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    FUN_0044c520(param_3,param_1);
    param_1 = param_1 + 0x60;
    param_3 = param_3 + 0x60;
  } while (param_1 != param_2);
  return param_3;
}

