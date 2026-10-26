/*
 * FUN_00439e64 at 00439e64
 * undefined __register FUN_00439e64(int * param_1, char param_2)
 * Address ranges: 00439e64-00439e75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439e64(int *param_1,char param_2)

{
  if (param_2 != (char)param_1[9]) {
    *(char *)(param_1 + 9) = param_2;
    *(undefined1 *)((int)param_1 + 0x35) = 0;
    FUN_00439764(param_1);
  }
  return;
}

