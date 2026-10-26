/*
 * FUN_00409151 at 00409151
 * undefined __stdcall FUN_00409151(void)
 * Address ranges: 00409151-00409179
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409151(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00410a4c;
  while (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 3;
    puVar2 = (undefined4 *)*puVar2;
    if (*piVar1 != 0) {
      FUN_0040650f();
    }
    FUN_0040650f();
  }
  return;
}

