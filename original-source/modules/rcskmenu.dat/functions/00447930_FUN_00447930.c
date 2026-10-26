/*
 * FUN_00447930 at 00447930
 * undefined __register FUN_00447930(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 00447930-00447946
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447930(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0) {
    param_2 = *(int *)(param_1 + 100);
  }
  FUN_004478f4(param_2,param_2,param_3,(int)&stack0xfffffffc);
  return;
}

