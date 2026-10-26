/*
 * thunk_FUN_00402300 at 004022f0
 * undefined thunk_FUN_00402300(void)
 * Address ranges: 004022f0-004022f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00402300
 */

void thunk_FUN_00402300(void)

{
  int iVar1;
  
  iVar1 = 0xf;
  do {
    FUN_0040c790();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

