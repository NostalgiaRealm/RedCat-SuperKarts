/*
 * FUN_00443f2c at 00443f2c
 * undefined __register FUN_00443f2c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined1 param_5, undefined4 param_6)
 * Address ranges: 00443f2c-00443f5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443f2c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5,undefined4 param_6)

{
  if (*(short *)(param_1 + 0x192) != 0) {
    (**(code **)(param_1 + 400))
              (*(undefined4 *)(param_1 + 0x194),param_1,param_2,param_4,param_5,param_6,param_3);
  }
  return;
}

