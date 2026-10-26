/*
 * FUN_00471dec at 00471dec
 * undefined __register FUN_00471dec(undefined4 param_1, int param_2, int * param_3)
 * Address ranges: 00471dec-00471f26;00471f31-00471f4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471dec(undefined4 param_1,int param_2,int *param_3)

{
  char cVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int local_1c [3];
  uint *local_10;
  int *local_c;
  int *local_8;
  
  puStack_2c = &stack0xfffffffc;
  puStack_38 = &stack0xfffffffc;
  puStack_44 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = (uint *)0x0;
  local_1c[2] = 0;
  local_1c[1] = 0;
  local_1c[0] = 0;
  puStack_30 = &LAB_00471f71;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_3c = &LAB_00471f4f;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_48 = &LAB_00471f27;
  uStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_4c;
  FUN_00403b50(param_3);
  local_8 = FUN_004703b0((int *)&PTR_FUN_004701c4,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  local_c = FUN_00459f94((int *)&PTR_FUN_00459f34,'\x01',extraout_ECX);
  FUN_0045a19c((int)local_c);
  if (local_8 == (int *)0x0) goto LAB_00471f1d;
  FUN_00470558((int)local_8,1);
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x02') {
LAB_00471e9b:
    FUN_00470560((int)local_8,(uint *)local_c[3]);
  }
  else {
    cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
    if (cVar1 == '\x04') goto LAB_00471e9b;
    FUN_00470560((int)local_8,*(uint **)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0xc));
  }
  FUN_0045c4c8(0x37,local_1c + 2);
  FUN_00407f60(param_2 + 1,local_1c + 1);
  FUN_0045c4c8(0x4e,local_1c);
  FUN_00403e90((int *)&local_10,4);
  FUN_00470508((int)local_8,local_10);
  (**(code **)(*local_8 + 0xd8))();
  FUN_004705e8((int)local_8,param_3);
LAB_00471f1d:
  *in_FS_OFFSET = uStack_4c;
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_00471f56;
  puStack_3c = (undefined1 *)0x471f46;
  FUN_00402eac(local_8);
  puStack_3c = (undefined1 *)0x471f4e;
  FUN_00402eac(local_c);
  return;
}

