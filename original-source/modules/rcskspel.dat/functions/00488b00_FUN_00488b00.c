/*
 * FUN_00488b00 at 00488b00
 * undefined FUN_00488b00(void)
 * Address ranges: 00488b00-00488b3c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00488b00(undefined4 *param_1)

{
  int iVar1;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1))
  {
    do {
      FUN_00488850();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

