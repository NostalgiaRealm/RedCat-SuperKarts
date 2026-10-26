/*
 * FUN_00414918 at 00414918
 * undefined __register FUN_00414918(int param_1, int param_2)
 * Address ranges: 00414918-0041493c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414918(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 4) = 0;
  FUN_0040f848(*(int **)(param_1 + 0x10),param_2);
  if ((*(int **)(param_1 + 0x10))[2] == 0) {
    FUN_00402eac(*(int **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

