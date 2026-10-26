/*
 * FUN_0047df70 at 0047df70
 * undefined FUN_0047df70(void)
 * Address ranges: 0047df70-0047df9b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047df70(void)

{
  void *pvVar1;
  
  if (DAT_0054500c == 0) {
    pvVar1 = operator_new(1);
    if (pvVar1 != (void *)0x0) {
      DAT_0054500c = FUN_0047df60();
      return;
    }
    DAT_0054500c = 0;
  }
  return;
}

