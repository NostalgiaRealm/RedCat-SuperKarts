/*
 * thunk_FUN_004385f4 at 004385f0
 * undefined4 __register thunk_FUN_004385f4(int param_1)
 * Address ranges: 004385f0-004385f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_004385f4
 */

undefined4 thunk_FUN_004385f4(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = param_1;
    param_1 = *(int *)(iVar1 + 0x58);
  } while (param_1 != 0);
  return *(undefined4 *)(iVar1 + 100);
}

