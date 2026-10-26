/*
 * FUN_0043ee6c at 0043ee6c
 * undefined __register FUN_0043ee6c(int * param_1, undefined4 param_2)
 * Address ranges: 0043ee6c-0043ee8b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ee6c(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x7c))(param_1,param_2,param_1[0xd],param_1[0xf],param_1[0xe]);
  *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 1;
  return;
}

