/*
 * FUN_00499600 at 00499600
 * undefined FUN_00499600(void)
 * Address ranges: 00499600-00499623
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00499600(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_00680c68;
  iVar2 = 200;
  do {
    FUN_00402950(puVar1,0xc,4,FUN_00423920);
    puVar1 = puVar1 + 0x4c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

