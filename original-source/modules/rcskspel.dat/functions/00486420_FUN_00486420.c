/*
 * FUN_00486420 at 00486420
 * undefined FUN_00486420(void)
 * Address ranges: 00486420-0048645c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00486420(undefined4 *param_1)

{
  int iVar1;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1))
  {
    do {
      FUN_00486130();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

