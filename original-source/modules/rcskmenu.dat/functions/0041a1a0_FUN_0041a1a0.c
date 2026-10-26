/*
 * FUN_0041a1a0 at 0041a1a0
 * undefined __register FUN_0041a1a0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined1 param_6, undefined1 param_7)
 * Address ranges: 0041a1a0-0041a1c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a1a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6,undefined1 param_7)

{
  if (*(short *)(param_1 + 0x12) != 0) {
    (**(code **)(param_1 + 0x10))
              (*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}

