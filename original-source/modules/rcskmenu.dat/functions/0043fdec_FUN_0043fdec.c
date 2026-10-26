/*
 * FUN_0043fdec at 0043fdec
 * undefined __register FUN_0043fdec(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 0043fdec-0043fe15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043fdec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(short *)(param_1 + 0x102) != 0) {
    (**(code **)(param_1 + 0x100))(*(undefined4 *)(param_1 + 0x104),param_1,param_2,param_4,param_3)
    ;
  }
  return;
}

