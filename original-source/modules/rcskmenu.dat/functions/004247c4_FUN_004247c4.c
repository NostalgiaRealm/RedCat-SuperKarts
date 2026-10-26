/*
 * FUN_004247c4 at 004247c4
 * undefined __register FUN_004247c4(int param_1, char param_2)
 * Address ranges: 004247c4-004247fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004247c4(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x1fa)) {
    *(char *)(param_1 + 0x1fa) = param_2;
    if (param_2 == '\x01') {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffdff;
    }
    else {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x200;
    }
    FUN_00442cd4(param_1);
  }
  return;
}

