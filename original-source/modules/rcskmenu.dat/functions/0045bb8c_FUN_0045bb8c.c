/*
 * FUN_0045bb8c at 0045bb8c
 * undefined __register FUN_0045bb8c(int param_1, int param_2)
 * Address ranges: 0045bb8c-0045bba7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045bb8c(int param_1,int param_2)

{
  *(int *)(param_1 + 0xc) = param_2;
  if (100 < param_2) {
    *(undefined4 *)(param_1 + 0xc) = 100;
    return;
  }
  if (param_2 < 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

