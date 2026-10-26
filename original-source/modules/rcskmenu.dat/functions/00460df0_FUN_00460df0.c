/*
 * FUN_00460df0 at 00460df0
 * undefined __register FUN_00460df0(uint * param_1, undefined4 * param_2, byte param_3)
 * Address ranges: 00460df0-00460eaa;00460eb5-00460eca;00460ed4-00460eee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460df0(uint *param_1,undefined4 *param_2,byte param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined4 local_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 *local_c;
  uint *local_8;
  
  puStack_24 = (undefined1 *)0x460e0a;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_24 = (undefined1 *)0x460e12;
  FUN_00403f84((int)local_c);
  puStack_28 = &LAB_00460eef;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_34 = &LAB_00460ecb;
  local_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_38;
  puStack_40 = &LAB_00460eab;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  puStack_3c = &stack0xfffffffc;
  puStack_30 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  piVar1 = FUN_00460a40((int *)&PTR_FUN_00460868,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  if (piVar1 != (int *)0x0) {
    FUN_00460cb8((int)piVar1,local_c);
    FUN_00460b88((int)piVar1,local_8);
    FUN_00460be8((int)piVar1,param_3,extraout_ECX);
    (**(code **)(*piVar1 + 0xd8))();
    *in_FS_OFFSET = uStack_44;
    puStack_3c = (undefined1 *)0x460e9f;
    FUN_004036a4();
    *in_FS_OFFSET = uStack_2c;
    puStack_24 = &LAB_00460ef6;
    puStack_28 = (undefined1 *)0x460eee;
    FUN_00403b74((int *)&local_c,2);
    return;
  }
  *in_FS_OFFSET = uStack_44;
  *in_FS_OFFSET = local_38;
  puStack_30 = &DAT_00460ed2;
  puStack_34 = (undefined1 *)0x460eca;
  FUN_0042ed64((int *)0x0);
  return;
}

