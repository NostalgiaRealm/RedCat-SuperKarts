/*
 * FUN_00418adc at 00418adc
 * undefined FUN_00418adc(void)
 * Address ranges: 00418adc-00418aef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418adc(int param_1)

{
  if (*(short *)(param_1 + 0x32) != 0) {
    (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x34),param_1);
  }
  return;
}

