/*
 * FUN_00423200 at 00423200
 * undefined FUN_00423200(void)
 * Address ranges: 00423200-00423226
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423200(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_005091a0;
  iVar2 = 10;
  do {
    FUN_00402950(puVar1,0x20,0x22,FUN_00423920);
    puVar1 = puVar1 + 0x110;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

