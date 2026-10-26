/*
 * FUN_004893a0 at 004893a0
 * undefined FUN_004893a0(void)
 * Address ranges: 004893a0-004893c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004893a0(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_00545114;
  iVar2 = 0x14;
  do {
    FUN_00402950(puVar1,0x20,2000,FUN_00423920);
    puVar1 = puVar1 + 0xfa10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

