/*
 * FUN_004039c8 at 004039c8
 * bool __register FUN_004039c8(void)
 * Address ranges: 004039c8-004039fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004039c8(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = DAT_0047d4a4;
  puVar4 = &DAT_0047d4a4;
  for (iVar2 = 0xb; iVar1 = DAT_0047d038, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  LOCK();
  DAT_0047d038 = 0;
  UNLOCK();
  return (bool)('\x01' - (iVar1 != 0));
}

