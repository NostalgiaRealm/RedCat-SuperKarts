/*
 * FUN_0041e430 at 0041e430
 * undefined FUN_0041e430(void)
 * Address ranges: 0041e430-0041e447
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e430(int param_1,undefined4 param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x20) + 8) == 0) {
    *(undefined4 *)(param_1 + 0x28) = param_2;
    return;
  }
  FUN_00418c3c((undefined4 *)PTR_PTR_0047c6dc);
  return;
}

