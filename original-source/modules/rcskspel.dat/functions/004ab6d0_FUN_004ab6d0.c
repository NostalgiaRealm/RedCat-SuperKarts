/*
 * FUN_004ab6d0 at 004ab6d0
 * undefined FUN_004ab6d0(void)
 * Address ranges: 004ab6d0-004ab6f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004ab6d0(int param_1)

{
  if (*(int *)(param_1 + 0x274) == 1) {
    (**(code **)(**(int **)(param_1 + 0x25c) + 8))(*(int **)(param_1 + 0x25c));
    *(undefined4 *)(param_1 + 0x274) = 0;
  }
  return;
}

