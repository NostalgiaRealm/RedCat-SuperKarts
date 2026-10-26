/*
 * FUN_0040811c at 0040811c
 * undefined4 __register FUN_0040811c(undefined * param_1)
 * Address ranges: 0040811c-0040812b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040811c(undefined *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004080b4(param_1);
  return CONCAT31((int3)((uint)(iVar1 + 1) >> 8),iVar1 + 1 != 0);
}

