/*
 * FUN_0040f7a4 at 0040f7a4
 * undefined __register FUN_0040f7a4(int * param_1, int param_2, int param_3)
 * Address ranges: 0040f7a4-0040f7fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f7a4(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 != param_2) {
    if ((param_3 < 0) || (param_1[2] <= param_3)) {
      FUN_0040f5ec(*param_1,(undefined4 *)PTR_PTR_0047c8f0,param_3);
    }
    uVar1 = FUN_0040f6b0(param_1,param_2);
    *(undefined4 *)(param_1[1] + param_2 * 4) = 0;
    FUN_0040f550(param_1,param_2);
    FUN_0040f72c(param_1,param_3,0);
    *(undefined4 *)(param_1[1] + param_3 * 4) = uVar1;
  }
  return;
}

