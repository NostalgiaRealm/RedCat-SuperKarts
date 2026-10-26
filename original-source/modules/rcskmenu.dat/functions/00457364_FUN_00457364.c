/*
 * FUN_00457364 at 00457364
 * undefined __register FUN_00457364(int param_1, byte param_2, int * param_3)
 * Address ranges: 00457364-00457388
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457364(int param_1,byte param_2,int *param_3)

{
  if (param_2 < 0x49) {
    FUN_00403ba4(param_3,*(undefined4 **)(param_1 + 4 + (uint)param_2 * 4));
  }
  return;
}

