/*
 * FUN_0043df30 at 0043df30
 * undefined FUN_0043df30(void)
 * Address ranges: 0043df30-0043df5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043df30(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_004ec41c;
  do {
    FUN_004931c0(puVar1[-1],*puVar1,puVar1[1]);
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0x4ec65c);
  FUN_00440960();
  FUN_004405e0();
  return;
}

