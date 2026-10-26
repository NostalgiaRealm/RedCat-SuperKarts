/*
 * FUN_0045dfec at 0045dfec
 * undefined __register FUN_0045dfec(int param_1, int param_2)
 * Address ranges: 0045dfec-0045e018
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045dfec(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x208) != 0) {
    FUN_004535e0(*(int *)(param_1 + 0x208),param_1);
  }
  *(int *)(param_1 + 0x208) = param_2;
  if (param_2 != 0) {
    FUN_004535a0(param_2,param_1);
  }
  return;
}

