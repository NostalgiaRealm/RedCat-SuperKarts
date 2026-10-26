/*
 * FUN_004416e4 at 004416e4
 * undefined FUN_004416e4(void)
 * Address ranges: 004416e4-00441715
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004416e4(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = *param_2;
  uStack_10 = param_2[1];
  if (*(short *)(param_1 + 0x11a) != 0) {
    (**(code **)(param_1 + 0x118))(*(undefined4 *)(param_1 + 0x11c),param_1,&uStack_14,param_3);
  }
  return;
}

