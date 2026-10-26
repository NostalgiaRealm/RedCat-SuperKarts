/*
 * FUN_00475c50 at 00475c50
 * undefined __register FUN_00475c50(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00475c50-00475cfc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475c50(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_FS_OFFSET;
  int iStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int iStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_18;
  undefined4 *local_14;
  int local_10;
  int *local_c;
  undefined4 uStack_8;
  
  puStack_20 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  uStack_8 = 0;
  local_c = (int *)0x0;
  local_10 = 0;
  local_14 = (undefined4 *)0x0;
  local_18 = 0;
  puStack_24 = &LAB_00475d1f;
  iStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_28;
  puStack_30 = &LAB_00475cfd;
  iStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_34;
  local_c = FUN_00459f94((int *)&PTR_FUN_00459f34,'\x01',0);
  FUN_00407f60(param_2,&local_18);
  FUN_00403e90(&local_10,3);
  iVar1 = local_10;
  FUN_00403e90((int *)&local_14,4);
  FUN_0045a3c8((int)local_c,local_14);
  uStack_8 = CONCAT13(*(undefined1 *)((int)local_c + 0x22),(undefined3)uStack_8);
  *in_FS_OFFSET = iVar1;
  if (local_c != (int *)0x0) {
    FUN_00402eac(local_c);
  }
  return;
}

