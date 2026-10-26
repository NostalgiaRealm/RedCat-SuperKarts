/*
 * FUN_00410d74 at 00410d74
 * undefined __register FUN_00410d74(int * param_1, int * param_2)
 * Address ranges: 00410d74-00410df4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00410d74(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_c;
  int *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_c = 0;
  puStack_1c = &LAB_00410e12;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_24 = (undefined1 *)0x410d9c;
  local_8 = param_1;
  FUN_0041073c(param_1);
  puStack_28 = &LAB_00410df5;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_24 = &stack0xfffffffc;
  iVar1 = FUN_004118b0(param_2);
  iVar2 = FUN_00411894(param_2);
  FUN_00403c38(&local_c,(undefined4 *)0x0,iVar1 - iVar2);
  (**(code **)(*param_2 + 4))(param_2,local_c,iVar1 - iVar2);
  (**(code **)(*local_8 + 0x2c))(local_8,local_c);
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_00410dfc;
  puStack_28 = (undefined1 *)0x410df4;
  FUN_004107f8(local_8);
  return;
}

