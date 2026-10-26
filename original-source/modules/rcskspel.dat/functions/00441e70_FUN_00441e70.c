/*
 * FUN_00441e70 at 00441e70
 * undefined FUN_00441e70(void)
 * Address ranges: 00441e70-00441f04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441e70(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0042abc0();
  if ((((iVar1 == 1) && (DAT_0053b9c0 != 6)) && (DAT_0053b9c0 != 3)) &&
     ((param_1 == DAT_0053be28 && (DAT_0053d208 < DAT_0053be70)))) {
    if (DAT_0053d204 == DAT_0053d338) {
      DAT_0053d204 = 1;
    }
    else {
      DAT_0053d204 = DAT_0053d204 + 1;
    }
    DAT_0053d208 = DAT_0053be70 + 1;
    iVar1 = FUN_0042a4d0(0x12);
    FUN_0042a5d0(0x12,(&DAT_0053d2b0)[DAT_0053d204] + iVar1);
    FUN_0043b600(s_CHECKPOINT_004ed1ac,0);
  }
  return;
}

