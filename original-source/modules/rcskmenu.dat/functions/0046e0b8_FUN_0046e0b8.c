/*
 * FUN_0046e0b8 at 0046e0b8
 * undefined __register FUN_0046e0b8(int param_1, int param_2)
 * Address ranges: 0046e0b8-0046e0cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e0b8(int param_1,int param_2)

{
  if (param_2 != *(int *)(param_1 + 0x2e4)) {
    *(int *)(param_1 + 0x2e4) = param_2;
  }
  *(undefined1 *)(param_1 + 0x2d8) = 1;
  return;
}

