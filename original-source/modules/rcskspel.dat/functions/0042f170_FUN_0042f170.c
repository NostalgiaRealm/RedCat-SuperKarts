/*
 * FUN_0042f170 at 0042f170
 * undefined FUN_0042f170(void)
 * Address ranges: 0042f170-0042f1ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f170(void)

{
  int iVar1;
  
  iVar1 = FUN_0042abc0();
  if ((iVar1 == 1) && (DAT_0053b9c0 == 0)) {
    iVar1 = FUN_0042a700(0x12);
    if (iVar1 != 0) {
      DAT_004e3b10 = 1;
      FUN_0042f740(6);
      return;
    }
    iVar1 = FUN_0042a4d0(0x12);
    iVar1 = iVar1 / 1000;
    if ((iVar1 < 6) && (iVar1 != DAT_0053baa8)) {
      DAT_0053baa8 = iVar1;
      FUN_0043b600(s_TIME_TICK_004ead78,0);
    }
  }
  return;
}

