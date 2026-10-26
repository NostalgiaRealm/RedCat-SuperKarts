/*
 * FUN_004320d0 at 004320d0
 * undefined FUN_004320d0(void)
 * Address ranges: 004320d0-00432181
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004320d0(void)

{
  if ((DAT_00507288 == 1) || (DAT_0053bd90 == 1)) {
    if (DAT_0053be0c == 0) {
      DAT_0053be0c = 1;
      if ((DAT_0053b9f0 != 0) && (DAT_0053ba50 != 0)) {
        FUN_00423b90(DAT_004eb2c8,1);
        FUN_00423b90(DAT_004eb2cc,1);
        return;
      }
      FUN_00442ce0(1);
    }
  }
  else if (DAT_0053be0c != 0) {
    DAT_0053be0c = 0;
    if ((DAT_0053b9f0 != 0) && (DAT_0053ba50 != 0)) {
      FUN_00423b90(DAT_004eb2c8,0);
      FUN_00423b90(DAT_004eb2cc,0);
      return;
    }
    FUN_00442ce0(0);
    return;
  }
  return;
}

