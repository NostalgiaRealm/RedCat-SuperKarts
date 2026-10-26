/*
 * thunk_FUN_00423200 at 004231f0
 * undefined thunk_FUN_00423200(void)
 * Address ranges: 004231f0-004231f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00423200
 */

void thunk_FUN_00423200(void)

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

