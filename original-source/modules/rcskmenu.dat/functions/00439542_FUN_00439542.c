/*
 * FUN_00439542 at 00439542
 * undefined __register FUN_00439542(int param_1, int param_2)
 * Address ranges: 0043953e-0043954a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439542(int param_1,int param_2)

{
  for (; (0 < param_2 && (param_1 != 0)); param_1 = *(int *)(param_1 + 0x58)) {
    param_2 = param_2 + -1;
  }
  return;
}

