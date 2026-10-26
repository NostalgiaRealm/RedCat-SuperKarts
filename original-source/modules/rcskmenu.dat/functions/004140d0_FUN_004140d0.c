/*
 * FUN_004140d0 at 004140d0
 * uint __register FUN_004140d0(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004140d0-004140e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004140d0(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint local_4;
  
  local_4 = param_3;
  uVar1 = FUN_0041292c(param_1,&local_4,1);
  return CONCAT31((int3)((uint)uVar1 >> 8),(undefined1)local_4);
}

