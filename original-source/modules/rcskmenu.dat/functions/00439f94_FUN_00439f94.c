/*
 * FUN_00439f94 at 00439f94
 * undefined __register FUN_00439f94(int param_1, int param_2)
 * Address ranges: 00439f94-00439fae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439f94(int param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_004365f0(*(int **)(param_1 + 0x28),*(int *)(param_2 + 0x28));
    return;
  }
  FUN_004365f0(*(int **)(param_1 + 0x28),0);
  return;
}

