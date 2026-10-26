/*
 * FUN_0041acf4 at 0041acf4
 * undefined4 __register FUN_0041acf4(int param_1)
 * Address ranges: 0041acf4-0041ad08
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041acf4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x2c))();
  }
  return uVar1;
}

