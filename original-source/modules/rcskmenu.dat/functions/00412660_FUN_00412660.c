/*
 * FUN_00412660 at 00412660
 * bool __register FUN_00412660(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 00412660-00412673
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00412660(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  return (char)uVar1 == '\0';
}

