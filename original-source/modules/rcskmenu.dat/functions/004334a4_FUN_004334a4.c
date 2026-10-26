/*
 * FUN_004334a4 at 004334a4
 * uint __register FUN_004334a4(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004334a4-004334c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004334a4(int param_1,undefined4 param_2,uint param_3)

{
  uint local_8;
  
  local_8 = param_3 & 0xffffff00;
  if (*(short *)(param_1 + 0xaa) != 0) {
    param_1 = (**(code **)(param_1 + 0xa8))(*(undefined4 *)(param_1 + 0xac),param_2,&local_8);
  }
  return CONCAT31((int3)((uint)param_1 >> 8),(undefined1)local_8);
}

