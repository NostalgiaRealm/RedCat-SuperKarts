/*
 * FUN_0040e6d0 at 0040e6d0
 * undefined FUN_0040e6d0(void)
 * Address ranges: 0040e6d0-0040e721
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040e6d0(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_0040b910(param_1);
  if (cVar1 != '\0') {
    FUN_0040ea50(param_1);
    return;
  }
  FUN_0040d230();
  if ((param_1 < DAT_00508610) && (-1 < param_1)) {
    (&DAT_00508215)[param_1 * 0x70] = 0;
    return;
  }
  DAT_0053bec5 = 0;
  return;
}

