/*
 * FUN_00472fe0 at 00472fe0
 * undefined __register FUN_00472fe0(void)
 * Address ranges: 00472fe0-00473116
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472fe0(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  undefined3 extraout_var;
  undefined4 extraout_ECX;
  undefined4 unaff_EBX;
  uint uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  int local_18 [2];
  uint *local_10;
  undefined4 *local_c;
  int *local_8;
  
  puStack_24 = &stack0xfffffffc;
  puStack_30 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (uint *)0x0;
  local_18[1] = 0;
  local_18[0] = 0;
  puStack_28 = &LAB_00473139;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  iVar1 = *(int *)(*(int *)PTR_DAT_0047c670 + 0x80);
  uVar4 = CONCAT31((int3)((uint)unaff_EBX >> 8),*(undefined1 *)(iVar1 + 0x24));
  puStack_34 = &LAB_00473117;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  cVar2 = FUN_0045a9f4(iVar1,uVar4);
  if (cVar2 != '\0') {
    bVar3 = FUN_004581c0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),uVar4);
    FUN_004581b4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),CONCAT31(extraout_var,bVar3));
    local_8 = FUN_00460a40((int *)&PTR_FUN_00460868,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
    FUN_0045c4f0(0x15,(int *)&local_10);
    FUN_00460b88((int)local_8,local_10);
    FUN_00460be8((int)local_8,4,extraout_ECX);
    FUN_0045c4c8(0x38,local_18 + 1);
    FUN_0045c4c8(0x39,local_18);
    FUN_00403e90((int *)&local_c,5);
    FUN_00460cb8((int)local_8,local_c);
    FUN_0045c5cc(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),
                 (&DAT_0047c504)[bVar3 & 0x7f]);
    (**(code **)(*local_8 + 0xd8))();
  }
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0047311e;
  puStack_34 = (undefined1 *)0x473116;
  FUN_00402eac(local_8);
  return;
}

