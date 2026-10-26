/*
 * FUN_004535e0 at 004535e0
 * undefined __register FUN_004535e0(int param_1, int param_2)
 * Address ranges: 004535e0-00453611
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004535e0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040f70c(*(int *)(param_1 + 0x4c),param_2);
  if (iVar1 != -1) {
    FUN_0040f550(*(int **)(param_1 + 0x4c),iVar1);
    FUN_004405f0(param_2,0x4402,0,0);
  }
  return;
}

