/*
 * FUN_0044842c at 0044842c
 * undefined __register FUN_0044842c(int param_1, undefined4 param_2, undefined4 param_3, int * param_4)
 * Address ranges: 0044842c-00448505
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044842c(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  if ((byte)(*(char *)(*(int *)(param_1 + 0x14) + 0x4b) - 1U) < 2) {
    FUN_0044834c(*param_4 + 1,param_4[1] + 1,param_3,(int)&stack0xfffffffc);
    FUN_004483a4(*param_4 + 3,param_4[1] + *(int *)(param_1 + 0x18) + 1,*param_4 + 5,param_4[3] + -2
                 ,(int)&stack0xfffffffc);
    FUN_004483a4(*param_4 + 6,param_4[1] + *(int *)(param_1 + 0x18) + 1,*param_4 + 8,param_4[3] + -2
                 ,(int)&stack0xfffffffc);
  }
  else {
    FUN_0044834c((param_4[2] - *(int *)(param_1 + 0x18)) + 1,param_4[1] + 1,param_3,
                 (int)&stack0xfffffffc);
    FUN_004483a4(*param_4 + 2,param_4[1] + 3,(param_4[2] - *(int *)(param_1 + 0x18)) + -2,
                 param_4[1] + 5,(int)&stack0xfffffffc);
    FUN_004483a4(*param_4 + 2,param_4[1] + 6,(param_4[2] - *(int *)(param_1 + 0x18)) + -2,
                 param_4[1] + 8,(int)&stack0xfffffffc);
  }
  return;
}

