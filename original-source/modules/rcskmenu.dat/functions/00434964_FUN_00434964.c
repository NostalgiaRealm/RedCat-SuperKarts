/*
 * FUN_00434964 at 00434964
 * undefined __register FUN_00434964(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00434964-00434982
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434964(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if (0 < param_1[0x14]) {
    param_1[0x14] = param_1[0x14] + -1;
  }
  if ((char)param_1[0x13] != '\0') {
    *(undefined1 *)(param_1 + 0x13) = 0;
    FUN_00403088(param_1,param_2,param_3);
  }
  return;
}

