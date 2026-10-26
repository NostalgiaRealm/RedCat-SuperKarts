/*
 * FUN_00451eac at 00451eac
 * int __register FUN_00451eac(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00451eac-00451ecd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00451eac(int *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00451cb4(param_1,1,param_3);
  if (*(char *)(param_1[9] + 0x42c) == '\0') {
    GdiFlush();
  }
  return param_1[0x1e];
}

