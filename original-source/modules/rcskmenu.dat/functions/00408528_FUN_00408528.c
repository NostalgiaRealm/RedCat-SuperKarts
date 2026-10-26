/*
 * FUN_00408528 at 00408528
 * int * __register FUN_00408528(int param_1)
 * Address ranges: 00408528-0040853b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00408528(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00402714(param_1 + 4);
  *piVar1 = param_1 + 4;
  return piVar1 + 1;
}

