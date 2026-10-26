/*
 * FUN_00458468 at 00458468
 * int __register FUN_00458468(int param_1)
 * Address ranges: 00458468-0045847e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00458468(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40) + 1;
  if ((iVar1 < 0x1e) && (iVar1 < *(int *)(param_1 + 0x44))) {
    return iVar1;
  }
  return 999;
}

