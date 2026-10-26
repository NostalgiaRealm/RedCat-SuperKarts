/*
 * FUN_00414a64 at 00414a64
 * undefined __register FUN_00414a64(int param_1, int param_2)
 * Address ranges: 00414a64-00414a87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414a64(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    FUN_0040f848(*(int **)(param_1 + 0x14),param_2);
    if ((*(int **)(param_1 + 0x14))[2] == 0) {
      FUN_00402eac(*(int **)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
  }
  return;
}

