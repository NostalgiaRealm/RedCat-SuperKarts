/*
 * FUN_004a89f0 at 004a89f0
 * undefined FUN_004a89f0(void)
 * Address ranges: 004a89f0-004a8a32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a89f0(int param_1,int param_2)

{
  if (*(float *)(param_1 + 0xc) < *(float *)(param_2 + 0xc)) {
    return DAT_004fd108;
  }
  if (*(float *)(param_1 + 0xc) != *(float *)(param_2 + 0xc)) {
    return -DAT_004fd108;
  }
  return 0;
}

