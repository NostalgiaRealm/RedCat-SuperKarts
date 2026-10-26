/*
 * FUN_00405490 at 00405490
 * int * __register FUN_00405490(int * param_1)
 * Address ranges: 00405490-004054a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00405490(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))();
    param_1 = piVar1;
  }
  return param_1;
}

