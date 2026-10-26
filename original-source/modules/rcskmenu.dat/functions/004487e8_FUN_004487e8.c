/*
 * FUN_004487e8 at 004487e8
 * undefined __register FUN_004487e8(int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 004487e8-00448819
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004487e8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((int *)param_1[3] != (int *)0x0) {
    uVar1 = param_4;
    FUN_004487e8((int *)param_1[3],param_4,param_3,param_4);
    param_3 = uVar1;
  }
  if ((int *)param_1[2] != (int *)0x0) {
    FUN_004487e8((int *)param_1[2],param_4,param_3,param_4);
  }
  FUN_00402eac(param_1);
  return;
}

