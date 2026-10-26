/*
 * FUN_00411464 at 00411464
 * undefined __register FUN_00411464(int * param_1, int param_2, int param_3)
 * Address ranges: 00411464-004114b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411464(int *param_1,int param_2,int param_3)

{
  if ((param_2 < 0) || (param_1[4] <= param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  if ((param_3 < 0) || (param_1[4] <= param_3)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_3);
  }
  (**(code **)(*param_1 + 0x74))();
  FUN_004114bc((int)param_1,param_2,param_3);
  (**(code **)(*param_1 + 0x70))();
  return;
}

