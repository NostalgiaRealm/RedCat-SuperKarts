/*
 * FUN_0043f770 at 0043f770
 * undefined __register FUN_0043f770(int param_1, char param_2)
 * Address ranges: 0043f770-0043f78c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f770(int param_1,char param_2)

{
  if ((param_2 != *(char *)(param_1 + 0x49)) &&
     (*(char *)(param_1 + 0x49) = param_2, *(int *)(param_1 + 0x24) != 0)) {
    FUN_004405f0(param_1,0xb008,0,0);
  }
  return;
}

