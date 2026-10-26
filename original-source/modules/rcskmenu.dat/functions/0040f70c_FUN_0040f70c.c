/*
 * FUN_0040f70c at 0040f70c
 * int __register FUN_0040f70c(int param_1, int param_2)
 * Address ranges: 0040f70c-0040f72a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040f70c(int param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = 0;
      (iVar1 < *(int *)(param_1 + 8) && (param_2 != *(int *)(*(int *)(param_1 + 4) + iVar1 * 4)));
      iVar1 = iVar1 + 1) {
  }
  if (iVar1 == *(int *)(param_1 + 8)) {
    iVar1 = -1;
  }
  return iVar1;
}

