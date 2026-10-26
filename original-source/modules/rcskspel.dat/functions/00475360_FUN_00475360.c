/*
 * FUN_00475360 at 00475360
 * undefined FUN_00475360(void)
 * Address ranges: 00475360-0047538b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475360(void)

{
  void *pvVar1;
  
  if (DAT_00544df0 == 0) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 != (void *)0x0) {
      DAT_00544df0 = FUN_004751d0();
      return;
    }
    DAT_00544df0 = 0;
  }
  return;
}

