/*
 * FUN_00426510 at 00426510
 * undefined FUN_00426510(void)
 * Address ranges: 00426510-00426539
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426510(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0050dfb4;
  iVar2 = 0x14;
  do {
    FUN_00402950(puVar1,0x20,200,FUN_00423920);
    puVar1 = puVar1 + 0x1910;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

