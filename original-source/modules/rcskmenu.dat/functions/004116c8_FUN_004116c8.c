/*
 * FUN_004116c8 at 004116c8
 * undefined FUN_004116c8(void)
 * Address ranges: 004116c8-0041171c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004116c8(int *param_1,int param_2,undefined4 *param_3)

{
  if ((char)param_1[6] != '\0') {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c78c,0);
  }
  if ((param_2 < 0) || (param_1[4] <= param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  (**(code **)(*param_1 + 0x74))();
  FUN_00403ba4((int *)(param_1[3] + param_2 * 8),param_3);
  (**(code **)(*param_1 + 0x70))();
  return;
}

