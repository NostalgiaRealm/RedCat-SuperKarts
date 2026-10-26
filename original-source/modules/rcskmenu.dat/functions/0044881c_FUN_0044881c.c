/*
 * FUN_0044881c at 0044881c
 * undefined __register FUN_0044881c(int param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0044881c-00448874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044881c(int param_1,int *param_2,undefined4 param_3)

{
  if (param_2 != (int *)0x0) {
    if ((int *)param_2[2] != (int *)0x0) {
      FUN_004487e8((int *)param_2[2],param_2,param_3,&stack0xfffffffc);
    }
    if (param_2[6] == 0) {
      if (param_2[5] != 0) {
        *(int *)(param_2[5] + 8) = param_2[3];
      }
    }
    else {
      *(int *)(param_2[6] + 0xc) = param_2[3];
    }
    if (param_2[3] != 0) {
      *(int *)(param_2[3] + 0x18) = param_2[6];
    }
    if (param_2 == *(int **)(param_1 + 100)) {
      *(undefined4 *)(param_1 + 100) = 0;
    }
    FUN_00402eac(param_2);
  }
  return;
}

