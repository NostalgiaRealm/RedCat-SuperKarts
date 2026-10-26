/*
 * FUN_00460d08 at 00460d08
 * undefined __register FUN_00460d08(undefined4 * param_1)
 * Address ranges: 00460d08-00460d9e;00460da9-00460dbe;00460dc8-00460ddd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460d08(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 local_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_8;
  
  puStack_1c = (undefined1 *)0x460d1c;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_20 = &LAB_00460dde;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_2c = &LAB_00460dbf;
  local_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_30;
  puStack_38 = &LAB_00460d9f;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_34 = &stack0xfffffffc;
  puStack_28 = &stack0xfffffffc;
  puStack_1c = &stack0xfffffffc;
  piVar1 = FUN_00460a40((int *)&PTR_FUN_00460868,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  if (piVar1 != (int *)0x0) {
    FUN_00460cb8((int)piVar1,local_8);
    (**(code **)(*piVar1 + 0xd8))();
    *in_FS_OFFSET = uStack_3c;
    puStack_34 = (undefined1 *)0x460d93;
    FUN_004036a4();
    *in_FS_OFFSET = uStack_24;
    puStack_1c = &LAB_00460de5;
    puStack_20 = (undefined1 *)0x460ddd;
    FUN_00403b50((int *)&local_8);
    return;
  }
  *in_FS_OFFSET = uStack_3c;
  *in_FS_OFFSET = local_30;
  puStack_28 = &DAT_00460dc6;
  puStack_2c = (undefined1 *)0x460dbe;
  FUN_0042ed64((int *)0x0);
  return;
}

