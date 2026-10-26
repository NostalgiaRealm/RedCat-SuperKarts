/*
 * thunk_FUN_00402360 at 00402350
 * undefined thunk_FUN_00402360(void)
 * Address ranges: 00402350-00402354
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00402360
 */

void thunk_FUN_00402360(void)

{
  int iVar1;
  
  iVar1 = 0x23;
  do {
    FUN_00402380();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

