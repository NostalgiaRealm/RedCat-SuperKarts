/*
 * FUN_00440c6c at 00440c6c
 * undefined __register FUN_00440c6c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00440c6c-00440ca1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440c6c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (*(short *)(param_1 + 0xca) != 0) {
    (**(code **)(param_1 + 200))
              (*(undefined4 *)(param_1 + 0xcc),param_1,param_2,param_4,param_5,param_3);
  }
  return;
}

