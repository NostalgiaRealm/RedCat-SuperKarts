/*
 * FUN_00488b40 at 00488b40
 * undefined FUN_00488b40(void)
 * Address ranges: 00488b40-00488b7c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00488b40(undefined4 *param_1)

{
  int iVar1;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1))
  {
    do {
      FUN_004888b0();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

