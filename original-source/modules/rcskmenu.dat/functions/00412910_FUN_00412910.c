/*
 * FUN_00412910 at 00412910
 * undefined __register FUN_00412910(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 00412910-0041291e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412910(int param_1,undefined4 param_2,uint param_3)

{
  FUN_004140d0(param_1,param_2,param_3);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  return;
}

