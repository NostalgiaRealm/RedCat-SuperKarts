/*
 * FUN_0044244c at 0044244c
 * undefined __register FUN_0044244c(int * param_1, char param_2)
 * Address ranges: 0044244c-00442468
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044244c(int *param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = FUN_004298bc(param_1);
  if (piVar1 != (int *)0x0) {
    FUN_0042d36c(piVar1,(int)param_1,param_2);
  }
  return;
}

