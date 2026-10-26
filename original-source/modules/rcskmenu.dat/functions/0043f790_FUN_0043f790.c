/*
 * FUN_0043f790 at 0043f790
 * undefined __register FUN_0043f790(int param_1, char param_2)
 * Address ranges: 0043f790-0043f7b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f790(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x89)) {
    *(char *)(param_1 + 0x89) = param_2;
    *(undefined1 *)(param_1 + 0x8a) = 0;
    FUN_004405f0(param_1,0xb022,0,0);
  }
  return;
}

