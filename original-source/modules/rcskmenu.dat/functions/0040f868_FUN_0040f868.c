/*
 * FUN_0040f868 at 0040f868
 * undefined __register FUN_0040f868(undefined4 * param_1, int param_2)
 * Address ranges: 0040f868-0040f8a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f868(undefined4 *param_1,int param_2)

{
  if ((param_2 < (int)param_1[2]) || (0x7ffffff < param_2)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c814,param_2);
  }
  if (param_2 != param_1[3]) {
    FUN_00402744(param_1 + 1,param_2 << 2);
    param_1[3] = param_2;
  }
  return;
}

