/*
 * thunk_FUN_00404f1c at 00404f14
 * undefined __register thunk_FUN_00404f1c(LPCSTR param_1)
 * Address ranges: 00404f14-00404f15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00404f1c
 */

void thunk_FUN_00404f1c(LPCSTR param_1)

{
  for (; (*param_1 != '\0' && (*param_1 != '\\')); param_1 = CharNextA(param_1)) {
  }
  return;
}

