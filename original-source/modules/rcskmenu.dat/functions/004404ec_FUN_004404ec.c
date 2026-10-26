/*
 * FUN_004404ec at 004404ec
 * undefined __register FUN_004404ec(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 004404ec-00440519
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004404ec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (*(short *)(param_1 + 0xb2) != 0) {
    (**(code **)(param_1 + 0xb0))
              (*(undefined4 *)(param_1 + 0xb4),param_1,param_2,param_4,param_5,param_3);
  }
  return;
}

