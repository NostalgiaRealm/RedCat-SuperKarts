/*
 * FUN_004101a0 at 004101a0
 * undefined FUN_004101a0(void)
 * Address ranges: 004101a0-004101c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004101a0(void)

{
  undefined *puVar1;
  int iVar2;
  
  FUN_0040fb40();
  iVar2 = 0;
  puVar1 = &DAT_00505930;
  do {
    FUN_0040fe50(iVar2);
    puVar1 = puVar1 + 0x18;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x505a20);
  return;
}

