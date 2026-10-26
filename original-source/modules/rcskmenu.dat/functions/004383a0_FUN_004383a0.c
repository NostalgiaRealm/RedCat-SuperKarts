/*
 * FUN_004383a0 at 004383a0
 * int __register FUN_004383a0(int param_1, int param_2)
 * Address ranges: 004383a0-004383b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004383a0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = -1;
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_0040f70c(*(int *)(param_1 + 0x50),param_2);
  }
  return iVar1;
}

