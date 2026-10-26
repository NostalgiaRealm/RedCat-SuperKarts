/*
 * FUN_0042bb30 at 0042bb30
 * undefined FUN_0042bb30(void)
 * Address ranges: 0042bb30-0042bb56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bb30(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x50)) {
    FUN_0043f81c(param_1,param_2);
    if (*(int *)(param_1 + 0x24) == 0) {
      FUN_004405f0(param_1,0xb03d,0,0);
    }
  }
  return;
}

