/*
 * FUN_0042a284 at 0042a284
 * undefined __register FUN_0042a284(int param_1, int param_2)
 * Address ranges: 0042a284-0042a29a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a284(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  if (param_2 < 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  FUN_0042a7a0(*(int *)(param_1 + 4));
  return;
}

