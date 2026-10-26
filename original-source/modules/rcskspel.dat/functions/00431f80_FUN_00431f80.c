/*
 * FUN_00431f80 at 00431f80
 * undefined FUN_00431f80(void)
 * Address ranges: 00431f80-00432013
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00431f80(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0053bae4;
  do {
    FUN_004bfa20();
    FUN_004bfa20();
    uVar1 = __ftol();
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x53bb5d);
  return;
}

