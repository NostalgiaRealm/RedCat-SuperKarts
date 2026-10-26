/*
 * FUN_0040f72c at 0040f72c
 * undefined __register FUN_0040f72c(int * param_1, int param_2, int param_3)
 * Address ranges: 0040f72c-0040f796
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f72c(int *param_1,int param_2,int param_3)

{
  if ((param_2 < 0) || (param_1[2] < param_2)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  if (param_1[2] == param_1[3]) {
    (**(code **)*param_1)();
  }
  if (param_2 < param_1[2]) {
    FUN_0040282c((undefined4 *)(param_1[1] + param_2 * 4),
                 (undefined4 *)(param_1[1] + 4 + param_2 * 4),(param_1[2] - param_2) * 4);
  }
  *(int *)(param_1[1] + param_2 * 4) = param_3;
  param_1[2] = param_1[2] + 1;
  if (param_3 != 0) {
    (**(code **)(*param_1 + 4))(param_1,param_3,0);
  }
  return;
}

