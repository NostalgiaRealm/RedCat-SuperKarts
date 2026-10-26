/*
 * FUN_00448c70 at 00448c70
 * undefined FUN_00448c70(void)
 * Address ranges: 00448c70-00448cbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448c70(int param_1)

{
  if (*(int *)(param_1 + 0x10) != -1) {
    FUN_0049dd20(*(undefined4 *)(*(int *)(param_1 + 0x10) * 0xd0 + 0x18 + DAT_0067ee20));
    FUN_0049d7a0();
    *(undefined4 *)(*(int *)(param_1 + 0x10) * 0xd0 + 0x44 + DAT_0067ee20) = 0;
  }
  return;
}

