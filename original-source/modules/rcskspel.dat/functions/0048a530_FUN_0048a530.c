/*
 * FUN_0048a530 at 0048a530
 * undefined FUN_0048a530(void)
 * Address ranges: 0048a530-0048a56c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048a530(undefined4 *param_1)

{
  int iVar1;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1))
  {
    do {
      FUN_0048a170();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

