/*
 * FUN_00410000 at 00410000
 * undefined FUN_00410000(void)
 * Address ranges: 00410000-0041002e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410000(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040fed8(param_1);
  if ((-1 < iVar1) && (param_2 != iVar1)) {
    FUN_0040f7a4(*(int **)(*(int *)(param_1 + 4) + 8),iVar1,param_2);
    FUN_0040feb4(param_1,'\x01');
  }
  return;
}

