/*
 * FUN_004578f4 at 004578f4
 * undefined __register FUN_004578f4(int param_1, int param_2)
 * Address ranges: 004578f4-00457900
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004578f4(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 0x1e)) {
    *(int *)(param_1 + 4) = param_2;
  }
  return;
}

