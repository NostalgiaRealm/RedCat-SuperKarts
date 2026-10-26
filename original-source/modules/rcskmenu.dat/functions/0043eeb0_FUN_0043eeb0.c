/*
 * FUN_0043eeb0 at 0043eeb0
 * undefined __register FUN_0043eeb0(int * param_1, undefined4 param_2)
 * Address ranges: 0043eeb0-0043eecf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043eeb0(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x7c))(param_1,param_1[0xc],param_1[0xd],param_1[0xf],param_2);
  *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 4;
  return;
}

