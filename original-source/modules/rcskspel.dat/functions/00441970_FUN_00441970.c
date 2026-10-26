/*
 * FUN_00441970 at 00441970
 * undefined FUN_00441970(void)
 * Address ranges: 00441970-00441998
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441970(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &DAT_004ecd80;
  do {
    FUN_00493290(iVar2,*puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x4ecee4);
  FUN_00440ef0();
  return;
}

