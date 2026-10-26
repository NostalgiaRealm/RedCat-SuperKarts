/*
 * FUN_0040f6b0 at 0040f6b0
 * undefined4 __register FUN_0040f6b0(undefined4 * param_1, int param_2)
 * Address ranges: 0040f6b0-0040f6d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040f6b0(undefined4 *param_1,int param_2)

{
  if ((param_2 < 0) || ((int)param_1[2] <= param_2)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  return *(undefined4 *)(param_1[1] + param_2 * 4);
}

