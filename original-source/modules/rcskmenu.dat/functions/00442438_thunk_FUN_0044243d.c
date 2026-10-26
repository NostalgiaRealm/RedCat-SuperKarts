/*
 * thunk_FUN_0044243d at 00442438
 * bool __register thunk_FUN_0044243d(int param_1, int param_2)
 * Address ranges: 00442438-00442439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_0044243d
 */

bool thunk_FUN_0044243d(int param_1,int param_2)

{
  for (; (param_2 != 0 && (param_1 != param_2)); param_2 = *(int *)(param_2 + 0x24)) {
  }
  return param_2 != 0;
}

