/*
 * thunk_FUN_00407600 at 004075f0
 * undefined thunk_FUN_00407600(void)
 * Address ranges: 004075f0-004075f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00407600
 */

void thunk_FUN_00407600(void)

{
  int iVar1;
  
  iVar1 = 0xf;
  do {
    FUN_00402380();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

