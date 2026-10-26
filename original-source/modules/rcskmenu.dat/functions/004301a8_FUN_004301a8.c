/*
 * FUN_004301a8 at 004301a8
 * int __register FUN_004301a8(int param_1)
 * Address ranges: 004301a8-004301c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004301a8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x4c) + 8);
  if (iVar1 == 0) {
    iVar1 = (**(code **)PTR_DAT_0047c734)();
    return iVar1;
  }
  return iVar1;
}

