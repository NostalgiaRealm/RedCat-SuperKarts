/*
 * FUN_00435320 at 00435320
 * undefined FUN_00435320(void)
 * Address ranges: 00435320-00435346
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00435320(void)

{
  DWORD DVar1;
  
  if (DAT_0053bef8 != 0) {
    DVar1 = GetTickCount();
    if (9999 < (int)(DVar1 - DAT_0053bee0)) {
      DAT_0053bee0 = DVar1;
    }
  }
  return;
}

