/*
 * FUN_00410948 at 00410948
 * undefined FUN_00410948(void)
 * Address ranges: 00410948-004109fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410948(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int *piStack_8;
  
  puStack_24 = &stack0xfffffffc;
  uStack_14 = 0;
  uStack_10 = 0;
  puStack_28 = &LAB_00410a20;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_30 = (undefined1 *)0x410976;
  piStack_8 = param_1;
  FUN_0041073c(param_1);
  puStack_34 = &LAB_004109fe;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  (**(code **)(*piStack_8 + 0xc))(piStack_8,param_2,&uStack_10);
  uStack_c = (**(code **)(*piStack_8 + 0x18))(piStack_8,param_2);
  (**(code **)(*piStack_8 + 0xc))(piStack_8,param_3,&uStack_14);
  (**(code **)(*piStack_8 + 0x20))(piStack_8,param_2,uStack_14);
  uVar1 = (**(code **)(*piStack_8 + 0x18))(piStack_8,param_3);
  (**(code **)(*piStack_8 + 0x24))(piStack_8,param_2,uVar1);
  (**(code **)(*piStack_8 + 0x20))(piStack_8,param_3,uStack_10);
  (**(code **)(*piStack_8 + 0x24))(piStack_8,param_3,uStack_c);
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_00410a05;
  puStack_34 = (undefined1 *)0x4109fd;
  FUN_004107f8(piStack_8);
  return;
}

