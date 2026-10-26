/*
 * FUN_004176d0 at 004176d0
 * undefined __register FUN_004176d0(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 004176d0-004176e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004176d0(int *param_1,int param_2,undefined4 param_3)

{
  if (param_2 != param_1[6]) {
    param_1[6] = param_2;
    FUN_00403088(param_1,param_2,param_3);
  }
  return;
}

