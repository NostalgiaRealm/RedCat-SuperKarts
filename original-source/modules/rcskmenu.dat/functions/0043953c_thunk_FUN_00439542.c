/*
 * thunk_FUN_00439542 at 0043953c
 * undefined __register thunk_FUN_00439542(int param_1, int param_2)
 * Address ranges: 0043953c-0043953d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00439542
 */

void thunk_FUN_00439542(int param_1,int param_2)

{
  for (; (0 < param_2 && (param_1 != 0)); param_1 = *(int *)(param_1 + 0x58)) {
    param_2 = param_2 + -1;
  }
  return;
}

