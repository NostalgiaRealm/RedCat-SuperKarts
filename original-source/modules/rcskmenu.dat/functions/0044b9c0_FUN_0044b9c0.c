/*
 * FUN_0044b9c0 at 0044b9c0
 * undefined __register FUN_0044b9c0(char param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0044b9c0-0044b9f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b9c0(char param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_4 + -4) = 0x80000014;
  if (param_1 == '\x01') {
    *(undefined4 *)(param_4 + -4) = 0x80000010;
  }
  *(undefined4 *)(param_4 + -8) = 0x80000010;
  if (param_1 == '\x01') {
    *(undefined4 *)(param_4 + -8) = 0x80000014;
  }
  return;
}

