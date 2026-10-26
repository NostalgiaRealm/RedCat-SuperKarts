/*
 * FUN_0048db00 at 0048db00
 * undefined FUN_0048db00(void)
 * Address ranges: 0048db00-0048db2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048db00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  if (0 < iVar1) {
    do {
      FUN_0048ca60();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

