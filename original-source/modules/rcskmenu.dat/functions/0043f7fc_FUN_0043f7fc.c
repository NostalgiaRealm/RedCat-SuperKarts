/*
 * FUN_0043f7fc at 0043f7fc
 * undefined __register FUN_0043f7fc(int param_1, char param_2)
 * Address ranges: 0043f7fc-0043f818
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f7fc(int param_1,char param_2)

{
  if ((param_2 != *(char *)(param_1 + 0x4a)) &&
     (*(char *)(param_1 + 0x4a) = param_2, *(int *)(param_1 + 0x24) != 0)) {
    FUN_004405f0(param_1,0xb009,0,0);
  }
  return;
}

