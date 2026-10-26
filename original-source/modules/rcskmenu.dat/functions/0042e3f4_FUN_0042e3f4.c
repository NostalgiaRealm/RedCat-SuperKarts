/*
 * FUN_0042e3f4 at 0042e3f4
 * undefined __register FUN_0042e3f4(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0042e3f4-0042e412
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042e3f4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(byte *)(param_1 + 8) & 2) == 0) {
    FUN_00403088(param_1,param_2,param_3);
    return;
  }
  *(byte *)(param_1 + 0xb3) = *(byte *)(param_1 + 0xb3) & 0xdf;
  return;
}

