/*
 * FUN_004165d0 at 004165d0
 * undefined FUN_004165d0(void)
 * Address ranges: 004165d0-004165e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004165d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00507390;
  do {
    puVar1[-2] = 0;
    *puVar1 = 0;
    puVar1[-1] = 0;
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0x507f48);
  return;
}

