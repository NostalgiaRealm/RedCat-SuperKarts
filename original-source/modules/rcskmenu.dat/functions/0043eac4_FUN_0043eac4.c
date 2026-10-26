/*
 * FUN_0043eac4 at 0043eac4
 * undefined __register FUN_0043eac4(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 0043eac4-0043eb3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043eac4(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  if (param_2 == 0) {
    FUN_00402eac((int *)param_1[0x17]);
    param_1[0x17] = 0;
    param_1[0x10] = param_1[0x10] & 0xffff7fff;
  }
  else {
    param_1[0x10] = param_1[0x10] | 0x8000;
    if (param_1[0x17] == 0) {
      iVar1 = FUN_00403088(param_1,param_2,param_3);
      iVar1 = (**(code **)(iVar1 + 0x14))(iVar1,1,param_1);
      param_1[0x17] = iVar1;
    }
    (**(code **)(*(int *)param_1[0x17] + 0xc))((int *)param_1[0x17],param_2);
    iVar1 = param_1[0x17];
    *(int **)(iVar1 + 0xc) = param_1;
    *(code **)(iVar1 + 8) = FUN_00441250;
    FUN_00403088(param_1,param_2,
                 CONCAT31((int3)((uint)extraout_ECX >> 8),(*(byte *)(param_2 + 0x20) & 1) != 0));
    FUN_00414858(param_2,(int)param_1,extraout_ECX_00);
  }
  return;
}

