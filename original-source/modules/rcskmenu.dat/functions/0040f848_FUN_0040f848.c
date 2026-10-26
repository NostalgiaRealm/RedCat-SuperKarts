/*
 * FUN_0040f848 at 0040f848
 * int __register FUN_0040f848(int * param_1, int param_2)
 * Address ranges: 0040f848-0040f866
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040f848(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040f70c((int)param_1,param_2);
  if (-1 < iVar1) {
    FUN_0040f550(param_1,iVar1);
  }
  return iVar1;
}

