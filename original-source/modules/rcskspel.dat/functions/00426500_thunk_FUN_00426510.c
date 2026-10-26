/*
 * thunk_FUN_00426510 at 00426500
 * undefined thunk_FUN_00426510(void)
 * Address ranges: 00426500-00426504
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00426510
 */

void thunk_FUN_00426510(void)

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

