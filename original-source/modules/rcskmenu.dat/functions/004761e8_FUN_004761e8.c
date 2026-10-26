/*
 * FUN_004761e8 at 004761e8
 * undefined __register FUN_004761e8(undefined4 param_1, undefined4 param_2, int * param_3)
 * Address ranges: 004761e8-00476283;0047628e-004762a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004761e8(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *local_c;
  int *local_8;
  
  puStack_1c = &stack0xfffffffc;
  puStack_28 = &stack0xfffffffc;
  puStack_34 = &stack0xfffffffc;
  local_c = (uint *)0x0;
  puStack_20 = &LAB_004762c1;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_2c = &LAB_004762a4;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_38 = &LAB_00476284;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  FUN_00403b50(param_3);
  local_8 = FUN_004703b0((int *)&PTR_FUN_004701c4,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  if (local_8 != (int *)0x0) {
    FUN_00470558((int)local_8,1);
    FUN_0045c4c8(0x35,(int *)&local_c);
    FUN_00470508((int)local_8,local_c);
    (**(code **)(*local_8 + 0xd8))();
    FUN_004705e8((int)local_8,param_3);
  }
  *in_FS_OFFSET = uStack_3c;
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_004762ab;
  puStack_2c = (undefined1 *)0x4762a3;
  FUN_0042ed64(local_8);
  return;
}

