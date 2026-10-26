/*
 * FUN_00431750 at 00431750
 * undefined FUN_00431750(void)
 * Address ranges: 00431750-0043177b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431750(void)

{
  void *pvVar1;
  
  if (DAT_0053babc == 0) {
    pvVar1 = operator_new(0x5c);
    if (pvVar1 != (void *)0x0) {
      DAT_0053babc = FUN_004316c0();
      return;
    }
    DAT_0053babc = 0;
  }
  return;
}

