/*
 * FUN_004863e0 at 004863e0
 * undefined FUN_004863e0(void)
 * Address ranges: 004863e0-0048641c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004863e0(undefined4 *param_1)

{
  int iVar1;
  
  if (((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1))
  {
    do {
      FUN_00486100();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

