/*
 * FUN_0041e770 at 0041e770
 * undefined __stdcall FUN_0041e770(void)
 * Address ranges: 0041e770-0041e786
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e770(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0043e214;
  do {
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x43e2b4);
  return;
}

