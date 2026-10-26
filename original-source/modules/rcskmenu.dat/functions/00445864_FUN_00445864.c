/*
 * FUN_00445864 at 00445864
 * undefined __register FUN_00445864(int param_1, char param_2)
 * Address ranges: 00445864-00445887
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445864(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x138)) {
    *(char *)(param_1 + 0x138) = param_2;
    *(undefined1 *)(param_1 + 0x160) = 0;
    FUN_004405f0(param_1,0xb010,0,0);
  }
  return;
}

