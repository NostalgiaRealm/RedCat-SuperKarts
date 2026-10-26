/*
 * FUN_004421e0 at 004421e0
 * undefined FUN_004421e0(void)
 * Address ranges: 004421e0-00442236
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004421e0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_00415be0(param_1);
  if (cVar1 == '\0') {
    DAT_0053d20c = DAT_0053d20c + -1;
  }
  else {
    DAT_0053d20c = DAT_0053d20c + 1;
  }
  if (DAT_0053d20c == DAT_005450b8) {
    DAT_0053d20c = 0;
  }
  else if (DAT_0053d20c < 0) {
    DAT_0053d20c = DAT_005450b8 + -1;
  }
  if (DAT_005450b4 != 0) {
    FUN_00481e10((float)*(int *)(DAT_005450b4 + DAT_0053d20c * 4) * 0.01);
  }
  return;
}

