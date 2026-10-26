/*
 * FUN_00458480 at 00458480
 * undefined __register FUN_00458480(int param_1, int param_2)
 * Address ranges: 00458480-0045848c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00458480(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 0x1e)) {
    *(int *)(param_1 + 0x40) = param_2;
  }
  return;
}

