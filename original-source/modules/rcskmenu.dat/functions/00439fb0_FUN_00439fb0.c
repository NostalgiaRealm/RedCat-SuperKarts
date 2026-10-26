/*
 * FUN_00439fb0 at 00439fb0
 * undefined __register FUN_00439fb0(int param_1, int param_2)
 * Address ranges: 00439fb0-00439fc9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439fb0(int param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(*(int *)(param_1 + 0x28) + 0x5c) == *(int *)(param_2 + 0x28))) {
    FUN_004365f0(*(int **)(param_1 + 0x28),0);
  }
  return;
}

