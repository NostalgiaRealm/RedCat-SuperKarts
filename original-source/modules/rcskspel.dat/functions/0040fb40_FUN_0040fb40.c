/*
 * FUN_0040fb40 at 0040fb40
 * undefined FUN_0040fb40(void)
 * Address ranges: 0040fb40-0040fb86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040fb40(void)

{
  void *pvVar1;
  
  if (DAT_00505a20 == 0) {
    pvVar1 = operator_new(0x220);
    if (pvVar1 != (void *)0x0) {
      DAT_00505a20 = FUN_0040f480();
      FUN_0040fae0();
      return DAT_00505a20;
    }
    DAT_00505a20 = 0;
    FUN_0040fae0();
  }
  return DAT_00505a20;
}

