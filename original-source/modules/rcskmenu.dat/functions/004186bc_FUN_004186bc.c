/*
 * FUN_004186bc at 004186bc
 * undefined __register FUN_004186bc(int * param_1, undefined4 param_2, int * param_3)
 * Address ranges: 004186bc-004186f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004186bc(int *param_1,undefined4 param_2,int *param_3)

{
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_1 + 0x10))();
    FUN_00418a68(param_1,0xf);
    (**(code **)(*param_3 + 0x14))(param_3,param_1,param_2);
    (**(code **)(*param_1 + 0xc))();
  }
  return;
}

