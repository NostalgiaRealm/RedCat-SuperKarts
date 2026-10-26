/*
 * FUN_004266e0 at 004266e0
 * undefined __register FUN_004266e0(int param_1, int param_2)
 * Address ranges: 004266e0-004266fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004266e0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040f848(*(int **)(param_1 + 0x24),param_2);
  if (-1 < iVar1) {
    *(undefined4 *)(param_2 + 0x4c) = 0;
  }
  return;
}

