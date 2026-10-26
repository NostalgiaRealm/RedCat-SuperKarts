/*
 * FUN_0043ee8c at 0043ee8c
 * undefined __register FUN_0043ee8c(int * param_1, undefined4 param_2)
 * Address ranges: 0043ee8c-0043eead
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ee8c(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x7c))(param_1,param_1[0xc],param_2,param_1[0xf],param_1[0xe]);
  *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 2;
  return;
}

