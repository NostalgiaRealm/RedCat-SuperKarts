/*
 * FUN_0043eed0 at 0043eed0
 * undefined __register FUN_0043eed0(int * param_1, undefined4 param_2)
 * Address ranges: 0043eed0-0043eeef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043eed0(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x7c))(param_1,param_1[0xc],param_1[0xd],param_2,param_1[0xe]);
  *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 8;
  return;
}

