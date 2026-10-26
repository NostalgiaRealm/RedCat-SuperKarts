/*
 * FUN_00411720 at 00411720
 * undefined FUN_00411720(void)
 * Address ranges: 00411720-00411759
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411720(int *param_1,int param_2,undefined4 param_3)

{
  if ((param_2 < 0) || (param_1[4] <= param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  (**(code **)(*param_1 + 0x74))();
  *(undefined4 *)(param_1[3] + 4 + param_2 * 8) = param_3;
  (**(code **)(*param_1 + 0x70))();
  return;
}

