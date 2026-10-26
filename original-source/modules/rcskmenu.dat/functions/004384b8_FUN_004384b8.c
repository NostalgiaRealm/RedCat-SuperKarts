/*
 * FUN_004384b8 at 004384b8
 * undefined __register FUN_004384b8(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 004384b8-00438524
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004384b8(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  if (param_2 == 0) {
    FUN_00402eac((int *)param_1[0xe]);
    param_1[0xe] = 0;
  }
  else {
    if (param_1[0xe] == 0) {
      iVar1 = FUN_00403088(param_1,param_2,param_3);
      iVar1 = (**(code **)(iVar1 + 0x14))(iVar1,1,param_1);
      param_1[0xe] = iVar1;
    }
    (**(code **)(*(int *)param_1[0xe] + 0xc))((int *)param_1[0xe],param_2);
    iVar1 = param_1[0xe];
    *(int **)(iVar1 + 0xc) = param_1;
    *(undefined1 **)(iVar1 + 8) = &LAB_00438714;
    FUN_00403088(param_1,param_2,
                 CONCAT31((int3)((uint)extraout_ECX >> 8),(*(byte *)(param_2 + 0x20) & 1) != 0));
    FUN_00414858(param_2,(int)param_1,extraout_ECX_00);
  }
  return;
}

