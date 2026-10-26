/*
 * FUN_00429670 at 00429670
 * undefined __register FUN_00429670(int param_1)
 * Address ranges: 00429670-00429682
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429670(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 5) = DAT_0047d780;
    DAT_0047d780 = param_1;
  }
  return;
}

