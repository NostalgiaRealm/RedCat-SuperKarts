/*
 * FUN_00440420 at 00440420
 * uint __register FUN_00440420(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00440420-0044044d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00440420(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_8;
  undefined3 uStack_7;
  
  _local_8 = CONCAT31((int3)((uint)param_3 >> 8),1);
  if (*(short *)(param_1 + 0xaa) != 0) {
    param_1 = (**(code **)(param_1 + 0xa8))
                        (*(undefined4 *)(param_1 + 0xac),param_1,param_2,&local_8,param_3);
  }
  return CONCAT31((int3)((uint)param_1 >> 8),local_8);
}

