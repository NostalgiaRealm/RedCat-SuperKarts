/*
 * FUN_0044b770 at 0044b770
 * undefined FUN_0044b770(void)
 * Address ranges: 0044b770-0044b790
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0044b770(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  return (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0x60;
}

