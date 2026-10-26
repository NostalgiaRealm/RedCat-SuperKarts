/*
 * FUN_00411584 at 00411584
 * undefined FUN_00411584(void)
 * Address ranges: 00411584-004115ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00411584(int param_1,int param_2)

{
  if ((param_2 < 0) || (*(int *)(param_1 + 0x10) <= param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + 4 + param_2 * 8);
}

