/*
 * FUN_0042f75c at 0042f75c
 * undefined FUN_0042f75c(void)
 * Address ranges: 0042f75c-0042f7b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f75c(int param_1,int param_2)

{
  int *piVar1;
  undefined4 auStack_1c [4];
  
  FUN_00444ecc(param_1);
  if (*(int *)(param_2 + 8) == 0) {
    FUN_004405f0(param_1,0xb039,0,*(undefined4 *)(param_2 + 4));
    piVar1 = *(int **)(param_2 + 4);
    if (param_1 == piVar1[0x24]) {
      FUN_0043f054((int)piVar1,auStack_1c);
      FUN_00403088(piVar1,0xffffffff,auStack_1c);
    }
  }
  return;
}

