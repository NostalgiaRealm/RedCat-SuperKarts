/*
 * FUN_00467660 at 00467660
 * undefined __register FUN_00467660(int * param_1, int * param_2)
 * Address ranges: 00467660-004676a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467660(int *param_1,int *param_2)

{
  WPARAM WVar1;
  
  if ((param_2 == (int *)0x0) || (param_1 == (int *)param_2[0x7d])) {
    FUN_0046711c(param_1,param_2);
    if (param_2 == (int *)0x0) {
      FUN_0046655c(param_1,0xffffffff);
    }
    else if (param_2 == (int *)param_1[0x91]) {
      WVar1 = FUN_00466cc0((int)param_2);
      FUN_0046655c(param_1,WVar1);
    }
  }
  return;
}

