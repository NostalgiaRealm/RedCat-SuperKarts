/*
 * FUN_00411220 at 00411220
 * undefined FUN_00411220(void)
 * Address ranges: 00411220-00411247
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00411220(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00505a34;
  do {
    puVar1[-1] = 0xffffffff;
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1 = puVar1 + 6;
  } while ((int)puVar1 < 0x505af4);
  return 1;
}

