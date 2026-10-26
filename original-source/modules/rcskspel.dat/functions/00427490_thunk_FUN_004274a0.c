/*
 * thunk_FUN_004274a0 at 00427490
 * undefined thunk_FUN_004274a0(void)
 * Address ranges: 00427490-00427494
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_004274a0
 */

void thunk_FUN_004274a0(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_0052d6d8;
  iVar2 = 100;
  do {
    FUN_00402950(puVar1,0x20,6,FUN_00423920);
    puVar1 = puVar1 + 0x134;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

