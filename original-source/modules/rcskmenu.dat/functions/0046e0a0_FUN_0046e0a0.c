/*
 * FUN_0046e0a0 at 0046e0a0
 * undefined __register FUN_0046e0a0(int param_1, char param_2)
 * Address ranges: 0046e0a0-0046e0b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e0a0(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x2d5)) {
    *(char *)(param_1 + 0x2d5) = param_2;
  }
  *(undefined1 *)(param_1 + 0x2d7) = 1;
  return;
}

