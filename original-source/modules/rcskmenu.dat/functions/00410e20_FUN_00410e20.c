/*
 * FUN_00410e20 at 00410e20
 * undefined __register FUN_00410e20(int * param_1, int param_2, int param_3)
 * Address ranges: 00410e20-00410ea3;00410eab-00410ec0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410e20(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  int local_c;
  int *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_c = 0;
  puStack_20 = &LAB_00410ec1;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  local_8 = param_1;
  if (param_3 != param_2) {
    puStack_28 = (undefined1 *)0x410e4f;
    FUN_0041073c(param_1);
    puStack_2c = &LAB_00410ea4;
    uStack_30 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_30;
    puStack_28 = &stack0xfffffffc;
    (**(code **)(*local_8 + 0xc))(local_8,param_2,&local_c);
    uVar1 = (**(code **)(*local_8 + 0x18))(local_8,param_2);
    (**(code **)(*local_8 + 0x44))(local_8,param_2);
    FUN_00410cf0(local_8,param_3,local_c,uVar1);
    *in_FS_OFFSET = uStack_30;
    puStack_28 = (undefined1 *)0x410eab;
    puStack_2c = (undefined1 *)0x410ea3;
    FUN_004107f8(local_8);
    return;
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00410ec8;
  puStack_20 = (undefined1 *)0x410ec0;
  FUN_00403b50(&local_c);
  return;
}

