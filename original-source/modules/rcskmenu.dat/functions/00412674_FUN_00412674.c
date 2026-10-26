/*
 * FUN_00412674 at 00412674
 * undefined FUN_00412674(void)
 * Address ranges: 00412674-00412693
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00412674(int param_1,undefined4 param_2,uint param_3)

{
  uint uStack_8;
  
  uStack_8 = param_3 & 0xffffff00;
  if (*(short *)(param_1 + 0x5a) != 0) {
    (**(code **)(param_1 + 0x58))(*(undefined4 *)(param_1 + 0x5c),param_1,param_2,&uStack_8);
  }
  return uStack_8 & 0xff;
}

