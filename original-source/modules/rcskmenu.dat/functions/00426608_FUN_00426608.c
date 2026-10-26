/*
 * FUN_00426608 at 00426608
 * undefined __register FUN_00426608(int param_1, int * param_2, int param_3)
 * Address ranges: 00426608-00426636
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426608(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_0040f70c(*(int *)(param_1 + 0x24),(int)param_2);
  if (-1 < iVar1) {
    iVar1 = FUN_0040303c(param_2,(int)&PTR_FUN_00425f90);
    FUN_00426390(iVar1,param_3);
  }
  return;
}

