/*
 * FUN_0042f69c at 0042f69c
 * undefined FUN_0042f69c(void)
 * Address ranges: 0042f69c-0042f6c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f69c(int *param_1,int param_2)

{
  FUN_00444a64(param_1,param_2);
  if (((*(byte *)(param_1 + 8) & 0x10) == 0) && (*(int *)(param_2 + 0xc) == 1)) {
    *(undefined4 *)(param_2 + 0xc) = 2;
  }
  return;
}

