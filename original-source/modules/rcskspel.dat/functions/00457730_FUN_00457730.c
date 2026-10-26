/*
 * FUN_00457730 at 00457730
 * undefined FUN_00457730(void)
 * Address ranges: 00457730-00457776
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00457730(void)

{
  void *pvVar1;
  
  if (DAT_00544a8c == 0) {
    pvVar1 = operator_new(0xa4);
    if (pvVar1 != (void *)0x0) {
      DAT_00544a8c = FUN_00457630();
      FUN_00457d10();
      return DAT_00544a8c;
    }
    DAT_00544a8c = 0;
    FUN_00457d10();
  }
  return DAT_00544a8c;
}

