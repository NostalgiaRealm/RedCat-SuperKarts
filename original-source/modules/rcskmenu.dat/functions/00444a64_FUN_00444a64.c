/*
 * FUN_00444a64 at 00444a64
 * undefined __register FUN_00444a64(int * param_1, int param_2)
 * Address ranges: 00444a64-00444a84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444a64(int *param_1,int param_2)

{
  if (((*(byte *)(param_1 + 8) & 0x10) != 0) && (param_1[9] != 0)) {
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
  (**(code **)(*param_1 + -0x10))();
  return;
}

