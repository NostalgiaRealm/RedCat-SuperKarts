/*
 * FUN_004482f0 at 004482f0
 * undefined FUN_004482f0(void)
 * Address ranges: 004482f0-0044833b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004482f0(int param_1)

{
  if (*(int *)(param_1 + 0x10) != -1) {
    FUN_0049dd20(*(undefined4 *)(*(int *)(param_1 + 0x10) * 0xd0 + 0x18 + DAT_0067ee20));
    FUN_0049d7a0();
    *(undefined4 *)(*(int *)(param_1 + 0x10) * 0xd0 + 0x44 + DAT_0067ee20) = 0;
  }
  return;
}

