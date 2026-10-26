/*
 * FUN_00447208 at 00447208
 * int __register FUN_00447208(int param_1)
 * Address ranges: 00447208-0044721b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00447208(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

