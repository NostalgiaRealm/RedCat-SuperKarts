/*
 * FUN_0048a4f0 at 0048a4f0
 * undefined FUN_0048a4f0(void)
 * Address ranges: 0048a4f0-0048a52c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048a4f0(undefined4 *param_1)

{
  int iVar1;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1))
  {
    do {
      FUN_00489d20();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

