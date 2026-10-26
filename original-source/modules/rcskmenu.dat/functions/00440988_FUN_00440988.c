/*
 * FUN_00440988 at 00440988
 * undefined __register FUN_00440988(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00440988-004409bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440988(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (*(short *)(param_1 + 0xba) != 0) {
    (**(code **)(param_1 + 0xb8))
              (*(undefined4 *)(param_1 + 0xbc),param_1,param_2,param_4,param_5,param_3);
  }
  return;
}

