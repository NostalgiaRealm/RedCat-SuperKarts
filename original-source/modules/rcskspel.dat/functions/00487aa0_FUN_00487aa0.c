/*
 * FUN_00487aa0 at 00487aa0
 * undefined FUN_00487aa0(void)
 * Address ranges: 00487aa0-00487ae5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00487aa0(undefined4 *param_1)

{
  int iVar1;
  
  if ((((DAT_0053ba78 != 0) && (DAT_0053ba60 != 0)) && (DAT_0053b9b0 == 0)) &&
     (iVar1 = (**(code **)*param_1)(), 0 < iVar1)) {
    do {
      FUN_00487780();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

