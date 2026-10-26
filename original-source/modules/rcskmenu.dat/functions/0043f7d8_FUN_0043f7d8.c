/*
 * FUN_0043f7d8 at 0043f7d8
 * undefined __register FUN_0043f7d8(int param_1, int param_2)
 * Address ranges: 0043f7d8-0043f7f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f7d8(int param_1,int param_2)

{
  if (param_2 != *(int *)(param_1 + 0x60)) {
    *(int *)(param_1 + 0x60) = param_2;
    *(undefined1 *)(param_1 + 0x4a) = 0;
    FUN_004405f0(param_1,0xb00d,0,0);
  }
  return;
}

