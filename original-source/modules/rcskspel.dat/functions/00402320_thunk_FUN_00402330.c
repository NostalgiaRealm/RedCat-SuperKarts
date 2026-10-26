/*
 * thunk_FUN_00402330 at 00402320
 * undefined thunk_FUN_00402330(void)
 * Address ranges: 00402320-00402324
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00402330
 */

void thunk_FUN_00402330(void)

{
  int iVar1;
  
  iVar1 = 0x23;
  do {
    FUN_00402380();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

