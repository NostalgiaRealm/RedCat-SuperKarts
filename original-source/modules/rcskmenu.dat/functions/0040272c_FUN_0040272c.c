/*
 * FUN_0040272c at 0040272c
 * undefined __register FUN_0040272c(int param_1)
 * Address ranges: 0040272c-00402741
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040272c(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (*(code *)PTR_FUN_0047b028)();
    if (iVar1 != 0) {
      FUN_004027a0(CONCAT31((int3)((uint)iVar1 >> 8),2));
      return;
    }
  }
  return;
}

