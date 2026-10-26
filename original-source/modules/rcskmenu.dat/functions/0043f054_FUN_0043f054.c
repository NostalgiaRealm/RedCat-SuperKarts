/*
 * FUN_0043f054 at 0043f054
 * undefined __register FUN_0043f054(int param_1, undefined4 * param_2)
 * Address ranges: 0043f054-0043f071
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f054(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  param_2[1] = *(undefined4 *)(param_1 + 0x34);
  param_2[2] = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x38);
  param_2[3] = *(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x3c);
  return;
}

