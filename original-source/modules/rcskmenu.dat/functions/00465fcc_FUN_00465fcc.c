/*
 * FUN_00465fcc at 00465fcc
 * undefined FUN_00465fcc(void)
 * Address ranges: 00465fcc-00465ff3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00465fcc(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uStack_8;
  
  uStack_8 = CONCAT31((int3)((uint)param_3 >> 8),1);
  if (*(short *)(param_1 + 0x22a) != 0) {
    (**(code **)(param_1 + 0x228))(*(undefined4 *)(param_1 + 0x22c),param_1,&uStack_8);
  }
  return uStack_8 & 0xff;
}

