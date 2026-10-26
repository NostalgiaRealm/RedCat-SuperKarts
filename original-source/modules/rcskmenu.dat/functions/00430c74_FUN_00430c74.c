/*
 * FUN_00430c74 at 00430c74
 * undefined __register FUN_00430c74(int param_1, int * param_2)
 * Address ranges: 00430c74-00430ca3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430c74(int param_1,int *param_2)

{
  while( true ) {
    if (param_1 == 0) {
      FUN_00403b50(param_2);
      return;
    }
    if (*(int *)(param_1 + 0x70) != 0) break;
    param_1 = *(int *)(param_1 + 0x24);
  }
  FUN_00403ba4(param_2,*(undefined4 **)(param_1 + 0x70));
  return;
}

