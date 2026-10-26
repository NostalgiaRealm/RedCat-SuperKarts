/*
 * FUN_004422e0 at 004422e0
 * undefined FUN_004422e0(void)
 * Address ranges: 004422e0-00442336
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004422e0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_00415be0(param_1);
  if (cVar1 == '\0') {
    DAT_0053d210 = DAT_0053d210 + -1;
  }
  else {
    DAT_0053d210 = DAT_0053d210 + 1;
  }
  if (DAT_0053d210 == DAT_005450b0) {
    DAT_0053d210 = 0;
  }
  else if (DAT_0053d210 < 0) {
    DAT_0053d210 = DAT_005450b0 + -1;
  }
  if (DAT_005450ac != 0) {
    FUN_00481d80((float)*(int *)(DAT_005450ac + DAT_0053d210 * 4) * 0.01);
  }
  return;
}

