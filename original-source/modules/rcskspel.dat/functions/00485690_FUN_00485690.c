/*
 * FUN_00485690 at 00485690
 * undefined FUN_00485690(void)
 * Address ranges: 00485690-004856d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00485690(void)

{
  void *pvVar1;
  
  if (DAT_005450c0 == 0) {
    pvVar1 = operator_new(0x1ef4);
    if (pvVar1 != (void *)0x0) {
      DAT_005450c0 = FUN_00485650();
      FUN_00485680();
      return DAT_005450c0;
    }
    DAT_005450c0 = 0;
    FUN_00485680();
  }
  return DAT_005450c0;
}

