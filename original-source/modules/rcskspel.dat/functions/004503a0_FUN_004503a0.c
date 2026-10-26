/*
 * FUN_004503a0 at 004503a0
 * undefined FUN_004503a0(void)
 * Address ranges: 004503a0-004503b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004503a0(int param_1,int param_2)

{
  if (param_2 != *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = param_2;
    FUN_004500e0();
  }
  return;
}

