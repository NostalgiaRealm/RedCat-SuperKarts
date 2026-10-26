/*
 * FUN_0043f920 at 0043f920
 * undefined FUN_0043f920(void)
 * Address ranges: 0043f920-0043f943
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f920(int *param_1,char param_2)

{
  if (param_1[9] != 0) {
    if (param_2 == '\0') {
      FUN_0043f8a0(param_1,0);
    }
    else {
      FUN_0043f8a0(param_1,*(int *)(*(int *)(param_1[9] + 0x134) + 8) + -1);
    }
  }
  return;
}

