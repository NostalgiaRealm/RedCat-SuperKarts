/*
 * FUN_0044785c at 0044785c
 * undefined __register FUN_0044785c(int param_1)
 * Address ranges: 0044785c-0044786f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044785c(int param_1)

{
  *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
  if (*(int *)(param_1 + 0x6c) < 1) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
    FUN_0044903c(param_1);
  }
  return;
}

