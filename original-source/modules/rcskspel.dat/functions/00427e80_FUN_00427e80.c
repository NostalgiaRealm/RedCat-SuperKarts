/*
 * FUN_00427e80 at 00427e80
 * undefined FUN_00427e80(void)
 * Address ranges: 00427e80-00427ea6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00427e80(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_00535060;
  iVar2 = 0x46;
  do {
    FUN_00402950(puVar1,0x20,6,FUN_00423920);
    puVar1 = puVar1 + 300;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

