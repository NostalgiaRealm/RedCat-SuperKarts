/*
 * FUN_00429d64 at 00429d64
 * bool __register FUN_00429d64(int param_1)
 * Address ranges: 00429d64-00429d79
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00429d64(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00429ce4(param_1);
  return iVar1 < *(int *)(param_1 + 0x10);
}

