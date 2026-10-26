/*
 * FUN_00411400 at 00411400
 * undefined FUN_00411400(void)
 * Address ranges: 00411400-00411462
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411400(int *param_1,int param_2)

{
  if ((param_2 < 0) || (param_1[4] <= param_2)) {
    FUN_004108f0(param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  (**(code **)(*param_1 + 0x74))();
  FUN_004044e0(param_1[3] + param_2 * 8,&DAT_0040e27c);
  param_1[4] = param_1[4] + -1;
  if (param_2 < param_1[4]) {
    FUN_0040282c((undefined4 *)(param_1[3] + 8 + param_2 * 8),
                 (undefined4 *)(param_1[3] + param_2 * 8),(param_1[4] - param_2) * 8);
  }
  (**(code **)(*param_1 + 0x70))();
  return;
}

