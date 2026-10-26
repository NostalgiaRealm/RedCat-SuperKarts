/*
 * FUN_0040f550 at 0040f550
 * undefined __register FUN_0040f550(int * param_1, int param_2)
 * Address ranges: 0040f550-0040f5af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f550(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (param_1[2] <= param_2)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  iVar1 = FUN_0040f6b0(param_1,param_2);
  param_1[2] = param_1[2] + -1;
  if (param_2 < param_1[2]) {
    FUN_0040282c((undefined4 *)(param_1[1] + 4 + param_2 * 4),
                 (undefined4 *)(param_1[1] + param_2 * 4),(param_1[2] - param_2) * 4);
  }
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 4))(param_1,iVar1,2);
  }
  return;
}

