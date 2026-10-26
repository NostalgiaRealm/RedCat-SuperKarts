/*
 * FUN_0044151c at 0044151c
 * undefined FUN_0044151c(void)
 * Address ranges: 0044151c-00441537
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044151c(int *param_1)

{
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    (**(code **)(*param_1 + 0x7c))(param_1,param_1[0xc],param_1[0xd],param_1[0xf],param_1[0xe]);
  }
  return;
}

