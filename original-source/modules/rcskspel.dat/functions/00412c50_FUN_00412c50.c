/*
 * FUN_00412c50 at 00412c50
 * undefined FUN_00412c50(void)
 * Address ranges: 00412c50-00412c9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412c50(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_00505b48 = DAT_00505b48 + -1;
    if (DAT_00505b48 < 0) {
      DAT_00505b48 = 0;
    }
  }
  else {
    DAT_00505b48 = DAT_00505b48 + 1;
  }
  FUN_00412bf0(param_1,param_2);
  DAT_00505b40 = (uint)(DAT_00505b48 != 0);
  return;
}

