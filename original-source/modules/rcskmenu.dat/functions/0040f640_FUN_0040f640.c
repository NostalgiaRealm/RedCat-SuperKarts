/*
 * FUN_0040f640 at 0040f640
 * undefined __register FUN_0040f640(undefined4 * param_1, int param_2, int param_3)
 * Address ranges: 0040f640-0040f68e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f640(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < 0) || ((int)param_1[2] <= param_2)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c8f0,param_2);
  }
  if ((param_3 < 0) || ((int)param_1[2] <= param_3)) {
    FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c8f0,param_3);
  }
  iVar1 = param_1[1];
  uVar2 = *(undefined4 *)(iVar1 + param_2 * 4);
  *(undefined4 *)(iVar1 + param_2 * 4) = *(undefined4 *)(param_1[1] + param_3 * 4);
  *(undefined4 *)(iVar1 + param_3 * 4) = uVar2;
  return;
}

